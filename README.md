## ※Access GPIO of HT66F318 (via slave address 0x27) applications
* Using the host I2C access MCU internal resource GPIO, EEPROM(64bytes), ADC(8ch 12bits), PWM output(10bit), Capture, OLED display...<br>
專案利用PC or Raspberry Pi or Arduino 軟件主控通過I2C下達通訊指令以存取GPIO port, EEPROM(64bytes), ADC(8ch 12bits), PWM output(10bit), Capture, OLED display...<br>
* 在MCU資源不足或是應用裝置缺乏時, Host即可透過I2C來控制這個裝置而把UART port use for other<br>

* Project Option: <br>
HIRC12M (hi speed internal RC): 可選項有:HXT(400K~16Mhz),HIRC4M,HIRC8M,HIRC12M<br>
LICR (Low speed internal RC for TB0/TB1): 可選項有:LXT(32.768Khz),LIRC(32Khz)<br>
So no need any external OSC. or X'tal in this project.<br>
WatchDog: enable<br>

* TB0,1 enable LIRC interrupt for 16.05ms, 0.514sec<br>

* TM0 enable HIRC12M (hi speed internal RC) interrupt for around 200us<br>

* I2C slave(address 0x27)
SDA(PC5),SCL(PC6) Host(PC or Raspberry Pi)速度必須在100K/bps以下, 連續的read/write更可能要在50K/bps(HIRC8M) <br>
HT66F318 Internal RC HIRC8M/HIRC12M 兩種HIRC也有差別的 <br>
> I2C slave 收到host write資料後, 暫放置於準備傳輸的緩衝當中, 準備被I2C提取(host read)<br>
> 一次性長度(Read or Write), 最長為8bytes

* HT-IDE3000 HT66F317/HT66F318 28ssop with HT-IDE3000 & e-Link & e-WriterPro<br>
文件[HT66F318 Document](https://www.holtek.com.tw/search?key=ht66F318)<br>
模擬&除錯Development & Debug[IDE3000 & ICE](https://www.holtek.com.tw/web/guest/ice)<br>
燒入器Progrmming & writer[HOPE3000 & e-WriterPro](https://www.holtek.com.tw/web/guest/programmer)<br>

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

