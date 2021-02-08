FILENAME	= main
PORT		= /dev/ttyUSB0
DEVICE		= atmega2560
PROGRAMMER	= wiring
BAUD		= 115200
F_CPU		= 16000000 #16 Mhz quartz #2 Mhz Cpu Clock (Quartz / 8)
COMPILE		= avr-gcc -Wall -mmcu=$(DEVICE) -DF_CPU=${F_CPU}
COLOR		= \0033[1;35m

MUTE		= TRUE #FALSE to mute

all: hex flash

coffee: hex flash clean
	@echo ""
	@echo "                    {"
	@echo "                 {   }"
	@echo "                  }\0033[1;34m_\0033[1;37m{ \0033[1;34m__\0033[1;37m{"
	@echo "               \0033[1;34m.-\0033[1;37m{   }   }\0033[1;34m-."
	@echo "              \0033[1;34m(   \0033[1;37m}     {   \0033[1;34m)"
	@echo "              \0033[1;34m| -.._____..- |"
	@echo "              |             ;--."
	@echo "              |            (__  \ "
	@echo "              |             | )  )"
	@echo "              |   \0033[1;96mCOFFEE \0033[1;34m   |/  / "
	@echo "              |             /  / "
	@echo "              |            (  / "
	@echo "              \             | "
	@echo "                -.._____..- "
	@echo ""
	@echo ""
	@echo "\0033[1;32m\033[3C          Take Your Coffee"
	@echo "\0033[1;32m\033[3C      And Your Microcontroller"
	@echo "\0033[1;37m"

hex:
	@$(COMPILE) -c $(FILENAME).c -o $(FILENAME).o
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@$(COMPILE) -o $(FILENAME).bin $(FILENAME).o
	@echo "$(COLOR)Binary \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@avr-objcopy -j .text -j .data -O ihex $(FILENAME).bin $(FILENAME).hex
	@echo "         \033[1;91m            _̷̛̮_̶͉͌̾_̵̠̅͌_̸̰̑̄ͅ_̶̛͙̱̈_̵̦̩͌̈́             "
	@echo "                .̴̩́d̷͇̼͗̉#̸̤̲̏#̵̭͇̂#̸̥̾̿*̸̗͊*̸͎̣͛*̷͍̻͋͑*̸̻̍*̶̰͉̾̇*̸͙̩̀#̷͉͗̈#̶̞̉#̶̯̲͗̓#̵͖̼̌͊c̵̩͎̑͠.̴       "
	@echo "             .̴̳̔̊d̴̻͐͠ͅ#̸̢̓P̸̨͊̄͜             #̴͖̙͒#̶̧̓#̷̝͗c̵͙͛      "
	@echo "            #̵͙͛#̷̼̈́̓#̵̖̠̂̏#̴̝̈́#̶̬̆͛ͅ.̶͚̣́           .̴̩̇̉#̸̰͝#̴̟̅̍#̶̞̄*̷͙͊#̶̜͗̕.̶̫̅̀    "
	@echo "          .̶̝͉͐̕#̸̤̪͌#̵̼͆͒ 4̶̡͗#̸͚̖̌L̸̞̃̽*̶͇̮̈̓#̸̬̕#̷̣͙̉.̶̣̀ͅ     .̵̻̈́̑#̶̫͈̄#̸̘̍͠P̷̼̺̂̊d̵̡̗̍#̷̖͑͝   #̴̟͐̈b̵̢͓̅̇   "
	@echo "          #̸͚̗͆̕F̵̫̓̈   *̴̫͊̓#̵̳̟̑.̷̀̈́͜  #̵̧̳͛#̷̜͆e̴͔̚.̷͇̙̄ë̴̗́͊#̶̲͂#̴̗̮̐̀  4̴͚̊#̸͎̓F̵̺̼̊̆   ^̸̬̈̀#̷̣̱̏b̶͚̲̾  "
	@echo "         d̷̫͋͐#̸̥̐͝     #̴̝̠͒#̵̫̺̾̐   ż̷̫̕#̸̞̉̚#̶̽͜#̵͋ͅe̶̯̼͒̍   #̴̤̒#̷̧̪̓̒      #̵̧̩̕.̶̧̗̉͗ "
	@echo "         #̴͔̂͛ͅP̸̫̐̃      #̴̧̈́L̵̗̣͛̽#̸͕̘́͝#̷̨̣̏̑P̷̣̼̀    #̶̲̾͒#̸͇̺̔d̸͓̉͘#̷̤̺̚       #̸͓̍#̷̩͕͋ "
	@echo "         #̸͓̍#̷̩͕͋     ḙ̸̺̀̇#̷̛̙̒#̵̭͍̅̕F̵̥͇͘       4̸̝̭̂͠#̵̩̟͝#̶͍̫͌̚b̷̙́̅.̵̼͊     #̸̟̂̾#̸̨͊ "
	@echo "         #̷͎̃̚b̴̼͆̈́  .̶̖͒̉#̷̙̲̕͠#̷̙̀  #̶̡̻̆#̸͖̋ͅ      .̷̢͐#̵̦͛#̵̭́̈́  4̶͍̍̀#̶̤̘̔ḅ̵̱͌̉.̵̛̣̱͌  #̴̳͖̒̌#̵͔̇ "
	@echo "         #̶̪̀͠#̴̤͗è̴̮̽ͅ#̷̩̂̕Ṕ̸̜     #̵͉͔͒̃b̵̢̈́͊     d̸̦͋͛#̸̻̺̈́      #̸̨͛#̴̰̫̌c̶̯̣̓̈#̷̩͊̍F̸͇̾̚ "
	@echo "          #̵̟̔̏P̷̥̙̽̕#̴̺͎̊#̶̼̦̐̈́#̸̯͓͆#̴̫̠͒͠#̵̫̮̕#̴̤͐#̷̡͙̀#̶͚̞͋#̶̛̯͌ͅ#̴͕̪́̆#̸͎͌͝#̴͇̈́̂#̸͎͙̏̏#̸̢̿́#̴̤̓#̷̢͗́#̵̢̝̄͠#̶̲͐#̵̜̲̍#̷͙̲̈́#̵̻͎̽̈́#̸̳͋͠#̶̭͗#̵̡̔̍#̸̫̪̈̆#̶̃͜  "
	@echo "           #̷͕͎̌c̸͓̀.̵̦͆̍      4̴̳̰̓̕#̵͇̰̄.̷̤̟̿  #̵̡̛͐#̵̮̪̌̌       .̶̡͍͌͝#̶͚̂̚#̵̢̬͆͘   "
	@echo "           ^̴̰͕̓̊#̴̱̉#̸̗̭͘.̴̤̈́      #̸̨̛̠#̷̝̅̿ d̴̲͈͂̂#̷̡̘̈̚       d̶̞̰̾̓#̴̣̰̿P̶̡̲͛̽    "
	@echo "              #̵̺̐#̸̣͕̓͌c̴̫͙̀.̴̲̆    #̴̪͂͝b̴̤͒̾#̴̰̜̄̽F̴̯̄̀    .̴̪͑̚d̷̝̕#̷̭̣͐̔P̶͙̩̈́͑      "
	@echo "                4̴͚̌#̸̤̖̀͝#̷̩̔#̴̺̒c̷͖̝̾.̶̫̈̓#̷̣̲̊#̴̬̈́ͅ#̵̱̓̍ͅ.̵̛̜̺́.̵̡͝e̴̱̰͛#̶̫̒̆#̷̬͆Ṕ̸̮̋         "
	@echo "                    ^̵͓̘̃͠^̶̖̣̈̈^̴̠̀͊^̸̛̱́^̶̤̀^̸̪̗̐^̶̜̦͂̚             \0033[1;37m"
	@echo "$(COLOR)Satanic Circle \033[100D\033[40C\0033[1;32m[D̴̮̬͊̾r̶̟̫̿a̴̬̟͛̈́w̴̻̍̌ê̶̤̚d̴̛̟̺]\0033[1;37m"
	@if [ $(MUTE) = FALSE ];then\
		avr-size --format=avr --mcu=$(DEVICE) $(FILENAME).bin;\
	fi

flash:
	@if [ $(MUTE) = FALSE ];then\
		avrdude -v -D -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i;\
	else\
		avrdude -D -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i  -l /dev/null;\
	fi
	@echo "$(COLOR)Black Magic \033[100D\033[40C\0033[1;32m[I̶̢͇͎͉͙͒̉n̸̛͖̣͒̓͒̊͆̉͜v̶̰̉̀́̓͠ǒ̵̜̰̝̼̤͉k̴͎̠̪͙̐̈́̔͑̇e̶̖̰͘d̸̻͛͊̎̀͒̚]\0033[1;37m"
	@echo "$(COLOR)$(DEVICE) \033[100D\033[40C\0033[1;32m[Flashed]\0033[1;37m"

clean:
	@rm -f $(FILENAME).o
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"
	@rm -f $(FILENAME).bin
	@echo "$(COLOR)Binaries \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"
	@rm -f $(FILENAME).hex
	@echo "$(COLOR)F̵̥̣͌o̸̘͍̐̓ŕ̸͙b̵̭͑i̶̢̼͒d̵͖̽̚d̶̙̋ē̴̠̤͛ṉ̴̜͘ ̶̪̾̆ķ̷̝̅͝ñ̴̯̚o̷͚͌w̶̼͠ḻ̴͒͝ḛ̵͙̈d̵̪̹̏͝ǵ̴͎̏e̶͔̦͆ \033[100D\033[40C\0033[1;31m[Exortized]\0033[1;37m"