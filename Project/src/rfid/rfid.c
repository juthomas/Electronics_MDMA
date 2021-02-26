#include "../../inc/mdma.h"

/**
 * Use the CRC coprocessor in the MFRC522 to calculate a CRC_A.
 
uint8_t PCD_CalculateCRC(uint8_t *data, uint8_t length, uint8_t *result)
{
  PCD_WriteRegister(CommandReg, PCD_Idle);      // Stop any active command.
  PCD_WriteRegister(DivIrqReg, 0x04);           // Clear the CRCIRq interrupt request bit
  PCD_SetRegisterBits(FIFOLevelReg, 0x80);      // FlushBuffer = 1, FIFO initialization
  PCD_WriteRegister(FIFODataReg, length, data); // Write data to the FIFO
  PCD_WriteRegister(CommandReg, PCD_CalcCRC);   // Start the calculation
 
  // Wait for the CRC calculation to complete. Each iteration of the while-loop takes 17.73us.
  uint16_t i = 5000;
  uint8_t n;
  while (1)
  {
    n = PCD_ReadRegister(DivIrqReg);  // DivIrqReg[7..0] bits are: Set2 reserved reserved MfinActIRq   reserved CRCIRq reserved reserved
    if (n & 0x04)
    {
      // CRCIRq bit set - calculation done
      break;
    }
    
    if (--i == 0)
    {
      // The emergency break. We will eventually terminate on this one after 89ms.
      // Communication with the MFRC522 might be down.
      return STATUS_TIMEOUT;
    }
  }
 
  // Stop calculating CRC for new content in the FIFO.
  PCD_WriteRegister(CommandReg, PCD_Idle);
 
  // Transfer the result from the registers to the result buffer
  result[0] = PCD_ReadRegister(CRCResultRegL);
  result[1] = PCD_ReadRegister(CRCResultRegH);
  return STATUS_OK;
} // End PCD_CalculateCRC()
*/

/*
 * Transmits SELECT/ANTICOLLISION commands to select a single PICC.
 */
