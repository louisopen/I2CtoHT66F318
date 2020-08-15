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
        
#define DeviceAddr		0x27	//I2C Slave address 0x20~0x27 like PCF8574

extern	u8	tx_iic_count, rx_iic_count;
extern	u8	tx_iic[8], rx_iic[8];
extern 	void	init_i2c(void), i2c_off(void), i2c_manage(void);

#endif