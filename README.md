## ��I2C slave with HT66F318 applications
* Using the host I2C access GPIO port, EEPROM(64bytes), ADC(8ch 12bits), PWM output(10bit), Capture, OLED display...via HT66F318 I2C port(Slave address 0x27)<br>
* �M�קQ��PC or Raspberry Pi or Arduino �n��D���q�LI2C�U�F�q�T���O�H�s��HT66F318(Slave address 0x27)��GPIO port, EEPROM(64bytes), ADC(8ch 12bits), PWM output(10bit), Capture, OLED display...<br>
* �bMCU�귽�����άO���θ˸m�ʥF��, Host�Y�i�z�LI2C�ӱ���o�Ӹ˸m�ӧ�UART��print for debug.<br>

* Project Option: <br>
HIRC8M (hi speed internal RC); �i�ﶵ��:HXT(400K~16Mhz),HIRC8M,HIRC12M,HIRC16M<br>
LICR (Low speed internal RC for TB0/TB1); �i�ﶵ��:LXT(32.768Khz),LIRC(32Khz)<br>

* TB0,1 enable LIRC interrupt for 0.514sec, 0.514sec<br>

* TM0 enable HIRC8M interrupt for around 200us<br>

* I2C slave(address 0x27)

* HT-IDE3000 HT66F317/HT66F318 28ssop with HT-IDE3000 & e-Link & e-WriterPro<br>
���[HT66F318 Document](https://www.holtek.com.tw/search?key=ht66F318)<br>
����&����Development & Debug[IDE3000 & ICE](https://www.holtek.com.tw/web/guest/ice)<br>
�N�J��Progrmming & writer[HOPE3000 & e-WriterPro](https://www.holtek.com.tw/web/guest/programmer)<br>

### Relevant information
* HT-IDE3000 V8.02
![Image](HT-IDE3000_version.jpg)
* HOLTEK C Compiler V3/Assembly
![Image](ProjectCompiler.jpg)
* HT66F318 Config, used 8Mhz X'tal external, VDD/VDDA binding
![Image](ProjectOption1.jpg)
![Image](ProjectOption2.jpg)
![Image](ProjectOption3.jpg)
![Image](ProjectOption4.jpg)
* HT66F318 28ssop Schematic Diagram
![Image](CircuitDiagram.jpg)
![Image](MCUdiagram.jpg)


### How to test or used
Using PC or Raspberry Pi or Arduino Host software control I2C of MCU (Slave address 0x27)
* For Example: 
* I2C Formate: @27 44 55

### Other applications:
* 

