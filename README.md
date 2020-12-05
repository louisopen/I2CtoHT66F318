## ��Access GPIO of HT66F318 (via slave address 0x27) applications
* Using the host I2C access MCU internal resource GPIO, EEPROM(64bytes), ADC(8ch 12bits), PWM output(10bit), Capture, OLED display...<br>
�M�קQ��PC or Raspberry Pi or Arduino �n��D���q�LI2C�U�F�q�T���O�H�s��GPIO port, EEPROM(64bytes), ADC(8ch 12bits), PWM output(10bit), Capture, OLED display...<br>
* �bMCU�귽�����άO���θ˸m�ʥF��, Host�Y�i�z�LI2C�ӱ���o�Ӹ˸m�ӧ�UART port use for other<br>

* Project Option: <br>
HIRC12M (hi speed internal RC): �i�ﶵ��:HXT(400K~16Mhz),HIRC4M,HIRC8M,HIRC12M<br>
LICR (Low speed internal RC for TB0/TB1): �i�ﶵ��:LXT(32.768Khz),LIRC(32Khz)<br>
So no need any external OSC. or X'tal in this project.<br>
WatchDog: enable<br>

* TB0,1 enable LIRC interrupt for 16.05ms, 0.514sec<br>

* TM0 enable HIRC12M (hi speed internal RC) interrupt for around 200us<br>

* I2C slave(address 0x27)
SDA(PC5),SCL(PC6) Host(PC or Raspberry Pi)�t�ץ����b100K/bps�H�U, �s��read/write��i��n�b50K/bps(HIRC8M) <br>
HT66F318 Internal RC HIRC8M/HIRC12M ���HIRC�]���t�O�� <br>
> I2C slave ����host write��ƫ�, �ȩ�m��ǳƶǿ骺�w�ķ�, �ǳƳQI2C����(host read)<br>
> �@���ʪ���(Read or Write), �̪���8bytes

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
* I2C slave read: @27 Port0 Port1 
* I2C slave write: @27 Port0 Port1

