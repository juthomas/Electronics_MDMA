EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 15 20
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4750 3850 0    50   BiDi ~ 0
CS
$Sheet
S 5000 3550 800  400 
U 605FFF79
F0 "level_shifter" 50
F1 "level_shifter.sch" 50
F2 "LV1" B L 5000 3700 50 
F3 "LV" I R 5800 3850 50 
F4 "HV" I R 5800 3700 50 
F5 "HV1" B L 5000 3850 50 
$EndSheet
$Comp
L power:+3.3V #PWR0111
U 1 1 614C05E1
P 4600 1800
AR Path="/6096BAB1/614C05E1" Ref="#PWR0111"  Part="1" 
AR Path="/6073AE75/614C05E1" Ref="#PWR0102"  Part="1" 
AR Path="/60968E40/614C05E1" Ref="#PWR0109"  Part="1" 
AR Path="/6096A2FC/614C05E1" Ref="#PWR0110"  Part="1" 
AR Path="/60967C0E/614C05E1" Ref="#PWR0112"  Part="1" 
F 0 "#PWR0109" H 4600 1650 50  0001 C CNN
F 1 "+3.3V" H 4550 2000 50  0000 C CNN
F 2 "" H 4600 1800 50  0001 C CNN
F 3 "" H 4600 1800 50  0001 C CNN
	1    4600 1800
	0    1    1    0   
