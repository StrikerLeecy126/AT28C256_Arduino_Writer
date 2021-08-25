# AT28C256_Arduino_Writer

--
This is an Arduino project for automatically write data to AT28C256 EEPROM. Code written by StrikerLeecy126.
--
A PCB is designed to make connection easier.
--
Component used:
--
1 Arduino Nano
--
2 74HC164N 8-bit shift registers
--
1 AT28C256 EEPROM
--
EEPROM_Writer_PCB_LCEDA.json is the locally saved PCB file for LCEDA(EASYEDA).
--
EEPROM_Writer_Schematic.png is the schmatic of the project.
--
Other Gerber files are used to make PCB.
--
To use the writer, place all the components on the corresponding locations. Upload the arduino code and the data is written automatically.
--
Change value in Data_Num to change the quantity of data available.
--
Change the value in Address_Set to change the address value. 15-bits, from 0x0000 to 0x7fff
--
Change the value in IO_Set to change the data, 8-bits, from 0x00 to 0xff
--
DIP Sockets are adviced to be used on PCB in order to easily change all the components.
--
L1-L6 on PCB board are simply jumper Lines, or 0Ω resistors. (Confused with inductors, my bad).
--
