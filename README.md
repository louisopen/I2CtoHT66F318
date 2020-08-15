### I2C slave with HT66F318 applications

Using the host I2C access to HT66F318(Slave address 0x27) GPIO port, EEPROM(64bytes), 
ADC(8ch 12bits), PWM output(10bit), Capture, OLED display...
�M�קQ��PC or Raspberry Pi or Arduino �n��D���U�FI2C�q�T���O�H�s��HT66F318(Slave address 0x27)
GPIO port, EEPROM(64bytes), ADC(8ch 12bits), PWM output(10bit), Capture, OLED display...

�bMCU�귽�����άO���θ˸m�ʥF��, �Y�i�H�s�y�ۤv�����θ˸m, Host�Y�i�z�LI2C�ӱ���o�Ӹ˸m
��UART��debug print.

#### relevant information:

Tools: HT66F318 28ssop with HT-IDE3000 V8.02 & e-Link

Project Option: HIRC8M (hi speed internal RC);�i�ﶵHXT,HIRC8M,HIRC12M,HIRC16M,LXT,LIRC

* HT-IDE3000 V8.02
![Image](HT-IDE3000_version.jpg)
* HOLTEK C Compiler V3/Assembly
![Image](ProjectCompiler.jpg)
* HT66F318 Config, used 8Mhz X'tal external, VDD/VDDA binding
![Image](ProjectOption1.jpg)
![Image](ProjectOption2.jpg)
![Image](ProjectOption3.jpg)
![Image](ProjectOption4.jpg)
* HT66F318 28ssop Diagram
![Image](CircuitDiagram.jpg)


#### How to test or used:

Using PC or Raspberry Pi or Arduino Host software control I2C of MCU (Slave address 0x27)
* For Example: 
* I2C Formate: @27 44 55


#### Other applications:

* 