$EndComp
Text HLabel 4400 3000 2    50   BiDi ~ 0
MISO
Text HLabel 4400 3100 2    50   BiDi ~ 0
MOSI
Text HLabel 4400 3200 2    50   BiDi ~ 0
CLK
Text HLabel 5050 2200 2    50   Output ~ 0
MAT_IN
Text HLabel 5500 2550 2    50   Output ~ 0
ENC_A
Text HLabel 5500 2650 2    50   Output ~ 0
ENC_B
Text HLabel 5500 2450 2    50   Output ~ 0
ENC_SW
Text HLabel 5500 2350 2    50   Output ~ 0
BUT_B
Text HLabel 5500 2250 2    50   Output ~ 0
BUT_A
$Comp
L Device:R R?
U 1 1 60621BD7
P 7100 2500
AR Path="/605FCE75/60621BD7" Ref="R?"  Part="1" 
AR Path="/60667947/60621BD7" Ref="R?"  Part="1" 
AR Path="/60667C6D/60621BD7" Ref="R?"  Part="1" 
AR Path="/60667CC3/60621BD7" Ref="R?"  Part="1" 
AR Path="/60667F0B/60621BD7" Ref="R?"  Part="1" 
AR Path="/60689793/60621BD7" Ref="R?"  Part="1" 
AR Path="/60689B07/60621BD7" Ref="R?"  Part="1" 
AR Path="/60689DBE/60621BD7" Ref="R?"  Part="1" 
AR Path="/6068A05A/60621BD7" Ref="R?"  Part="1" 
AR Path="/606A48A1/60621BD7" Ref="R?"  Part="1" 
AR Path="/606A8A05/60621BD7" Ref="R?"  Part="1" 
AR Path="/606A8A14/60621BD7" Ref="R?"  Part="1" 
AR Path="/606B05AD/60621BD7" Ref="R?"  Part="1" 
AR Path="/606B0C5B/60621BD7" Ref="R?"  Part="1" 
AR Path="/606B96E7/60621BD7" Ref="R?"  Part="1" 
AR Path="/606B9CFB/60621BD7" Ref="R?"  Part="1" 
AR Path="/60729DFC/60621BD7" Ref="R?"  Part="1" 
AR Path="/60729E0E/60621BD7" Ref="R?"  Part="1" 
AR Path="/6072E685/60621BD7" Ref="R?"  Part="1" 
AR Path="/6072E697/60621BD7" Ref="R?"  Part="1" 
AR Path="/607376FF/60621BD7" Ref="R?"  Part="1" 
AR Path="/60737711/60621BD7" Ref="R?"  Part="1" 
AR Path="/6073AE75/60621BD7" Ref="R4"  Part="1" 
AR Path="/607501CB/60621BD7" Ref="R?"  Part="1" 
AR Path="/60785CEB/60621BD7" Ref="R?"  Part="1" 
AR Path="/607ACD02/60621BD7" Ref="R?"  Part="1" 
AR Path="/60952AC6/60621BD7" Ref="R?"  Part="1" 
AR Path="/60956AE5/60621BD7" Ref="R?"  Part="1" 
AR Path="/60956AF4/60621BD7" Ref="R?"  Part="1" 
AR Path="/60965800/60621BD7" Ref="R?"  Part="1" 
AR Path="/60967C0E/60621BD7" Ref="R52"  Part="1" 
AR Path="/60968E40/60621BD7" Ref="R16"  Part="1" 
AR Path="/6096A2FC/60621BD7" Ref="R26"  Part="1" 
AR Path="/6096BAB1/60621BD7" Ref="R42"  Part="1" 
F 0 "R16" V 7150 2300 50  0000 L CNN
F 1 "10k" V 7100 2400 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7030 2500 50  0001 C CNN
F 3 "~" H 7100 2500 50  0001 C CNN
	1    7100 2500
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6063973E
P 7250 2500
AR Path="/605FCE75/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60667947/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60667C6D/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60667CC3/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60667F0B/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60689793/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60689B07/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60689DBE/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/6068A05A/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/606A48A1/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/606A8A05/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/606A8A14/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/606B05AD/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/606B0C5B/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/606B96E7/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/606B9CFB/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60729DFC/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60729E0E/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/6072E685/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/6072E697/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/607376FF/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60737711/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/6073AE75/6063973E" Ref="#PWR012"  Part="1" 
AR Path="/607501CB/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60785CEB/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/607ACD02/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60952AC6/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60956AE5/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60956AF4/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60965800/6063973E" Ref="#PWR?"  Part="1" 
AR Path="/60967C0E/6063973E" Ref="#PWR066"  Part="1" 
AR Path="/60968E40/6063973E" Ref="#PWR024"  Part="1" 
AR Path="/6096A2FC/6063973E" Ref="#PWR036"  Part="1" 
AR Path="/6096BAB1/6063973E" Ref="#PWR054"  Part="1" 
F 0 "#PWR024" H 7250 2250 50  0001 C CNN
F 1 "GND" H 7255 2327 50  0000 C CNN
F 2 "" H 7250 2500 50  0001 C CNN
F 3 "" H 7250 2500 50  0001 C CNN
	1    7250 2500
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 6061F683
P 7600 2600
AR Path="/605FCE75/6061F683" Ref="R?"  Part="1" 
AR Path="/60667947/6061F683" Ref="R?"  Part="1" 
AR Path="/60667C6D/6061F683" Ref="R?"  Part="1" 
AR Path="/60667CC3/6061F683" Ref="R?"  Part="1" 
AR Path="/60667F0B/6061F683" Ref="R?"  Part="1" 
AR Path="/60689793/6061F683" Ref="R?"  Part="1" 
AR Path="/60689B07/6061F683" Ref="R?"  Part="1" 
AR Path="/60689DBE/6061F683" Ref="R?"  Part="1" 
AR Path="/6068A05A/6061F683" Ref="R?"  Part="1" 
AR Path="/606A48A1/6061F683" Ref="R?"  Part="1" 
AR Path="/606A8A05/6061F683" Ref="R?"  Part="1" 
AR Path="/606A8A14/6061F683" Ref="R?"  Part="1" 
AR Path="/606B05AD/6061F683" Ref="R?"  Part="1" 
AR Path="/606B0C5B/6061F683" Ref="R?"  Part="1" 
AR Path="/606B96E7/6061F683" Ref="R?"  Part="1" 
AR Path="/606B9CFB/6061F683" Ref="R?"  Part="1" 
AR Path="/60729DFC/6061F683" Ref="R?"  Part="1" 
AR Path="/60729E0E/6061F683" Ref="R?"  Part="1" 
AR Path="/6072E685/6061F683" Ref="R?"  Part="1" 
AR Path="/6072E697/6061F683" Ref="R?"  Part="1" 
AR Path="/607376FF/6061F683" Ref="R?"  Part="1" 
AR Path="/60737711/6061F683" Ref="R?"  Part="1" 
AR Path="/6073AE75/6061F683" Ref="R2"  Part="1" 
AR Path="/607501CB/6061F683" Ref="R?"  Part="1" 
AR Path="/60785CEB/6061F683" Ref="R?"  Part="1" 
AR Path="/607ACD02/6061F683" Ref="R?"  Part="1" 
AR Path="/60952AC6/6061F683" Ref="R?"  Part="1" 
AR Path="/60956AE5/6061F683" Ref="R?"  Part="1" 
AR Path="/60956AF4/6061F683" Ref="R?"  Part="1" 
AR Path="/60965800/6061F683" Ref="R?"  Part="1" 
AR Path="/60967C0E/6061F683" Ref="R50"  Part="1" 
AR Path="/60968E40/6061F683" Ref="R14"  Part="1" 
AR Path="/6096A2FC/6061F683" Ref="R24"  Part="1" 
AR Path="/6096BAB1/6061F683" Ref="R40"  Part="1" 
F 0 "R14" V 7650 2400 50  0000 L CNN
F 1 "10k" V 7600 2500 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7530 2600 50  0001 C CNN
F 3 "~" H 7600 2600 50  0001 C CNN
	1    7600 2600
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60639A22
P 7800 2600
AR Path="/605FCE75/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60667947/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60667C6D/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60667CC3/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60667F0B/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60689793/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60689B07/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60689DBE/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/6068A05A/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/606A48A1/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/606A8A05/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/606A8A14/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/606B05AD/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/606B0C5B/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/606B96E7/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/606B9CFB/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60729DFC/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60729E0E/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/6072E685/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/6072E697/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/607376FF/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60737711/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/6073AE75/60639A22" Ref="#PWR010"  Part="1" 
AR Path="/607501CB/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60785CEB/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/607ACD02/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60952AC6/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60956AE5/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60956AF4/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60965800/60639A22" Ref="#PWR?"  Part="1" 
AR Path="/60967C0E/60639A22" Ref="#PWR064"  Part="1" 
AR Path="/60968E40/60639A22" Ref="#PWR022"  Part="1" 
AR Path="/6096A2FC/60639A22" Ref="#PWR034"  Part="1" 
AR Path="/6096BAB1/60639A22" Ref="#PWR052"  Part="1" 
F 0 "#PWR022" H 7800 2350 50  0001 C CNN
F 1 "GND" H 7805 2427 50  0000 C CNN
F 2 "" H 7800 2600 50  0001 C CNN
F 3 "" H 7800 2600 50  0001 C CNN
	1    7800 2600
	0    -1   -1   0   
