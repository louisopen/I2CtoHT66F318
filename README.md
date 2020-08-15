### I2C slave with HT66F318 applications

Using the host I2C access to HT66F318(Slave address 0x27) GPIO port, EEPROM(64bytes), 
ADC(8ch 12bits), PWM output(10bit), Capture, OLED display...
專案利用PC or Raspberry Pi or Arduino 軟件主控下達I2C通訊指令以存取HT66F318(Slave address 0x27)
GPIO port, EEPROM(64bytes), ADC(8ch 12bits), PWM output(10bit), Capture, OLED display...

在MCU資源不足或是應用裝置缺乏時, 即可以製造自己的應用裝置, Host即可透過I2C來控制這個裝置
把UART當成debug print.

#### relevant information:

Tools: HT66F318 28ssop with HT-IDE3000 V8.02 & e-Link

Project Option: HIRC8M (hi speed internal RC);可選項HXT,HIRC8M,HIRC12M,HIRC16M,LXT,LIRC

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

