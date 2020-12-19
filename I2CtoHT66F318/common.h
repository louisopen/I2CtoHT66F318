//___________________________________________________________________
//___________________________________________________________________
// Description: This Application
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: common.h
//Targer Board: MK8002D
//    MCU Body: HT66F317 HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#ifndef _COMMON_H_
#define _COMMON_H_

#include "HT66F318.h"
#include "typedef.h"
#include "I2C.h"
#include "Sys_Init.h"
//#include "Uart.h"
//#include "bc7602.h"
#include "Interrupt.h"

#define TB0_int_flag	interrupt_flag.bits.b0
#define TB1_int_flag	interrupt_flag.bits.b1
#define i2c_rx_success  interrupt_flag.bits.b4

#define toggle_led		system_flag.bits.b0
#define toggle_buzzer	system_flag.bits.b1
#define sleep_request	system_flag.bits.b2
#define edge_int_flag	system_flag.bits.b3

//PCF8574 P07~P00 => pa7~pa0  	(24pin/28pin) 
//PCF8575 P07~P00 add P17~P10 => pb6~pb2,pc2~pc0 	(24pin/28pin)
//HT66F318 LED64 (PCF8575 with pc4,pc3,pb1,pb0) 8x4ch+8x4ch	(24pin/28pin)

#define Vbat_adc 	AN0		//binding _pb0 , AN0=0
#define IO_test 	_pb1	//label: P0.5
#define Buzzer	 	_pb2
//#define LED_fast 	_pa3	//LED flash fast
//#define PWMout	_pb3	//pb3 binding TP2(TM2) CTM already
//#define Capture	_pa7	//pa7 binding TP1(TM1) PTM already
#define LED_slow 	_pa0	//pa0 not binding TP0(TM0) STM already

extern unsigned char Port0, Port1;

#endif