$EndComp
$Sheet
S 7450 3200 800  400 
U 60634AF2
F0 "sheet60634ADD" 50
F1 "level_shifter.sch" 50
F2 "LV1" B L 7450 3350 50 
F3 "LV" I R 8250 3500 50 
F4 "HV" I R 8250 3350 50 
F5 "HV1" B L 7450 3500 50 
$EndSheet
$Comp
L Device:R R?
U 1 1 6062CE4E
P 6600 2400
AR Path="/605FCE75/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60667947/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60667C6D/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60667CC3/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60667F0B/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60689793/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60689B07/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60689DBE/6062CE4E" Ref="R?"  Part="1" 
AR Path="/6068A05A/6062CE4E" Ref="R?"  Part="1" 
AR Path="/606A48A1/6062CE4E" Ref="R?"  Part="1" 
AR Path="/606A8A05/6062CE4E" Ref="R?"  Part="1" 
AR Path="/606A8A14/6062CE4E" Ref="R?"  Part="1" 
AR Path="/606B05AD/6062CE4E" Ref="R?"  Part="1" 
AR Path="/606B0C5B/6062CE4E" Ref="R?"  Part="1" 
AR Path="/606B96E7/6062CE4E" Ref="R?"  Part="1" 
AR Path="/606B9CFB/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60729DFC/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60729E0E/6062CE4E" Ref="R?"  Part="1" 
AR Path="/6072E685/6062CE4E" Ref="R?"  Part="1" 
AR Path="/6072E697/6062CE4E" Ref="R?"  Part="1" 
AR Path="/607376FF/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60737711/6062CE4E" Ref="R?"  Part="1" 
AR Path="/6073AE75/6062CE4E" Ref="R5"  Part="1" 
AR Path="/607501CB/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60785CEB/6062CE4E" Ref="R?"  Part="1" 
AR Path="/607ACD02/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60952AC6/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60956AE5/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60956AF4/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60965800/6062CE4E" Ref="R?"  Part="1" 
AR Path="/60967C0E/6062CE4E" Ref="R53"  Part="1" 
AR Path="/60968E40/6062CE4E" Ref="R17"  Part="1" 
AR Path="/6096A2FC/6062CE4E" Ref="R27"  Part="1" 
AR Path="/6096BAB1/6062CE4E" Ref="R43"  Part="1" 
F 0 "R17" V 6650 2200 50  0000 L CNN
F 1 "10k" V 6600 2300 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6530 2400 50  0001 C CNN
F 3 "~" H 6600 2400 50  0001 C CNN
	1    6600 2400
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60638D16
P 6750 2400
AR Path="/605FCE75/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60667947/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60667C6D/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60667CC3/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60667F0B/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60689793/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60689B07/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60689DBE/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/6068A05A/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/606A48A1/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/606A8A05/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/606A8A14/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/606B05AD/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/606B0C5B/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/606B96E7/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/606B9CFB/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60729DFC/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60729E0E/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/6072E685/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/6072E697/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/607376FF/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60737711/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/6073AE75/60638D16" Ref="#PWR015"  Part="1" 
AR Path="/607501CB/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60785CEB/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/607ACD02/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60952AC6/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60956AE5/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60956AF4/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60965800/60638D16" Ref="#PWR?"  Part="1" 
AR Path="/60967C0E/60638D16" Ref="#PWR069"  Part="1" 
AR Path="/60968E40/60638D16" Ref="#PWR027"  Part="1" 
AR Path="/6096A2FC/60638D16" Ref="#PWR039"  Part="1" 
AR Path="/6096BAB1/60638D16" Ref="#PWR057"  Part="1" 
F 0 "#PWR027" H 6750 2150 50  0001 C CNN
F 1 "GND" H 6755 2227 50  0000 C CNN
F 2 "" H 6750 2400 50  0001 C CNN
F 3 "" H 6750 2400 50  0001 C CNN
	1    6750 2400
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60639ECC
P 8300 2700
AR Path="/605FCE75/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60667947/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60667C6D/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60667CC3/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60667F0B/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60689793/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60689B07/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60689DBE/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/6068A05A/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/606A48A1/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/606A8A05/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/606A8A14/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/606B05AD/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/606B0C5B/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/606B96E7/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/606B9CFB/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60729DFC/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60729E0E/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/6072E685/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/6072E697/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/607376FF/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60737711/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/6073AE75/60639ECC" Ref="#PWR09"  Part="1" 
AR Path="/607501CB/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60785CEB/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/607ACD02/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60952AC6/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60956AE5/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60956AF4/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60965800/60639ECC" Ref="#PWR?"  Part="1" 
AR Path="/60967C0E/60639ECC" Ref="#PWR063"  Part="1" 
AR Path="/60968E40/60639ECC" Ref="#PWR021"  Part="1" 
AR Path="/6096A2FC/60639ECC" Ref="#PWR033"  Part="1" 
AR Path="/6096BAB1/60639ECC" Ref="#PWR051"  Part="1" 
F 0 "#PWR021" H 8300 2450 50  0001 C CNN
F 1 "GND" H 8305 2527 50  0000 C CNN
F 2 "" H 8300 2700 50  0001 C CNN
F 3 "" H 8300 2700 50  0001 C CNN
	1    8300 2700
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 606391E0
P 6250 2300
AR Path="/605FCE75/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60667947/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60667C6D/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60667CC3/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60667F0B/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60689793/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60689B07/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60689DBE/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/6068A05A/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/606A48A1/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/606A8A05/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/606A8A14/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/606B05AD/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/606B0C5B/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/606B96E7/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/606B9CFB/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60729DFC/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60729E0E/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/6072E685/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/6072E697/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/607376FF/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60737711/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/6073AE75/606391E0" Ref="#PWR016"  Part="1" 
AR Path="/607501CB/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60785CEB/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/607ACD02/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60952AC6/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60956AE5/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60956AF4/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60965800/606391E0" Ref="#PWR?"  Part="1" 
AR Path="/60967C0E/606391E0" Ref="#PWR070"  Part="1" 
AR Path="/60968E40/606391E0" Ref="#PWR028"  Part="1" 
AR Path="/6096A2FC/606391E0" Ref="#PWR040"  Part="1" 
AR Path="/6096BAB1/606391E0" Ref="#PWR058"  Part="1" 
F 0 "#PWR028" H 6250 2050 50  0001 C CNN
F 1 "GND" H 6255 2127 50  0000 C CNN
F 2 "" H 6250 2300 50  0001 C CNN
F 3 "" H 6250 2300 50  0001 C CNN
	1    6250 2300
	0    -1   -1   0   
