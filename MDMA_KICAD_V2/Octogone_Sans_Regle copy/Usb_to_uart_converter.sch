EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 21
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	2350 1700 1950 1700
Wire Wire Line
	2350 1600 1950 1600
Text HLabel 1950 1600 0    50   Input ~ 0
UD+
Text HLabel 1950 1700 0    50   Input ~ 0
UD-
$Comp
L power:GND #PWR0123
U 1 1 608FEF04
P 2750 2650
F 0 "#PWR0123" H 2750 2400 50  0001 C CNN
F 1 "GND" H 2755 2477 50  0000 C CNN
F 2 "" H 2750 2650 50  0001 C CNN
F 3 "" H 2750 2650 50  0001 C CNN
	1    2750 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0124
U 1 1 608FF65D
P 2250 1000
F 0 "#PWR0124" H 2250 750 50  0001 C CNN
F 1 "GND" V 2255 872 50  0000 R CNN
F 2 "" H 2250 1000 50  0001 C CNN
F 3 "" H 2250 1000 50  0001 C CNN
	1    2250 1000
	0    1    1    0   
$EndComp
$Comp
L Device:C C12
U 1 1 609012C1
P 2400 1000
F 0 "C12" V 2148 1000 50  0000 C CNN
F 1 "1000p" V 2239 1000 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2438 850 50  0001 C CNN
F 3 "~" H 2400 1000 50  0001 C CNN
	1    2400 1000
	0    1    1    0   
$EndComp
Wire Wire Line
	2550 1000 2650 1000
Wire Wire Line
	2650 1000 2650 1100
Text HLabel 4250 1400 2    50   Input ~ 0
TX
$Comp
L Device:R R60
U 1 1 6090C210
P 3700 1400
F 0 "R60" V 3493 1400 50  0000 C CNN
F 1 "4K7" V 3584 1400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3630 1400 50  0001 C CNN
F 3 "~" H 3700 1400 50  0001 C CNN
	1    3700 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	3150 1400 3550 1400
$Comp
L Device:R R59
U 1 1 60910A54
P 4300 1300
F 0 "R59" V 4093 1300 50  0000 C CNN
F 1 "4K7" V 4184 1300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4230 1300 50  0001 C CNN
F 3 "~" H 4300 1300 50  0001 C CNN
	1    4300 1300
	0    1    1    0   
$EndComp
Wire Wire Line
	3850 1400 4250 1400
Text HLabel 4850 1300 2    50   Output ~ 0
RX
$Comp
L power:GND #PWR056
U 1 1 6104968B
P 1050 1050
F 0 "#PWR056" H 1050 800 50  0001 C CNN
F 1 "GND" H 1055 877 50  0000 C CNN
F 2 "" H 1050 1050 50  0001 C CNN
F 3 "" H 1050 1050 50  0001 C CNN
	1    1050 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 6104E8A1
P 1050 900
F 0 "C9" H 1165 946 50  0000 L CNN
F 1 "0.1u" H 1165 855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1088 750 50  0001 C CNN
F 3 "~" H 1050 900 50  0001 C CNN
	1    1050 900 
	1    0    0    -1  
$EndComp
$Comp
L Interface_USB:CH340C U5
U 1 1 619900EE
P 2750 1700
F 0 "U5" H 2750 1011 50  0000 R TNN
F 1 "CH340C" H 2750 920 50  0000 R TNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 2800 1150 50  0001 L CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Jiangsu-Qin-Heng-CH340C_C84681.pdf" H 2400 2500 50  0001 C CNN
	1    2750 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 2300 2750 2650
Wire Wire Line
	3150 1300 4150 1300
Wire Wire Line
	4450 1300 4850 1300
NoConn ~ 3150 1600
NoConn ~ 3150 1700
NoConn ~ 3150 1800
NoConn ~ 3150 1900
Wire Wire Line
	3150 2000 3550 2000
Wire Wire Line
	3150 2100 3550 2100
Text Label 3550 2000 2    50   ~ 0
DTR
Text Label 3550 2100 2    50   ~ 0
RTS
NoConn ~ 3550 2100
Text HLabel 3550 2000 2    50   BiDi ~ 0
RESET
Text HLabel 2750 1050 1    50   Input ~ 0
VCC
Text HLabel 1050 750  1    50   Input ~ 0
VCC
Text HLabel 2350 1400 0    50   Input ~ 0
VCC
Wire Wire Line
	2750 1100 2750 1050
$EndSCHEMATC
