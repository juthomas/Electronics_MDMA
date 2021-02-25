#include "../../inc/mdma.h"

static const uint8_t PROGMEM initcmd[] = {
    0xEF, 3, 0x03, 0x80, 0x02,  //Undocumented but necessary
    ILI9341_CMD_POWER_CONTROL_B, 3, 0x00, 0xC1, 0x30,
    0xED, 4, 0x64, 0x03, 0x12, 0x81, //Undocumented but necessary
    ILI9341_CMD_DRIVER_TIMING_CONTROL_A, 3, 0x85, 0x00, 0x78,
    ILI9341_CMD_POWER_ON_SEQ_CONTROL, 5, 0x39, 0x2C, 0x00, 0x34, 0x02,
    ILI9341_CMD_PUMP_RATIO_CONTROL, 1, 0x20,                 // Pump Radio Control
    ILI9341_CMD_DRIVER_TIMING_CONTROL_B, 2, 0x00, 0x00,           // Driver timing control B
    ILI9341_CMD_POWER_CONTROL_1, 1, 0x23,       // Power control VRH[5:0]
    ILI9341_CMD_POWER_CONTROL_2, 1, 0x10,       // Power control SAP[2:0];BT[3:0]
    ILI9341_CMD_VCOM_CONTROL_1, 2, 0x3e, 0x28, // VCM control
    ILI9341_CMD_VCOM_CONTROL_2, 1, 0x86,       // VCM control2
    ILI9341_CMD_MEMORY_ACCESS_CONTROL, 1, 0x48,       // Memory Access Control
    ILI9341_CMD_VERT_SCROLL_START_ADDRESS, 1, 0x00,   // Vertical scroll zero
    ILI9341_CMD_COLMOD_PIXEL_FORMAT_SET, 1, 0x55,
    ILI9341_CMD_FRAME_RATE_CONTROL_NORMAL, 2, 0x00, 0x18,
    ILI9341_CMD_DISPLAY_FUNCTION_CONTROL, 3, 0x08, 0x82, 0x27,                    // Display Function Control
    ILI9341_CMD_ENABLE_3_GAMMA_CONTROL, 1, 0x00,                                           // 3Gamma Function Disable
    ILI9341_CMD_GAMMA_SET, 1, 0x01,                               // Gamma curve selected
    ILI9341_CMD_POSITIVE_GAMMA_CORRECTION, 15, 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00,
    ILI9341_CMD_NEGATIVE_GAMMA_CORRECTION, 15, 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F,
    ILI9341_CMD_SLEEP_OUT, 0x80, // Exit Sleep
    ILI9341_CMD_DISPLAY_ON, 0x80, // Display on
    0x00                  // End of list
};

void ili9341_setCursor(int16_t x, int16_t y)
{
    cursor_x = x;
    cursor_y = y;
}

void ili9341_setTextColor(uint16_t c) 
{ 
    textcolor = textbgcolor = c; 
}

void ili9341_setTextSize(uint8_t s) {
  textsize_x = (s > 0) ? s : 1;
  textsize_y = (s > 0) ? s : 1;
}

void spiWrite(uint8_t b)
{
    for (uint8_t bit = 0; bit < 8; bit++)
    {
        if (b & 0x80)
            ft_digital_write(TFT_MOSI,FT_HIGH);
        else
            ft_digital_write(TFT_MOSI,FT_LOW);
        ft_digital_write(TFT_CLK,FT_HIGH);
        b <<= 1;
        ft_digital_write(TFT_CLK,FT_LOW);
    }
}

void sendCommand(uint8_t commandByte, uint8_t *dataBytes, uint8_t numDataBytes)
{
    if (TFT_CS >= 0)
        ft_digital_write(TFT_CS,FT_LOW);

    ft_digital_write(TFT_DC,FT_LOW);
    spiWrite(commandByte);
    ft_digital_write(TFT_DC,FT_HIGH);
    for (int i = 0; i < numDataBytes; i++)
        spiWrite((*dataBytes)++);
    if (TFT_CS >= 0)
        ft_digital_write(TFT_CS,FT_HIGH);
}

void sendCommand_init(uint8_t commandByte, const uint8_t *dataBytes, uint8_t numDataBytes)
{
    if (TFT_CS >= 0)
        ft_digital_write(TFT_CS,FT_LOW);

    ft_digital_write(TFT_DC,FT_LOW);
    spiWrite(commandByte);
    ft_digital_write(TFT_DC,FT_HIGH);
    for (int i = 0; i < numDataBytes; i++)
        spiWrite(pgm_read_byte(dataBytes++));
    if (TFT_CS >= 0)
        ft_digital_write(TFT_CS,FT_HIGH);
}

void initSPI(uint32_t freq)
{
    if (TFT_CS >= 0)
    {
        ft_pin_mode(TFT_CS,FT_OUTPUT);
        ft_digital_write(TFT_CS,FT_HIGH);
    }
    ft_pin_mode(TFT_DC,FT_OUTPUT);
    ft_digital_write(TFT_DC,FT_HIGH);

    ft_pin_mode(TFT_MOSI, FT_OUTPUT);
    ft_digital_write(TFT_MOSI, FT_LOW);
    ft_pin_mode(TFT_CLK,FT_OUTPUT);
    ft_digital_write(TFT_CLK,FT_LOW);
    if (TFT_MISO >= 0)
    {
        ft_pin_mode(TFT_MISO,FT_INPUT);
    }
    if (TFT_RST >= 0)
    {
        ft_pin_mode(TFT_RST,FT_OUTPUT);
        ft_digital_write(TFT_RST,FT_HIGH);
        custom_delay(100);
        ft_digital_write(TFT_RST,FT_LOW);
        custom_delay(100);
        ft_digital_write(TFT_RST,FT_HIGH);
        custom_delay(200);
    }
}
void ili9341_setRotation(uint8_t m) {
 rotation = m % 4; // can't be higher than 3
  switch (rotation) {
  case 0:
    m = (MADCTL_MX | MADCTL_BGR);
    width = ILI9341_TFTWIDTH;
    height = ILI9341_TFTHEIGHT;
    break;
  case 1:
    m = (MADCTL_MV | MADCTL_BGR);
    width = ILI9341_TFTHEIGHT;
    height = ILI9341_TFTWIDTH;
    break;
  case 2:
    m = (MADCTL_MY | MADCTL_BGR);
    width = ILI9341_TFTWIDTH;
    height = ILI9341_TFTHEIGHT;
    break;
  case 3:
    m = (MADCTL_MX | MADCTL_MY | MADCTL_MV | MADCTL_BGR);
    width = ILI9341_TFTHEIGHT;
    height = ILI9341_TFTWIDTH;
    break;
  }
  serial_putnbr((int32_t)m);
  sendCommand(0x36, &m, 1);
}
void ili9341_begin()
{
    uint32_t freq = 1;
    wrap = 1;
    cp437 = 0;
    
    initSPI(freq);

    uint8_t cmd, x, numArgs;
    width = ILI9341_TFTWIDTH;
    height = ILI9341_TFTHEIGHT;
    portSPI = (volatile uint8_t*)g_pin_associations[TFT_MOSI].register_port_addr;
    portPINL = (volatile uint8_t*)g_pin_associations[TFT_DC].register_port_addr;
    const uint8_t *addr = initcmd;
    while ((cmd = pgm_read_byte(addr++)) > 0)
    {
        x = pgm_read_byte(addr++);
        numArgs = x & 0x7F;
        sendCommand_init(cmd, addr, numArgs);
        addr += numArgs;
        if (x & 0x80)
            custom_delay(150);
    }
}