$EndComp
Text HLabel 6800 3500 0    50   BiDi ~ 0
RST
$Comp
L power:+3V3 #PWR?
U 1 1 60634AEC
P 8250 3500
AR Path="/605FCE75/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60667947/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60667C6D/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60667CC3/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60667F0B/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60689793/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60689B07/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60689DBE/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/6068A05A/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/606A48A1/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/606A8A05/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/606A8A14/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/606B05AD/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/606B0C5B/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/606B96E7/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/606B9CFB/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60729DFC/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60729E0E/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/6072E685/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/6072E697/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/607376FF/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60737711/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/6073AE75/60634AEC" Ref="#PWR07"  Part="1" 
AR Path="/607501CB/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60785CEB/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/607ACD02/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60952AC6/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60956AE5/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60956AF4/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60965800/60634AEC" Ref="#PWR?"  Part="1" 
AR Path="/60967C0E/60634AEC" Ref="#PWR061"  Part="1" 
AR Path="/60968E40/60634AEC" Ref="#PWR019"  Part="1" 
AR Path="/6096A2FC/60634AEC" Ref="#PWR031"  Part="1" 
AR Path="/6096BAB1/60634AEC" Ref="#PWR049"  Part="1" 
F 0 "#PWR019" H 8250 3350 50  0001 C CNN
F 1 "+3V3" H 8265 3673 50  0000 C CNN
F 2 "" H 8250 3500 50  0001 C CNN
F 3 "" H 8250 3500 50  0001 C CNN
	1    8250 3500
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 60634AE6
P 8250 3350
AR Path="/605FCE75/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60667947/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60667C6D/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60667CC3/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60667F0B/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60689793/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60689B07/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60689DBE/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/6068A05A/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/606A48A1/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/606A8A05/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/606A8A14/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/606B05AD/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/606B0C5B/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/606B96E7/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/606B9CFB/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60729DFC/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60729E0E/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/6072E685/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/6072E697/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/607376FF/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60737711/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/6073AE75/60634AE6" Ref="#PWR08"  Part="1" 
AR Path="/607501CB/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60785CEB/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/607ACD02/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60952AC6/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60956AE5/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60956AF4/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60965800/60634AE6" Ref="#PWR?"  Part="1" 
AR Path="/60967C0E/60634AE6" Ref="#PWR062"  Part="1" 
AR Path="/60968E40/60634AE6" Ref="#PWR020"  Part="1" 
AR Path="/6096A2FC/60634AE6" Ref="#PWR032"  Part="1" 
AR Path="/6096BAB1/60634AE6" Ref="#PWR050"  Part="1" 
F 0 "#PWR020" H 8250 3200 50  0001 C CNN
F 1 "+5V" H 8265 3523 50  0000 C CNN
F 2 "" H 8250 3350 50  0001 C CNN
F 3 "" H 8250 3350 50  0001 C CNN
	1    8250 3350
	0    1    1    0   
