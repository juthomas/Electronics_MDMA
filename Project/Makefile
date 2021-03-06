FILENAME	= main
PORT		= /dev/tty.usbserial-1440 #tty.usbserial-14410
DEVICE		= atmega2560 #atmega328p #atmega2560 for atmega2560
PROGRAMMER	= arduino #wiring #arduino #wiring for atmega2560
BAUD		= 115200#57600 #115200 #can change for old bootloader (57600)
F_CPU		= 1600000 #12Mhz on uno   16 Mhz quartz #2 Mhz Cpu Clock (Quartz / 8)
COMPILE		= avr-gcc -Os -Wall -mmcu=$(DEVICE) -DF_CPU=${F_CPU}
COLOR		= \0033[1;35m

MUTE		= TRUE #FALSE to unmute


#LED MATRIX MODIFIERS, Make update to update
MATRIX_BRIGHTNESS		= 7		# 0-100
MATRIX_RED_MODIFIER		= 100	# 0-100
MATRIX_GREEN_MODIFIER	= 100	# 0-100
MATRIX_BLUE_MODIFIER	= 100	# 0-100

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

INC_H = leds math matrix_progmem mdma tone buttons millis encoders

#defines of directories names
BUTTONS_DIR = buttons
ILI9341_DIR = ili9341
SERIAL_DIR = serial
RFID_DIR = rfid
MOZART_DIR = mozart
TIME_DIR = time
LEDS_MANAGER_DIR = leds_manager
GAMES_DIR = Game
MATH_DIR = math

#defines of files in directories
# PIN_REGISTER_FT = pins_manipulation 
BUTTONS_FT = buttons encoders
ILI9341_FT = ili9341_init ili9341_SPI ili9341_text ili9341_draw ili9341_draw_utilities #graphicTest

LEDS_MANAGER_FT = low_level_led_addressing pixels_management
MOZART_FT = tone musique
MATH_FT = math
SERIAL_FT = serial_uart serial_nbr_base
RFID_FT = rfid
GAMES_FT = game
MATH_FT = math
TIME_FT = millis

SRC_FT = main

#defines of sources inputs (add lines if new srcs)
SRC =	$(SRC_FT:%=$(SRC_DIR)/%.c) \
		$(BUTTONS_FT:%=$(SRC_DIR)/$(BUTTONS_DIR)/%.c) \
		$(RFID_FT:%=$(SRC_DIR)/$(RFID_DIR)/%.c) \
		$(ILI9341_FT:%=$(SRC_DIR)/$(ILI9341_DIR)/%.c) \
		$(MOZART_FT:%=$(SRC_DIR)/$(MOZART_DIR)/%.c) \
		$(TIME_FT:%=$(SRC_DIR)/$(TIME_DIR)/%.c) \
		$(LEDS_MANAGER_FT:%=$(SRC_DIR)/$(LEDS_MANAGER_DIR)/%.c) \
		$(BOUTON_FT:%=$(SRC_DIR)/$(BOUTON_DIR)/%.c) \
		$(GAMES_FT:%=$(SRC_DIR)/$(GAMES_DIR)/%.c) \
		$(MATH_FT:%=$(SRC_DIR)/$(MATH_DIR)/%.c)

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

#defines of objects output locations (add lines if new srcs)
OBJ_DIRS =	$(BUTTONS_DIR:%=$(OBJ_DIR)/%) \
			$(RFID_DIR:%=$(OBJ_DIR)/%) \
			$(ILI9341_DIR:%=$(OBJ_DIR)/%) \
			$(MOZART_DIR:%=$(OBJ_DIR)/%) \
			$(TIME_DIR:%=$(OBJ_DIR)/%) \
			$(LEDS_MANAGER_DIR:%=$(OBJ_DIR)/%) \
			$(BOUTON_DIR:%=$(OBJ_DIR)/%)  \
			$(GAMES_DIR:%=$(OBJ_DIR)/%) \
			$(MATH_DIR:%=$(OBJ_DIR)/%)

INC = $(INC_DIR:%=-I ./%)

INCLUDES = $(INC_H:%=./$(INC_DIR)/%.h)

CC	= avr-gcc  -Wall -mmcu=$(DEVICE) -DF_CPU=${F_CPU} $(INC)


define auto_set_serial_port =
ls /dev > test1;
while [ true ] ; do
read -t 3 -n 1
if [ $? = 0 ] ; then
exit ;
else
echo "waiting for the keypress"
fi
done
ls /dev > test2;
diff test1 test2;
endef


all: hex flash

update: compile_matrix_items coffee

compile_matrix_items:
	@make -C ./res/compile_matrix_items
	@echo "$(COLOR)inc/matrix_progmem.h \033[100D\033[40C\0033[1;32m[Updated]\0033[1;37m"
	@./res/compile_matrix_items/compile_matrix_items $(MATRIX_BRIGHTNESS) \
	$(MATRIX_RED_MODIFIER) $(MATRIX_GREEN_MODIFIER) $(MATRIX_BLUE_MODIFIER) inc/matrix_progmem.h
	@make -C ./res/compile_matrix_items fclean

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

$(OBJ_DIRS):
	@mkdir -p $@



$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@$(CC) -c -Os -fno-fat-lto-objects -ffunction-sections -fdata-sections -flto $< -o $@

hex: $(FILENAME)

$(FILENAME): $(OBJ_DIRS) $(SRC) $(INCLUDES)
	@if [ $(MUTE) = FALSE ];then\
		$(MAKE) -j $(OBJ);\
	else\
		$(MAKE) -j -s $(OBJ);\
	fi

	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"

	@if [ $(MUTE) = FALSE ];then\
		$(COMPILE) -v -Os -flto -Wl,--gc-sections -fuse-linker-plugin -o $(FILENAME).bin $(OBJ);\
	else\
		$(COMPILE) -Os -flto -Wl,--gc-sections -fuse-linker-plugin -o $(FILENAME).bin $(OBJ);\
	fi

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
		avrdude -V -v -D -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i;\
	else\
		avrdude -V -D -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i -l /dev/null;\
	fi
	@echo "$(COLOR)Black Magic \033[100D\033[40C\0033[1;32m[I̶̢͇͎͉͙͒̉n̸̛͖̣͒̓͒̊͆̉͜v̶̰̉̀́̓͠ǒ̵̜̰̝̼̤͉k̴͎̠̪͙̐̈́̔͑̇e̶̖̰͘d̸̻͛͊̎̀͒̚]\0033[1;37m"
	@echo "$(COLOR)$(DEVICE) \033[100D\033[40C\0033[1;32m[Flashed]\0033[1;37m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR)Objects directory \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"
	@rm -f $(FILENAME).bin
	@echo "$(COLOR)Binaries \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"
	@rm -f $(FILENAME).hex
	@echo "$(COLOR)F̵̥̣͌o̸̘͍̐̓ŕ̸͙b̵̭͑i̶̢̼͒d̵͖̽̚d̶̙̋ē̴̠̤͛ṉ̴̜͘ ̶̪̾̆ķ̷̝̅͝ñ̴̯̚o̷͚͌w̶̼͠ḻ̴͒͝ḛ̵͙̈d̵̪̹̏͝ǵ̴͎̏e̶͔̦͆ \033[100D\033[40C\0033[1;31m[Exortized]\0033[1;37m"

unmute:
	$(eval MUTE=FALSE)

debug: unmute coffee

re: clean all

serial: coffee
	@echo "\0033[1;36mStarting Serial Monitor"
	@echo "To quit this windows"
	@echo "Press CTRL+A"
	@echo "Then type \":quit\""
	@echo "Starting Screen in 5\0033[1;37m"
	@sleep 1
	@echo "\033[1A\033[K\0033[1;36mStarting Screen in 4\0033[1;37m"
	@sleep 1
	@echo "\033[1A\033[K\0033[1;36mStarting Screen in 3\0033[1;37m"
	@sleep 1
	@echo "\033[1A\033[K\0033[1;36mStarting Screen in 2\0033[1;37m"
	@sleep 1
	@echo "\033[1A\033[K\0033[1;36mStarting Screen in 1\0033[1;37m"
	@sleep 1
	@screen $(PORT) 9600

monitor: coffee
	@screen $(PORT) 9600

help:
	@echo "$(COLOR)Options :\0033[1;37m"
	@echo "\033[100D\033[5C\0033[1;32mmake\033[100D\033[10C \033[100D\033[40C\0033[1;31mCreate hex file then flash it \0033[1;37m"
	@echo "\033[100D\033[5C\0033[1;32mmake\033[100D\033[10Chex\033[100D\033[40C\0033[1;31mCreate hex file\0033[1;37m"
	@echo "\033[100D\033[5C\0033[1;32mmake\033[100D\033[10Cflash\033[100D\033[40C\0033[1;31mFlash hex file\0033[1;37m"
	@echo "\033[100D\033[5C\0033[1;32mmake\033[100D\033[10Ccoffee\033[100D\033[40C\0033[1;31mCreate hex file, flash it then clean\0033[1;37m"
	@echo "\033[100D\033[5C\0033[1;32mmake\033[100D\033[10Cdebug\033[100D\033[40C\0033[1;31mSame as coffee but show verbose\0033[1;37m"

man: help

options: help

option: help

.PHONY: all coffee flash clean unmute debug help man options option
