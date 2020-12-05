//___________________________________________________________________
//___________________________________________________________________
// Description: Main program
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: main
//Targer Board: MK8002D 
//    MCU Body: HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"

unsigned char Port0, Port1;
//___________________________________________________________________
//___________________________________________________________________
//___________________________________________________________________
void main()
{	//like Arduino setup();
	if(_to ==0 || _pdf ==0)		//power up or reset pin normal.
	{	//�W�q�_��Ϊ̬O���`���p�U���D���`�_��
		Ram_Init();		//RAM clear all, first time power up.
		PowerOn_Init();	//�Ĥ@���W�q�Υ��`reset pin 
		WDT_ResetInit();                          								
	}
	else//Watch dog reset 													
	{	//WDT�y�����X���_��
		WDT_ResetInit();	
	}
	//sleep_request=1;					//test sleep request
	while(1)	//like Arduino loop() for main loop
	{	
		//GCC_CLRWDT();		//Clear Watchdog
		_clrwdt();			//Clear Watchdog
		//Uart_RXD_Manage();	//Received process/check
		i2c_manage();		//Received process/check
		if(sleep_request)	//Enter sleep mode ?
		{
 			ReadyToHalt();
		}
		else
		{
			Task_500ms();	//TimeBase Task process/check
			Key_Scan();		
		}
	}
}