$EndComp
Text HLabel 4400 2000 2    50   Output ~ 0
LED_OUT
Text HLabel 4400 2100 2    50   Input ~ 0
LED_IN
$Comp
L Device:R R?
U 1 1 6062CE54
P 6100 2300
AR Path="/605FCE75/6062CE54" Ref="R?"  Part="1" 
AR Path="/60667947/6062CE54" Ref="R?"  Part="1" 
AR Path="/60667C6D/6062CE54" Ref="R?"  Part="1" 
AR Path="/60667CC3/6062CE54" Ref="R?"  Part="1" 
AR Path="/60667F0B/6062CE54" Ref="R?"  Part="1" 
AR Path="/60689793/6062CE54" Ref="R?"  Part="1" 
AR Path="/60689B07/6062CE54" Ref="R?"  Part="1" 
AR Path="/60689DBE/6062CE54" Ref="R?"  Part="1" 
AR Path="/6068A05A/6062CE54" Ref="R?"  Part="1" 
AR Path="/606A48A1/6062CE54" Ref="R?"  Part="1" 
AR Path="/606A8A05/6062CE54" Ref="R?"  Part="1" 
AR Path="/606A8A14/6062CE54" Ref="R?"  Part="1" 
AR Path="/606B05AD/6062CE54" Ref="R?"  Part="1" 
AR Path="/606B0C5B/6062CE54" Ref="R?"  Part="1" 
AR Path="/606B96E7/6062CE54" Ref="R?"  Part="1" 
AR Path="/606B9CFB/6062CE54" Ref="R?"  Part="1" 
AR Path="/60729DFC/6062CE54" Ref="R?"  Part="1" 
AR Path="/60729E0E/6062CE54" Ref="R?"  Part="1" 
AR Path="/6072E685/6062CE54" Ref="R?"  Part="1" 
AR Path="/6072E697/6062CE54" Ref="R?"  Part="1" 
AR Path="/607376FF/6062CE54" Ref="R?"  Part="1" 
AR Path="/60737711/6062CE54" Ref="R?"  Part="1" 
AR Path="/6073AE75/6062CE54" Ref="R6"  Part="1" 
AR Path="/607501CB/6062CE54" Ref="R?"  Part="1" 
AR Path="/60785CEB/6062CE54" Ref="R?"  Part="1" 
AR Path="/607ACD02/6062CE54" Ref="R?"  Part="1" 
AR Path="/60952AC6/6062CE54" Ref="R?"  Part="1" 
AR Path="/60956AE5/6062CE54" Ref="R?"  Part="1" 
AR Path="/60956AF4/6062CE54" Ref="R?"  Part="1" 
AR Path="/60965800/6062CE54" Ref="R?"  Part="1" 
AR Path="/60967C0E/6062CE54" Ref="R54"  Part="1" 
AR Path="/60968E40/6062CE54" Ref="R18"  Part="1" 
AR Path="/6096A2FC/6062CE54" Ref="R28"  Part="1" 
AR Path="/6096BAB1/6062CE54" Ref="R44"  Part="1" 
F 0 "R18" V 6150 2100 50  0000 L CNN
F 1 "10k" V 6100 2200 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6030 2300 50  0001 C CNN
F 3 "~" H 6100 2300 50  0001 C CNN
	1    6100 2300
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 6061A0B1
P 8150 2700
AR Path="/605FCE75/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60667947/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60667C6D/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60667CC3/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60667F0B/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60689793/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60689B07/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60689DBE/6061A0B1" Ref="R?"  Part="1" 
AR Path="/6068A05A/6061A0B1" Ref="R?"  Part="1" 
AR Path="/606A48A1/6061A0B1" Ref="R?"  Part="1" 
AR Path="/606A8A05/6061A0B1" Ref="R?"  Part="1" 
AR Path="/606A8A14/6061A0B1" Ref="R?"  Part="1" 
AR Path="/606B05AD/6061A0B1" Ref="R?"  Part="1" 
AR Path="/606B0C5B/6061A0B1" Ref="R?"  Part="1" 
AR Path="/606B96E7/6061A0B1" Ref="R?"  Part="1" 
AR Path="/606B9CFB/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60729DFC/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60729E0E/6061A0B1" Ref="R?"  Part="1" 
AR Path="/6072E685/6061A0B1" Ref="R?"  Part="1" 
AR Path="/6072E697/6061A0B1" Ref="R?"  Part="1" 
AR Path="/607376FF/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60737711/6061A0B1" Ref="R?"  Part="1" 
AR Path="/6073AE75/6061A0B1" Ref="R1"  Part="1" 
AR Path="/607501CB/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60785CEB/6061A0B1" Ref="R?"  Part="1" 
AR Path="/607ACD02/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60952AC6/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60956AE5/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60956AF4/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60965800/6061A0B1" Ref="R?"  Part="1" 
AR Path="/60967C0E/6061A0B1" Ref="R49"  Part="1" 
AR Path="/60968E40/6061A0B1" Ref="R13"  Part="1" 
AR Path="/6096A2FC/6061A0B1" Ref="R23"  Part="1" 
AR Path="/6096BAB1/6061A0B1" Ref="R39"  Part="1" 
F 0 "R13" V 8200 2500 50  0000 L CNN
F 1 "10k" V 8150 2600 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8080 2700 50  0001 C CNN
F 3 "~" H 8150 2700 50  0001 C CNN
	1    8150 2700
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 606183F1
P 4900 2200
AR Path="/605FCE75/606183F1" Ref="R?"  Part="1" 
AR Path="/60667947/606183F1" Ref="R?"  Part="1" 
AR Path="/60667C6D/606183F1" Ref="R?"  Part="1" 
AR Path="/60667CC3/606183F1" Ref="R?"  Part="1" 
AR Path="/60667F0B/606183F1" Ref="R?"  Part="1" 
AR Path="/60689793/606183F1" Ref="R?"  Part="1" 
AR Path="/60689B07/606183F1" Ref="R?"  Part="1" 
AR Path="/60689DBE/606183F1" Ref="R?"  Part="1" 
AR Path="/6068A05A/606183F1" Ref="R?"  Part="1" 
AR Path="/606A48A1/606183F1" Ref="R?"  Part="1" 
AR Path="/606A8A05/606183F1" Ref="R?"  Part="1" 
AR Path="/606A8A14/606183F1" Ref="R?"  Part="1" 
AR Path="/606B05AD/606183F1" Ref="R?"  Part="1" 
AR Path="/606B0C5B/606183F1" Ref="R?"  Part="1" 
AR Path="/606B96E7/606183F1" Ref="R?"  Part="1" 
AR Path="/606B9CFB/606183F1" Ref="R?"  Part="1" 
AR Path="/60729DFC/606183F1" Ref="R?"  Part="1" 
AR Path="/60729E0E/606183F1" Ref="R?"  Part="1" 
AR Path="/6072E685/606183F1" Ref="R?"  Part="1" 
AR Path="/6072E697/606183F1" Ref="R?"  Part="1" 
AR Path="/607376FF/606183F1" Ref="R?"  Part="1" 
AR Path="/60737711/606183F1" Ref="R?"  Part="1" 
AR Path="/6073AE75/606183F1" Ref="R3"  Part="1" 
AR Path="/607501CB/606183F1" Ref="R?"  Part="1" 
AR Path="/60785CEB/606183F1" Ref="R?"  Part="1" 
AR Path="/607ACD02/606183F1" Ref="R?"  Part="1" 
AR Path="/60952AC6/606183F1" Ref="R?"  Part="1" 
AR Path="/60956AE5/606183F1" Ref="R?"  Part="1" 
AR Path="/60956AF4/606183F1" Ref="R?"  Part="1" 
AR Path="/60965800/606183F1" Ref="R?"  Part="1" 
AR Path="/60967C0E/606183F1" Ref="R51"  Part="1" 
AR Path="/60968E40/606183F1" Ref="R15"  Part="1" 
AR Path="/6096A2FC/606183F1" Ref="R25"  Part="1" 
AR Path="/6096BAB1/606183F1" Ref="R41"  Part="1" 
F 0 "R15" V 4900 2150 50  0000 L CNN
F 1 "300_Ohm" V 5000 1800 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4830 2200 50  0001 C CNN
F 3 "~" H 4900 2200 50  0001 C CNN
	1    4900 2200
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 606102FA
P 5800 3850
AR Path="/605FCE75/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60667947/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60667C6D/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60667CC3/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60667F0B/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60689793/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60689B07/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60689DBE/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/6068A05A/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/606A48A1/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/606A8A05/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/606A8A14/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/606B05AD/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/606B0C5B/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/606B96E7/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/606B9CFB/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60729DFC/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60729E0E/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/6072E685/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/6072E697/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/607376FF/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60737711/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/6073AE75/606102FA" Ref="#PWR05"  Part="1" 
AR Path="/607501CB/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60785CEB/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/607ACD02/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60952AC6/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60956AE5/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60956AF4/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60965800/606102FA" Ref="#PWR?"  Part="1" 
AR Path="/60967C0E/606102FA" Ref="#PWR059"  Part="1" 
AR Path="/60968E40/606102FA" Ref="#PWR017"  Part="1" 
AR Path="/6096A2FC/606102FA" Ref="#PWR029"  Part="1" 
AR Path="/6096BAB1/606102FA" Ref="#PWR047"  Part="1" 
F 0 "#PWR017" H 5800 3700 50  0001 C CNN
F 1 "+3V3" H 5815 4023 50  0000 C CNN
F 2 "" H 5800 3850 50  0001 C CNN
F 3 "" H 5800 3850 50  0001 C CNN
	1    5800 3850
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 6060FB09
P 5800 3700
AR Path="/605FCE75/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60667947/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60667C6D/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60667CC3/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60667F0B/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60689793/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60689B07/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60689DBE/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/6068A05A/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/606A48A1/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/606A8A05/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/606A8A14/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/606B05AD/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/606B0C5B/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/606B96E7/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/606B9CFB/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60729DFC/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60729E0E/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/6072E685/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/6072E697/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/607376FF/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60737711/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/6073AE75/6060FB09" Ref="#PWR06"  Part="1" 
AR Path="/607501CB/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60785CEB/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/607ACD02/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60952AC6/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60956AE5/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60956AF4/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60965800/6060FB09" Ref="#PWR?"  Part="1" 
AR Path="/60967C0E/6060FB09" Ref="#PWR060"  Part="1" 
AR Path="/60968E40/6060FB09" Ref="#PWR018"  Part="1" 
AR Path="/6096A2FC/6060FB09" Ref="#PWR030"  Part="1" 
AR Path="/6096BAB1/6060FB09" Ref="#PWR048"  Part="1" 
F 0 "#PWR018" H 5800 3550 50  0001 C CNN
F 1 "+5V" H 5815 3873 50  0000 C CNN
F 2 "" H 5800 3700 50  0001 C CNN
F 3 "" H 5800 3700 50  0001 C CNN
	1    5800 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 3700 5000 3700