uint8_t PICC_Select(t_uid *uid, uint8_t validBits)
{
  unsigned int uidComplete;
  unsigned int selectDone;
  unsigned int useCascadeTag;
  uint8_t cascadeLevel = 1;
  uint8_t result;
  uint8_t count;
  uint8_t index;
  uint8_t uidIndex;          // The first index in uid->uidByte[] that is used in the current Cascade Level.
  uint8_t currentLevelKnownBits;   // The number of known UID bits in the current Cascade Level.
  uint8_t buffer[9];         // The SELECT/ANTICOLLISION commands uses a 7 byte standard frame + 2 bytes CRC_A
  uint8_t bufferUsed;        // The number of bytes used in the buffer, ie the number of bytes to transfer to the FIFO.
  uint8_t rxAlign;           // Used in BitFramingReg. Defines the bit position for the first bit received.
  uint8_t txLastBits;        // Used in BitFramingReg. The number of valid bits in the last transmitted byte.
  uint8_t *responseBuffer;
  uint8_t responseLength;
 
  // Description of buffer structure:
  //    Byte 0: SEL         Indicates the Cascade Level: PICC_CMD_SEL_CL1, PICC_CMD_SEL_CL2 or PICC_CMD_SEL_CL3
  //    Byte 1: NVB         Number of Valid Bits (in complete command, not just the UID): High nibble: complete bytes, Low nibble: Extra bits.
  //    Byte 2: UID-data or CT    See explanation below. CT means Cascade Tag.
  //    Byte 3: UID-data
  //    Byte 4: UID-data
  //    Byte 5: UID-data
  //    Byte 6: BCC         Block Check Character - XOR of bytes 2-5
  //    Byte 7: CRC_A
  //    Byte 8: CRC_A
  // The BCC and CRC_A is only transmitted if we know all the UID bits of the current Cascade Level.
  //
  // Description of bytes 2-5: (Section 6.5.4 of the ISO/IEC 14443-3 draft: UID contents and cascade levels)
  //    UID size  Cascade level Byte2 Byte3 Byte4 Byte5
  //    ========  ============= ===== ===== ===== =====
  //     4 bytes    1     uid0  uid1  uid2  uid3
  //     7 bytes    1     CT    uid0  uid1  uid2
  //                2     uid3  uid4  uid5  uid6
  //    10 bytes    1     CT    uint8_t PICC_Select(t_uid *uid, uint8_t validBits)uid0  uid1  uid2
  //                2     CT    uid3  uid4  uid5
  //                3     uid6  uid7  uid8  uid9
 
  // Sanity checks
  /*if (validBits > 80)
  {
    return STATUS_INVALID;
  }*/
 
  // Prepare MFRC522
  // ValuesAfterColl=1 => Bits received after collision are cleared.
  PCD_ClrRegisterBits(CollReg, 0x80);
 
  // Repeat Cascade Level loop until we have a complete UID.
  uidComplete = 0;
  while ( ! uidComplete)
  {
    // Set the Cascade Level in the SEL byte, find out if we need to use the Cascade Tag in byte 2.
    if (cascadeLevel == 1)
    {
        buffer[0] = PICC_CMD_SEL_CL1;
        uidIndex = 0;
        useCascadeTag = validBits && (uid->size > 4); // When we know that the UID has more than 4 bytes
        break;
    }
 
    else if (cascadeLevel == 2)
    {
        buffer[0] = PICC_CMD_SEL_CL2;
        uidIndex = 3;
        useCascadeTag = validBits && (uid->size > 7); // When we know that the UID has more than 7 bytes
        break;
    }
    else if (cascadeLevel == 3)
    {
        buffer[0] = PICC_CMD_SEL_CL3;
        uidIndex = 6;
        useCascadeTag = 0;            // Never used in CL3.
        break;
    }

    else
      return STATUS_INTERNAL_ERROR;
        //break;
 
    // How many UID bits are known in this Cascade Level?
    if(validBits > (8 * uidIndex))
    {
      currentLevelKnownBits = validBits - (8 * uidIndex);
    }
    else
    {
      currentLevelKnownBits = 0;
    }
 
    // Copy the known bits from uid->uidByte[] to buffer[]
    index = 2; // destination index in buffer[]
    if (useCascadeTag)
    {
      buffer[index++] = PICC_CMD_CT;
    }
 
    uint8_t bytesToCopy = currentLevelKnownBits / 8 + (currentLevelKnownBits % 8 ? 1 : 0); // The number of bytes needed to represent the known bits for this level.
    if (bytesToCopy)
    {
      // Max 4 bytes in each Cascade Level. Only 3 left if we use the Cascade Tag
      uint8_t maxBytes = useCascadeTag ? 3 : 4;
      if (bytesToCopy > maxBytes)
      {
        bytesToCopy = maxBytes;
      }
 
      for (count = 0; count < bytesToCopy; count++)
      {
        buffer[index++] = uid->uidByte[uidIndex + count];
      }
    }
 
    // Now that the data has been copied we need to include the 8 bits in CT in currentLevelKnownBits
    if (useCascadeTag)
    {
      currentLevelKnownBits += 8;
    }
 
    // Repeat anti collision loop until we can transmit all UID bits + BCC and receive a SAK - max 32 iterations.
    selectDone = 0;
    while ( ! selectDone)
    {
      // Find out how many bits and bytes to send and receive.
      if (currentLevelKnownBits >= 32)
      { // All UID bits in this Cascade Level are known. This is a SELECT.
        //Serial.print("SELECT: currentLevelKnownBits="); Serial.println(currentLevelKnownBits, DEC);
        buffer[1] = 0x70; // NVB - Number of Valid Bits: Seven whole bytes
 
        // Calulate BCC - Block Check Character
        buffer[6] = buffer[2] ^ buffer[3] ^ buffer[4] ^ buffer[5];
 
        // Calculate CRC_A
      /*  result = PCD_CalculateCRC(buffer, 7, &buffer[7]);
        if (result != STATUS_OK)
        {
          return result;
        }
 */
        txLastBits      = 0; // 0 => All 8 bits are valid.
        bufferUsed      = 9;
 
        // Store response in the last 3 bytes of buffer (BCC and CRC_A - not needed after tx)
        responseBuffer  = &buffer[6];
        responseLength  = 3;
      }
      else
      { // This is an ANTICOLLISION.
        //Serial.print("ANTICOLLISION: currentLevelKnownBits="); Serial.println(currentLevelKnownBits, DEC);
        txLastBits     = currentLevelKnownBits % 8;
        count          = currentLevelKnownBits / 8;  // Number of whole bytes in the UID part.
        index          = 2 + count;                  // Number of whole bytes: SEL + NVB + UIDs
        buffer[1]      = (index << 4) + txLastBits;  // NVB - Number of Valid Bits
        bufferUsed     = index + (txLastBits ? 1 : 0);
 
        // Store response in the unused part of buffer
        responseBuffer = &buffer[index];
        responseLength = sizeof(buffer) - index;
      }
 
      // Set bit adjustments
      rxAlign = txLastBits;                     // Having a seperate variable is overkill. But it makes the next line easier to read.
      PCD_WriteRegister(BitFramingReg, (rxAlign << 4) + txLastBits);  // RxAlign = BitFramingReg[6..4]. TxLastBits = BitFramingReg[2..0]
 
      // Transmit the buffer and receive the response.
      result = PCD_TransceiveData(buffer, bufferUsed, responseBuffer, &responseLength, &txLastBits, rxAlign, 0);
      if (result == STATUS_COLLISION)
      { // More than one PICC in the field => collision.
        result = PCD_ReadRegister(CollReg);     // CollReg[7..0] bits are: ValuesAfterColl reserved CollPosNotValid CollPos[4:0]
        if (result & 0x20)
        { // CollPosNotValid
          return STATUS_COLLISION; // Without a valid collision position we cannot continue
        }
 
        uint8_t collisionPos = result & 0x1F; // Values 0-31, 0 means bit 32.
        if (collisionPos == 0)
        {
          collisionPos = 32;
        }
 
        if (collisionPos <= currentLevelKnownBits)
        { // No progress - should not happen
          return STATUS_INTERNAL_ERROR;
        }
 
        // Choose the PICC with the bit set.
        currentLevelKnownBits = collisionPos;
        count          = (currentLevelKnownBits - 1) % 8; // The bit to modify
        index          = 1 + (currentLevelKnownBits / 8) + (count ? 1 : 0); // First byte is index 0.
        buffer[index] |= (1 << count);
      }
      else if (result != STATUS_OK)
      {
        return result;
      }
      else
      { // STATUS_OK
        if (currentLevelKnownBits >= 32)
        { // This was a SELECT.
          selectDone = 1; // No more anticollision
          // We continue below outside the while.
        }
        else
        { // This was an ANTICOLLISION.
          // We now have all 32 bits of the UID in this Cascade Level
          currentLevelKnownBits = 32;
          // Run loop again to do the SELECT.
        }
      }
    } // End of while ( ! selectDone)
 
    // We do not check the CBB - it was constructed by us above.
 
    // Copy the found UID bytes from buffer[] to uid->uidByte[]
    index       = (buffer[2] == PICC_CMD_CT) ? 3 : 2; // source index in buffer[]
    bytesToCopy = (buffer[2] == PICC_CMD_CT) ? 3 : 4;
    for (count = 0; count < bytesToCopy; count++)
    {
      uid->uidByte[uidIndex + count] = buffer[index++];
    }
 
    // Check response SAK (Select Acknowledge)
    if (responseLength != 3 || txLastBits != 0)
    {   // SAK must be exactly 24 bits (1 byte + CRC_A).
      return STATUS_ERROR;
    }
 
    // Verify CRC_A - do our own calculation and store the control in buffer[2..3] - those bytes are not needed anymore.
    /*result = PCD_CalculateCRC(responseBuffer, 1, &buffer[2]);
    if (result != STATUS_OK)
    {
      return result;
    }
 
    if ((buffer[2] != responseBuffer[1]) || (buffer[3] != responseBuffer[2]))
    {
      return STATUS_CRC_WRONG;
    }
 */
    if (responseBuffer[0] & 0x04)
    { // Cascade bit set - UID not complete yes
      cascadeLevel++;
    }
    else
    {
      uidComplete = 1;
      uid->sak = responseBuffer[0];
    }
  } // End of while ( ! uidComplete)
 
  // Set correct uid->size
  uid->size = 3 * cascadeLevel + 1;
 
  return STATUS_OK;
} // End PICC_Select()
