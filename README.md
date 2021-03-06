# MEGA DRINKING MACHINA ADVENTURE
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/juthomas/Electronics_MDMA?style=for-the-badge)
![GitHub last commit](https://img.shields.io/github/last-commit/juthomas/Electronics_MDMA?style=for-the-badge)
![GitHub contributors](https://img.shields.io/github/contributors-anon/juthomas/Electronics_MDMA?style=for-the-badge)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/juthomas/Electronics_MDMA?style=for-the-badge)

<br/>

![alt text](https://github.com/juthomas/Electronics_MDMA/blob/master/Images/MDMA_Board.png)

__Sommaire__ :
* [Description](#description)
* [Installation](#installation-avr)
* [Usage](#usage)
* [Visual Studio Code Linter](#visual-studio-code-linter)
* [Project Functionalities](#project-functionalities)
  * [Leds Control](#leds-control)
  * [Prerequisites](#prerequisites)
  * [Leds Variables](#leds-variables)
  * [Color Attribution](#color-attribution)
  * [Usefull Functions](#usefull-functions)

<div id='description'/>

## Description

Cet objet à été conçu sur les bases d’un témoignage perturbant à la date du 27 juin 2007 sur le forum ████ par l’utilisateur Chri████4.
Il y fait mention d’un jeu à boire avec ses amis où ils auraient décidé d'invoquer Satan aux alentours de 23h42. La soirée aurait tourné en une cruelle mission de subjugation du malin avec pour seule arme l’alcool en grande quantité qu’ils avaient préparé pour faire la fête. Suite à cette affaire le service d’exorcisme V-696 (avec à sa tête Jean-███II) aurait procédé à une énorme commande de Sobieski. 

À travers le projet Mega Drinking Machina Adventure™ nous voulons faire vivre à nos très chers futurs utilisateurs une simulation familiale de cette aventure hors du commun. Une compilation de jeux à boire allant de 1 à 5 joueurs sera proposée, avec une mise en place intuitive et rapide. Sur batterie, lumineux et facile à transporter, il deviendra votre meilleur outil pour pimenter vos soirées peu importe le contexte.
<div id='installation-avr'/>

## Installation (AVR)

* Debian Based Linux :  
  * Install avr-gcc :  
  `sudo apt-get install gcc-avr binutils-avr avr-libc`
  * Install avr-dude :  
  `sudo apt-get install avrdude`
* Macos Unix :  
  * Install brew (for noobies) :  
  `rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && export PATH=$HOME/.brew/bin:$PATH && brew update && echo "export PATH=$HOME/.brew/bin:$PATH" >> ~/.zshrc`
  * Install avr-gcc :  
  `brew tap osx-cross/avr`  
  `brew install avr-gcc`
  * Install avr-dude :  
  `brew install avrdude`
<div id='usage'/>

## Usage

* Setup port :  
  `ls /dev/ > /tmp/file1`  
  then connect board  
  `ls /dev/ > /tmp/file2`  
  `diff /tmp/file1 /tmp/file2`  
  will give you the port  
  paste the given port to the `PORT` variable of the makefile

* Upload to board :  
  `make coffee` for build and upload  
  `make debug` for debuging  
  `make help` for other options
<div id='visual-studio-code-linter'/>

## Visual Studio Code Linter

* Install C/C++ extension  
* Configure C/C++ extension for avr :  
  Type `C/C++: Edit Configurations (JSON)` in Command Palette  
  * Linux :  
  Add `"/usr/lib/avr/include/**"` line to includePath  
  * Macos :  
  Add `"/Users/tmp/.brew/Cellar/avr-gcc@9/9.3.0_2/avr/include/**"`  
  on labelec macs  
  or  
  `/System/Volumes/Data/usr/local/Cellar/avr-gcc@9/9.3.0_2/avr/include/**`  
  (on real macs)  
  to includePath.  
  If this line doesnt work find "avr/io.h" file with `find / -name io.h`  
  Add the containing folder to includePath (like Linux method)

<div id='project-functionalities'/>

## Project Functionalities

<div id='leds-control'/>

### Leds Control

<div id='prerequisites'/>

#### Prerequisites
* `ft_pin_mode(led_pin, FT_OUTPUT);`

<div id='leds-variables'/>

#### Leds Variables
* char buffer (size = number of leds * 3)

<div id='color-attribution'/>

#### Color Attribution
  The color format is uint32_t : `0xLLRRGGBB`  
  LL : Luminosity (0x01 to 0xFF, or 0x00 to ignore)  
  RR : Red (0x00 to 0xFF)  
  GG : Green (0x00 to 0xFF)  
  BB : Blue (0x00 to 0xFF)  

<div id='usefull-functions'/>

#### Usefull Functions
* `uint8_t *feed_one_pixel(uint16_t pixel_index, uint8_t *pixels, uint32_t color)`  
  feed the selected pixel with the color
* `led_send_data(51, pixels, pixels_number);`  
  send data to the leds