Wire Wire Line
	4750 3850 5000 3850
Wire Wire Line
	4500 3300 4500 3700
Wire Wire Line
	4800 2800 4800 3350
Wire Wire Line
	4800 3350 7450 3350
Wire Wire Line
	5450 2600 5450 2550
Wire Wire Line
	5450 2550 5500 2550
Wire Wire Line
	5450 2700 5450 2650
Wire Wire Line
	5450 2650 5500 2650
Wire Wire Line
	5450 2500 5450 2450
Wire Wire Line
	5450 2450 5500 2450
Wire Wire Line
	5450 2400 5450 2350
Wire Wire Line
	5450 2350 5500 2350
Connection ~ 5450 2400
Wire Wire Line
	5450 2400 6450 2400
Connection ~ 5450 2500
Wire Wire Line
	5450 2500 6950 2500
Connection ~ 5450 2700
Wire Wire Line
	5450 2700 8000 2700
Wire Wire Line
	4400 2500 5450 2500
Wire Wire Line
	4400 2400 5450 2400
Wire Wire Line
	4400 2300 5450 2300
Wire Wire Line
	4400 2200 4750 2200
Wire Wire Line
	4400 1800 4600 1800
Wire Wire Line
	4400 3300 4500 3300
NoConn ~ 4400 2900
Wire Wire Line
	4800 2800 4400 2800
