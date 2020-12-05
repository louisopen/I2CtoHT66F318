//___________________________________________________________________
//___________________________________________________________________
// Description: I2C Slave controller 
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: i2c.h
//Targer Board: MK8002D
//    MCU Body: HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#ifndef _I2C_H_
#define _I2C_H_

//PCF8574 P07~P00 => pa7~pa0  	(24pin/28pin) 
//PCF8575 P07~P00 add P17~P10 => pb6~pb2,pc2~pc0 	(24pin/28pin)
//HT66F318 LED64 (PCF8575 with pc4,pc3,pb1,pb0) 8x4ch+8x4ch	(24pin/28pin)

//PCF8574/PCF8575 slave address 0x20 ~ 0x27
#define DeviceAddr		0x27	//I2C Slave address for PCF8574/PCF8575
//#define DeviceAddr		0x33	//I2C Slave address for LED64 matrix

//#define DataCount		2		//I2C Received data count in PCF8574 P0 port
#define DataCount		2		//I2C Received data count in PCF8575 P0,P1 port
//#define DataCount		8		//I2C Received data count in HT66F318 for LED matrix


extern	u8	tx_iic_count, rx_iic_count;
extern	u8	tx_iic[8], rx_iic[8];
extern 	void	init_i2c(void), i2c_off(void), i2c_manage(void);

#endif