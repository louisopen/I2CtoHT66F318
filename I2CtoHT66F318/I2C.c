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
	
	//_i2ctoc = 0x00;		//I2C Time out reg. disable
	_i2ctoc = 0B10111111;	//I2C Time out reg. MAX
	
	_iicen = 1;			//enable i2c
	_iica = DeviceAddr << 1;	//set i2c slave address 0x27
	_iicf = 0;
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
//DEFINE_ISR(I2C_ISR, 0x28)							//for V1 of compiler
//#pragma vector I2C_ISR @ 0x28						//for V2 of compiler
//void I2C_ISR(void)
void __attribute((interrupt(0x28)))  I2C_ISR()	//for V3 of compiler
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
		{//htx=1:slave in write data;
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
		{//htx=0:slave in read data
			rx_iic[rx_iic_count] = _iicd;	
			rx_iic_count++;	
			_iictxak = 0;
			
			if (rx_iic_count>=DataCount){ 	//copy for applications 
				i2c_rx_success=1;
				for(tx_iic_count=0; tx_iic_count<DataCount; tx_iic_count++)
					tx_iic[tx_iic_count] = rx_iic[tx_iic_count];
			}			
		}
		/*
		if(edge_int_flag)		//test "每收到一個byte" toggle output
		{	edge_int_flag=0;
			IO_test=0;
		}
		else
		{	edge_int_flag=1;
			IO_test=1;
		}
		*/	
	}
	//_iicf = 0;						//clr i2c interrupt flag 	
}

//___________________________________________________________________
//Function: I2C Manager (Only for HT66F318)
//NOTE    : 
//___________________________________________________________________
void i2c_manage(void)
{
	if(i2c_rx_success) {
		i2c_rx_success=0;
		Port0 = rx_iic[0];
		Port1 = rx_iic[1];		
	}
}