Wire Wire Line
	4400 2700 5450 2700
Wire Wire Line
	4400 2600 5450 2600
$Comp
L power:+5V #PWR0107
U 1 1 614BF91F
P 4400 1700
AR Path="/6096BAB1/614BF91F" Ref="#PWR0107"  Part="1" 
AR Path="/6073AE75/614BF91F" Ref="#PWR0104"  Part="1" 
AR Path="/60968E40/614BF91F" Ref="#PWR0105"  Part="1" 
AR Path="/6096A2FC/614BF91F" Ref="#PWR0106"  Part="1" 
AR Path="/60967C0E/614BF91F" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0105" H 4400 1550 50  0001 C CNN
F 1 "+5V" H 4300 1800 50  0000 C CNN
F 2 "" H 4400 1700 50  0001 C CNN
F 3 "" H 4400 1700 50  0001 C CNN
	1    4400 1700
	0    1    1    0   
$EndComp
$Comp
L my_lib:Switch_Pin_out P?
U 1 1 605FDC32
P 3850 2450
AR Path="/605FCE75/605FDC32" Ref="P?"  Part="1" 
AR Path="/60667947/605FDC32" Ref="P?"  Part="1" 
AR Path="/60667C6D/605FDC32" Ref="P?"  Part="1" 
AR Path="/60667CC3/605FDC32" Ref="P?"  Part="1" 
AR Path="/60667F0B/605FDC32" Ref="P?"  Part="1" 
AR Path="/60689793/605FDC32" Ref="P?"  Part="1" 
AR Path="/60689B07/605FDC32" Ref="P?"  Part="1" 
AR Path="/60689DBE/605FDC32" Ref="P?"  Part="1" 
AR Path="/6068A05A/605FDC32" Ref="P?"  Part="1" 
AR Path="/606A48A1/605FDC32" Ref="P?"  Part="1" 
AR Path="/606A8A05/605FDC32" Ref="P?"  Part="1" 
AR Path="/606A8A14/605FDC32" Ref="P?"  Part="1" 
AR Path="/606B05AD/605FDC32" Ref="P?"  Part="1" 
AR Path="/606B0C5B/605FDC32" Ref="P?"  Part="1" 
AR Path="/606B96E7/605FDC32" Ref="P?"  Part="1" 
AR Path="/606B9CFB/605FDC32" Ref="P?"  Part="1" 
AR Path="/60729DFC/605FDC32" Ref="P?"  Part="1" 
AR Path="/60729E0E/605FDC32" Ref="P?"  Part="1" 
AR Path="/6072E685/605FDC32" Ref="P?"  Part="1" 
AR Path="/6072E697/605FDC32" Ref="P?"  Part="1" 
AR Path="/607376FF/605FDC32" Ref="P?"  Part="1" 
AR Path="/60737711/605FDC32" Ref="P?"  Part="1" 
AR Path="/6073AE75/605FDC32" Ref="P1"  Part="1" 
AR Path="/607501CB/605FDC32" Ref="P?"  Part="1" 
AR Path="/60785CEB/605FDC32" Ref="P?"  Part="1" 
AR Path="/607ACD02/605FDC32" Ref="P?"  Part="1" 
AR Path="/60952AC6/605FDC32" Ref="P?"  Part="1" 
AR Path="/60956AE5/605FDC32" Ref="P?"  Part="1" 
AR Path="/60956AF4/605FDC32" Ref="P?"  Part="1" 
AR Path="/60965800/605FDC32" Ref="P?"  Part="1" 
AR Path="/60967C0E/605FDC32" Ref="P5"  Part="1" 
AR Path="/60968E40/605FDC32" Ref="P2"  Part="1" 
AR Path="/6096A2FC/605FDC32" Ref="P3"  Part="1" 
AR Path="/6096BAB1/605FDC32" Ref="P4"  Part="1" 
F 0 "P2" V 4800 2300 50  0000 L CNN
F 1 "Switch_Pin_out" V 4728 2197 50  0000 L CNN
F 2 "my_lib:Pizza_Pin_Out" H 4000 2450 50  0001 C CNN
F 3 "" H 4000 2450 50  0001 C CNN
	1    3850 2450
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6062FC3A
P 4950 1900
AR Path="/605FCE75/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60667947/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60667C6D/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60667CC3/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60667F0B/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60689793/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60689B07/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60689DBE/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/6068A05A/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/606A48A1/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/606A8A05/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/606A8A14/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/606B05AD/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/606B0C5B/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/606B96E7/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/606B9CFB/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60729DFC/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60729E0E/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/6072E685/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/6072E697/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/607376FF/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60737711/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/6073AE75/6062FC3A" Ref="#PWR011"  Part="1" 
AR Path="/607501CB/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60785CEB/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/607ACD02/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60952AC6/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60956AE5/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60956AF4/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60965800/6062FC3A" Ref="#PWR?"  Part="1" 
AR Path="/60967C0E/6062FC3A" Ref="#PWR065"  Part="1" 
AR Path="/60968E40/6062FC3A" Ref="#PWR023"  Part="1" 
AR Path="/6096A2FC/6062FC3A" Ref="#PWR035"  Part="1" 
AR Path="/6096BAB1/6062FC3A" Ref="#PWR053"  Part="1" 
F 0 "#PWR023" H 4950 1650 50  0001 C CNN
F 1 "GND" H 4955 1727 50  0000 C CNN
F 2 "" H 4950 1900 50  0001 C CNN
F 3 "" H 4950 1900 50  0001 C CNN
	1    4950 1900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 1900 4950 1900
Wire Wire Line
	6800 3500 7450 3500
Wire Wire Line
	5450 2600 7450 2600
Connection ~ 5450 2600
Wire Wire Line
	7750 2600 7800 2600
Wire Wire Line
	5500 2250 5450 2250
Wire Wire Line
	5450 2250 5450 2300
Connection ~ 5450 2300
Wire Wire Line
	5450 2300 5950 2300
$EndSCHEMATC
