//___________________________________________________________________
//___________________________________________________________________
// Description: I2C Slave Controller with Host
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//  File Name : i2c.c
//Targer Board: MK8002D
//    MCU Body: HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"

u8	tx_iic_count, rx_iic_count;
u8	tx_iic[8], rx_iic[8];
void init_i2c(void), i2c_off(void), i2c_manage(void);
//___________________________________________________________________
//Function: Init i2C and I2C off
//   INPUT: 
//  OUTPUT: 
//	  NOTE:   
//___________________________________________________________________
void init_i2c(void)					//initial I2C
{
	_pcpu5 = 1;			//set pull-high for SDA
	_pcpu6 = 1;			//set pull-high for SDC
	_pcc5 = 1;
	_pcc6 = 1;

	//_i2cdbnc0 =1;		//debounce 2clock	
	_i2cdbnc1 =1;		//debounce 4clock
	
	_i2ctoc = 0x00;		//I2C Time out reg. disable
	
	_iicen = 1;			//enable i2c
	_iica = DeviceAddr;	//set i2c slave address 0x27
	_iice = 1;			//ii2 interrupt enable
	//_emi  = 1;		//Global enable interrupt 
}

void i2c_off(void)		//initial I2C
{
	_iice = 0;			//ii2 interrupt disable
	_iicen = 0;			//disable i2c function
	_pcpu5 = 1;			//set pull-high for SDA
	_pcpu6 = 1;			//set pull-high for SDC
	_pcc5 = 1;			//set input
	_pcc6 = 1;			//set input
}
//___________________________________________________________________
//Function: I2C ISR (Only for HT66F318)
//NOTE    : 
//___________________________________________________________________
DEFINE_ISR(I2C_ISR, 0x28)							//for V3 of compiler
//#pragma vector I2C_ISR @ 0x28
//void I2C_ISR(void)
//void __attribute((interrupt(0x28)))  I2C_ISR()	//for V3 of compiler
{
	if(_iichaas)
	{//_haas=1,address match trig interrupt
		if(_iicsrw)
		{//srw=1:slave in transfer mode	
			_iichtx = 1;
			tx_iic_count = 0;
			_iicd = tx_iic[tx_iic_count++];		
		}
		else
		{//srw=0:slave in receive mode
			_iichtx = 0;
			_iictxak = 0;
			_acc = _iicd;		//dummy read from IICD to release scl line
			rx_iic_count=0;
			//rx_iic[rx_iic_count] = _acc;
		} 
	}
	else
	{//_haas=0,data trig interrupt
		if(_iichtx)
		{//htx=1:slave in write state;
			if(_iicrxak)
			{//rxak=1:master stop receiving next byte,master releases scl bus
				_iichtx = 0;
				_iictxak = 0;	
				_acc = _iicd;		//dummy read from IICD to release scl line
				//rx_iic = _acc;
			}
			else
			{//rxak=0:master wants to receive next byte;	
				//_iicd = tx_iic;
				_iicd = tx_iic[tx_iic_count++];	
			}			
		}
		else
		{//htx=0:slave in read state
			rx_iic[rx_iic_count] = _iicd;	
			rx_iic_count++;	
			_iictxak = 0;				
		}
	}
	//_iicf = 0;						//clr i2c interrupt flag 	
}

//___________________________________________________________________
//Function: I2C Manager (Only for HT66F318)
//NOTE    : 
//___________________________________________________________________
void i2c_manage(void)
{
	
	
	
}