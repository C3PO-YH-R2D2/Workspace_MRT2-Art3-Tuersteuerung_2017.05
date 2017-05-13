#ifndef SFR62_H
#define SFR62_H
/*******************************************************************************
 *                                                                             *
 * Special Function Registers for M16C/6xxx microcontrollers                   *
 *                                                                             *
 * All special function registers can be accessed like variables by using the  *
 * names (in all uppercase) given in the device datasheet.                     *
 * Some registers (e.g. IO ports) have definitions for bitwise access as well. *
 *                                                                             *
 * Additionally, for every register where bitwise access is not explicitely    *
 * forbidden, there is a union definition named SFR_+<register>, which allows  *
 * arbitrary bit and byte access to the register location.                     *
 *                                                                             *
 * Registers marked with (62) are not available on 61xx parts.                 *                                                             
 ******************************************************************************/ 

/* Type for byte and bitwise access to special function registers */
typedef union{
	struct{
		unsigned char b0: 1;
		unsigned char b1: 1;
		unsigned char b2: 1;
		unsigned char b3: 1;
		unsigned char b4: 1;
		unsigned char b5: 1;
		unsigned char b6: 1;
		unsigned char b7: 1;				
	}bits;
	unsigned char all;
}SFR8_t;

typedef union{
	struct{
		unsigned char b0: 1;
		unsigned char b1: 1;
		unsigned char b2: 1;
		unsigned char b3: 1;
		unsigned char b4: 1;
		unsigned char b5: 1;
		unsigned char b6: 1;
		unsigned char b7: 1;
		unsigned char b8: 1;
		unsigned char b9: 1;	
		unsigned char b10: 1;
		unsigned char b11: 1;
		unsigned char b12: 1;
		unsigned char b13: 1;
		unsigned char b14: 1;
		unsigned char b15: 1;
	}bits;
	struct{
		unsigned char ucLow;
		unsigned char ucHigh;
	}bytes;
	unsigned int uiAll;
}SFR16_t;

typedef union{
	struct{
		unsigned char b0: 1;
		unsigned char b1: 1;
		unsigned char b2: 1;
		unsigned char b3: 1;
		unsigned char b4: 1;
		unsigned char b5: 1;
		unsigned char b6: 1;
		unsigned char b7: 1;
		unsigned char b8: 1;
		unsigned char b9: 1;	
		unsigned char b10: 1;
		unsigned char b11: 1;
		unsigned char b12: 1;
		unsigned char b13: 1;
		unsigned char b14: 1;
		unsigned char b15: 1;
		unsigned char b16: 1;
		unsigned char b17: 1;
		unsigned char b18: 1;
		unsigned char b19: 1;
	}bits;
	struct{
		unsigned char ucLow;
		unsigned char ucMid;
		unsigned char ucHigh;
	}bytes;
	unsigned long ulAll;
}SFR20_t;

/*******************************************************************************
 *                                IO PORTS                                     *                       
 ******************************************************************************/ 

/* definitions for Port all direction registers */  
#define PD_INPUT						0
#define PD_OUTPUT                   	1

/* Port control register */
#pragma ADDRESS SFR_PCR					03ffH
SFR8_t SFR_PCR;
#define PCR								SFR_PCR.all

#define PCR_P0_READ_NORMAL				(1 << 0)
#define PCR_P0_READ_LATCH				(1 << 0)


/*! Pull-Up control registers */
#pragma ADDRESS SFR_PUR0				03fcH
SFR8_t SFR_PUR0;
#define PUR0							SFR_PUR0.all

#define PUR0_P0_0_TO_3					(1 << 0)
#define PUR0_P0_4_TO_7					(1 << 1)
#define PUR0_P1_0_TO_3					(1 << 2)
#define PUR0_P1_4_TO_7					(1 << 3)
#define PUR0_P2_0_TO_3					(1 << 4)
#define PUR0_P2_4_TO_7					(1 << 5)
#define PUR0_P3_0_TO_3					(1 << 6)
#define PUR0_P3_4_TO_7					(1 << 7)

#pragma ADDRESS SFR_PUR1				03fdH
SFR8_t SFR_PUR1;
#define PUR1							SFR_PUR1.all

#define PUR1_P4_0_TO_3					(1 << 0)
#define PUR1_P4_4_TO_7					(1 << 1)
#define PUR1_P5_0_TO_3					(1 << 2)
#define PUR1_P5_4_TO_7					(1 << 3)
#define PUR1_P6_0_TO_3					(1 << 4)
#define PUR1_P6_4_TO_7					(1 << 5)
#define PUR1_P7_0_TO_3					(1 << 6)
#define PUR1_P7_4_TO_7					(1 << 7)

#pragma ADDRESS SFR_PUR2				03feH
SFR8_t SFR_PUR2;					
#define PUR2							SFR_PUR2.all

#define PUR2_P8_0_TO_3					(1 << 0)
#define PUR2_P8_4_TO_7					(1 << 1)
#define PUR2_P9_0_TO_3					(1 << 2)
#define PUR2_P9_4_TO_7					(1 << 3)
#define PUR2_P10_0_TO_3					(1 << 4)
#define PUR2_P10_4_TO_7					(1 << 5)


/* P0 port and data direction register */
#pragma ADDRESS SFR_P0					03e0H
SFR8_t SFR_P0;
#define P0								SFR_P0.all;

#define P0_0	                		SFR_P0.bits.b0
#define P0_1	                		SFR_P0.bits.b1
#define P0_2	                		SFR_P0.bits.b2
#define P0_3	                		SFR_P0.bits.b3
#define P0_4	                		SFR_P0.bits.b4
#define P0_5	                		SFR_P0.bits.b5
#define P0_6	                		SFR_P0.bits.b6
#define P0_7	                		SFR_P0.bits.b7

#pragma ADDRESS SFR_PD0					03e2H
SFR8_t SFR_PD0;
#define PD0								SFR_PD0.all

#define PD0_0							SFR_PD0.bits.b0
#define PD0_1							SFR_PD0.bits.b1
#define PD0_2							SFR_PD0.bits.b2
#define PD0_3							SFR_PD0.bits.b3
#define PD0_4							SFR_PD0.bits.b4
#define PD0_5							SFR_PD0.bits.b5
#define PD0_6							SFR_PD0.bits.b6
#define PD0_7							SFR_PD0.bits.b7

/* P1 port and data direction register */
#pragma ADDRESS SFR_P1					03e1H
SFR8_t SFR_P1;
#define P1								SFR_P1.all;

#define P1_0	                		SFR_P1.bits.b0
#define P1_1	                		SFR_P1.bits.b1
#define P1_2	                		SFR_P1.bits.b2
#define P1_3	                		SFR_P1.bits.b3
#define P1_4	                		SFR_P1.bits.b4
#define P1_5	                		SFR_P1.bits.b5
#define P1_6	                		SFR_P1.bits.b6
#define P1_7	                		SFR_P1.bits.b7

#pragma ADDRESS SFR_PD1					03e3H
SFR8_t SFR_PD1;
#define PD1								SFR_PD1.all

#define PD1_0							SFR_PD1.bits.b0
#define PD1_1							SFR_PD1.bits.b1
#define PD1_2							SFR_PD1.bits.b2
#define PD1_3							SFR_PD1.bits.b3
#define PD1_4							SFR_PD1.bits.b4
#define PD1_5							SFR_PD1.bits.b5
#define PD1_6							SFR_PD1.bits.b6
#define PD1_7							SFR_PD1.bits.b7

/* P2 port and data direction register */
#pragma ADDRESS SFR_P2					03e4H
SFR8_t SFR_P2;
#define P2								SFR_P2.all;

#define P2_0	                		SFR_P2.bits.b0
#define P2_1	                		SFR_P2.bits.b1
#define P2_2	                		SFR_P2.bits.b2
#define P2_3	                		SFR_P2.bits.b3
#define P2_4	                		SFR_P2.bits.b4
#define P2_5	                		SFR_P2.bits.b5
#define P2_6	                		SFR_P2.bits.b6
#define P2_7	                		SFR_P2.bits.b7

#pragma ADDRESS SFR_PD2					03e6H
SFR8_t SFR_PD2;
#define PD2								SFR_PD2.all

#define PD2_0							SFR_PD2.bits.b0
#define PD2_1							SFR_PD2.bits.b1
#define PD2_2							SFR_PD2.bits.b2
#define PD2_3							SFR_PD2.bits.b3
#define PD2_4							SFR_PD2.bits.b4
#define PD2_5							SFR_PD2.bits.b5
#define PD2_6							SFR_PD2.bits.b6
#define PD2_7							SFR_PD2.bits.b7

/* P3 port and data direction register */
#pragma ADDRESS SFR_P3					03e5H
SFR8_t SFR_P3;
#define P3								SFR_P3.all;

#define P3_0	                		SFR_P3.bits.b0
#define P3_1	                		SFR_P3.bits.b1
#define P3_2	                		SFR_P3.bits.b2
#define P3_3	                		SFR_P3.bits.b3
#define P3_4	                		SFR_P3.bits.b4
#define P3_5	                		SFR_P3.bits.b5
#define P3_6	                		SFR_P3.bits.b6
#define P3_7	                		SFR_P3.bits.b7

#pragma ADDRESS SFR_PD3					03e7H
SFR8_t SFR_PD3;
#define PD3								SFR_PD3.all

#define PD3_0							SFR_PD3.bits.b0
#define PD3_1							SFR_PD3.bits.b1
#define PD3_2							SFR_PD3.bits.b2
#define PD3_3							SFR_PD3.bits.b3
#define PD3_4							SFR_PD3.bits.b4
#define PD3_5							SFR_PD3.bits.b5
#define PD3_6							SFR_PD3.bits.b6
#define PD3_7							SFR_PD3.bits.b7

/* P4 port and data direction register */
#pragma ADDRESS SFR_P4					03e8H
SFR8_t SFR_P4;
#define P4								SFR_P4.all;

#define P4_0	                		SFR_P4.bits.b0
#define P4_1	                		SFR_P4.bits.b1
#define P4_2	                		SFR_P4.bits.b2
#define P4_3	                		SFR_P4.bits.b3
#define P4_4	                		SFR_P4.bits.b4
#define P4_5	                		SFR_P4.bits.b5
#define P4_6	                		SFR_P4.bits.b6
#define P4_7	                		SFR_P4.bits.b7

#pragma ADDRESS SFR_PD4					03eaH
SFR8_t SFR_PD4;
#define PD4								SFR_PD4.all

#define PD4_0							SFR_PD4.bits.b0
#define PD4_1							SFR_PD4.bits.b1
#define PD4_2							SFR_PD4.bits.b2
#define PD4_3							SFR_PD4.bits.b3
#define PD4_4							SFR_PD4.bits.b4
#define PD4_5							SFR_PD4.bits.b5
#define PD4_6							SFR_PD4.bits.b6
#define PD4_7							SFR_PD4.bits.b7

/* P5 port and data direction register */
#pragma ADDRESS SFR_P5					03e9H
SFR8_t SFR_P5;
#define P5								SFR_P5.all;

#define P5_0	                		SFR_P5.bits.b0
#define P5_1	                		SFR_P5.bits.b1
#define P5_2	                		SFR_P5.bits.b2
#define P5_3	                		SFR_P5.bits.b3
#define P5_4	                		SFR_P5.bits.b4
#define P5_5	                		SFR_P5.bits.b5
#define P5_6	                		SFR_P5.bits.b6
#define P5_7	                		SFR_P5.bits.b7

#pragma ADDRESS SFR_PD5					03ebH
SFR8_t SFR_PD5;
#define PD5								SFR_PD5.all

#define PD5_0							SFR_PD5.bits.b0
#define PD5_1							SFR_PD5.bits.b1
#define PD5_2							SFR_PD5.bits.b2
#define PD5_3							SFR_PD5.bits.b3
#define PD5_4							SFR_PD5.bits.b4
#define PD5_5							SFR_PD5.bits.b5
#define PD5_6							SFR_PD5.bits.b6
#define PD5_7							SFR_PD5.bits.b7

/* P6 port and data direction register */
#pragma ADDRESS SFR_P6					03ecH
SFR8_t SFR_P6;
#define P6								SFR_P6.all;

#define P6_0	                		SFR_P6.bits.b0
#define P6_1	                		SFR_P6.bits.b1
#define P6_2	                		SFR_P6.bits.b2
#define P6_3	                		SFR_P6.bits.b3
#define P6_4	                		SFR_P6.bits.b4
#define P6_5	                		SFR_P6.bits.b5
#define P6_6	                		SFR_P6.bits.b6
#define P6_7	                		SFR_P6.bits.b7

#pragma ADDRESS SFR_PD6					03eeH
SFR8_t SFR_PD6;
#define PD6								SFR_PD6.all

#define PD6_0							SFR_PD6.bits.b0
#define PD6_1							SFR_PD6.bits.b1
#define PD6_2							SFR_PD6.bits.b2
#define PD6_3							SFR_PD6.bits.b3
#define PD6_4							SFR_PD6.bits.b4
#define PD6_5							SFR_PD6.bits.b5
#define PD6_6							SFR_PD6.bits.b6
#define PD6_7							SFR_PD6.bits.b7

/* P7 port and data direction register */
#pragma ADDRESS SFR_P7					03edH
SFR8_t SFR_P7;
#define P7								SFR_P7.all;

#define P7_0	                		SFR_P7.bits.b0
#define P7_1	                		SFR_P7.bits.b1
#define P7_2	                		SFR_P7.bits.b2
#define P7_3	                		SFR_P7.bits.b3
#define P7_4	                		SFR_P7.bits.b4
#define P7_5	                		SFR_P7.bits.b5
#define P7_6	                		SFR_P7.bits.b6
#define P7_7	                		SFR_P7.bits.b7

#pragma ADDRESS SFR_PD7					03efH
SFR8_t SFR_PD7;
#define PD7								SFR_PD7.all

#define PD7_0							SFR_PD7.bits.b0
#define PD7_1							SFR_PD7.bits.b1
#define PD7_2							SFR_PD7.bits.b2
#define PD7_3							SFR_PD7.bits.b3
#define PD7_4							SFR_PD7.bits.b4
#define PD7_5							SFR_PD7.bits.b5
#define PD7_6							SFR_PD7.bits.b6
#define PD7_7							SFR_PD7.bits.b7

/* P8 port and data direction register */
#pragma ADDRESS SFR_P8					03f0H
SFR8_t SFR_P8;
#define P8								SFR_P8.all;

#define P8_0	                		SFR_P8.bits.b0
#define P8_1	                		SFR_P8.bits.b1
#define P8_2	                		SFR_P8.bits.b2
#define P8_3	                		SFR_P8.bits.b3
#define P8_4	                		SFR_P8.bits.b4
#define P8_5	                		SFR_P8.bits.b5 // read only
#define P8_6	                		SFR_P8.bits.b6
#define P8_7	                		SFR_P8.bits.b7

#pragma ADDRESS SFR_PD8					03f2H
SFR8_t SFR_PD8;
#define PD8								SFR_PD8.all

#define PD8_0							SFR_PD8.bits.b0
#define PD8_1							SFR_PD8.bits.b1
#define PD8_2							SFR_PD8.bits.b2
#define PD8_3							SFR_PD8.bits.b3
#define PD8_4							SFR_PD8.bits.b4
// Pin P8_5 is input only
#define PD8_6							SFR_PD8.bits.b6
#define PD8_7							SFR_PD8.bits.b7

/* P9 port and data direction register */
#pragma ADDRESS SFR_P9					03f1H
SFR8_t SFR_P9;
#define P9								SFR_P9.all;

#define P9_0	                		SFR_P9.bits.b0
#define P9_1	                		SFR_P9.bits.b1
#define P9_2	                		SFR_P9.bits.b2
#define P9_3	                		SFR_P9.bits.b3
#define P9_4	                		SFR_P9.bits.b4
#define P9_5	                		SFR_P9.bits.b5
#define P9_6	                		SFR_P9.bits.b6
#define P9_7	                		SFR_P9.bits.b7

#pragma ADDRESS SFR_PD9					03f3H
SFR8_t SFR_PD9;
#define PD9								SFR_PD9.all

#define PD9_0							SFR_PD9.bits.b0
#define PD9_1							SFR_PD9.bits.b1
#define PD9_2							SFR_PD9.bits.b2
#define PD9_3							SFR_PD9.bits.b3
#define PD9_4							SFR_PD9.bits.b4
#define PD9_5							SFR_PD9.bits.b5
#define PD9_6							SFR_PD9.bits.b6
#define PD9_7							SFR_PD9.bits.b7

/* P10 port and data direction register */
#pragma ADDRESS SFR_P10					03f4H
SFR8_t SFR_P10;
#define P10								SFR_P10.all;

#define P10_0	                		SFR_P10.bits.b0
#define P10_1	                		SFR_P10.bits.b1
#define P10_2	                		SFR_P10.bits.b2
#define P10_3	                		SFR_P10.bits.b3
#define P10_4	                		SFR_P10.bits.b4
#define P10_5	                		SFR_P10.bits.b5
#define P10_6	                		SFR_P10.bits.b6
#define P10_7	                		SFR_P10.bits.b7

#pragma ADDRESS SFR_PD10				03f6H
SFR8_t SFR_PD10;
#define PD10							SFR_PD10.all

#define PD10_0							SFR_PD10.bits.b0
#define PD10_1							SFR_PD10.bits.b1
#define PD10_2							SFR_PD10.bits.b2
#define PD10_3							SFR_PD10.bits.b3
#define PD10_4							SFR_PD10.bits.b4
#define PD10_5							SFR_PD10.bits.b5
#define PD10_6							SFR_PD10.bits.b6
#define PD10_7							SFR_PD10.bits.b7

/*******************************************************************************
 *           common definitions for all interrupt control registers            *                       
 ******************************************************************************/ 

#define IC_LEVEL(n)						((n) & 0x7)
#define IC_DISABLED						IC_LEVEL(0)
#define IC_RESET_REQUEST				(1 << 3)
#define IC_POLARITY_FALLING				(0 << 4)
#define IC_POLARITY_RISING				(1 << 4)

/*******************************************************************************
 *                  common definitions for all timers                          *
 ******************************************************************************/ 

/* Clock prescaler reset flag */
#pragma ADDRESS SFR_CPSRF				0381H
SFR8_t SFR_CPSRF;
#define CPSRF							SFR_CPSRF.all;

#define CPSRF_CPSR						SFR_CPSRF.bits.b7

/* Timer A/B count start flag */ 
#pragma ADDRESS SFR_TABSR				0380H
SFR8_t SFR_TABSR;
#define TABSR							SFR_TABSR.all

#define TABSR_TA0S						SFR_TABSR.bits.b0
#define TABSR_TA1S						SFR_TABSR.bits.b1
#define TABSR_TA2S						SFR_TABSR.bits.b2
#define TABSR_TA3S						SFR_TABSR.bits.b3
#define TABSR_TA4S						SFR_TABSR.bits.b4

#define TABSR_TB0S						SFR_TABSR.bits.b5 
#define TABSR_TB1S						SFR_TABSR.bits.b6
#define TABSR_TB2S						SFR_TABSR.bits.b7
 
/* start/stop timers in TABSR und TBSR */
#define TSR_START						1
#define TSR_STOP						0

/*******************************************************************************
 *                          TIMER A peripheral                                 *                       
 ******************************************************************************/ 

/* Timer A0 interrupt control register */
#pragma ADDRESS SFR_TA0IC				0055H
SFR8_t SFR_TA0IC;
#define TA0IC							SFR_TA0IC.all
#define TA0IC_IR						SFR_TA0IC.bits.b3

/* Timer A1 interrupt control register */
#pragma ADDRESS SFR_TA1IC				0056H
SFR8_t SFR_TA1IC;
#define TA1IC							SFR_TA1IC.all
#define TA1IC_IR						SFR_TA1IC.bits.b3

/* Timer A2 interrupt control register */
#pragma ADDRESS SFR_TA2IC				0057H
SFR8_t SFR_TA2IC;
#define TA2IC							SFR_TA2IC.all
#define TA2IC_IR						SFR_TA2IC.bits.b3

/* Timer A3 interrupt control register */
#pragma ADDRESS SFR_TA3IC				0058H
SFR8_t SFR_TA3IC;
#define TA3IC							SFR_TA3IC.all
#define TA3IC_IR						SFR_TA3IC.bits.b3
  
/* Timer A4 interrupt control register */
#pragma ADDRESS SFR_TA4IC				0059H
SFR8_t SFR_TA4IC;
#define TA4IC							SFR_TA4IC.all
#define TA4IC_IR						SFR_TA4IC.bits.b3

/* Timer A0 */
#pragma ADDRESS TA0						0386H
unsigned int TA0;

/* Timer A1 */
#pragma ADDRESS TA1						0388H
unsigned int TA1;
/* Timer A1-1 (62) */
#pragma ADDRESS TA11					0342H
unsigned int TA11;

/* Timer A2 */
#pragma ADDRESS TA2						038aH
unsigned int TA2;
/* Timer A2-1 (62) */
#pragma ADDRESS TA21					0344H
unsigned int TA21;

/* Timer A3 */
#pragma ADDRESS TA3						038cH
unsigned int TA3;

/* Timer A4 */
#pragma ADDRESS TA4						038eH
unsigned int TA4;
/* Timer A4-1 (62) */
#pragma ADDRESS TA41					0346H
unsigned int TA41;

/* Definitions for all Timer A mode registers */
#define TAMR_MODE_TIMER					0
#define TAMR_MODE_EVENT					1
#define TAMR_MODE_EVENT_TWOPHASE		(TAMR_MODE_EVENT | (0x4 << 2)
#define TAMR_MODE_ONESHOT				2
#define TAMR_MODE_PWM					3

#define TAMR_TAOUT_DISABLED				(0 << 2) 
#define TAMR_TAOUT_ENABLED				(1 << 2)

#define TAMR_TRIGGER_EDGE_FALLING		(0 << 3)
#define TAMR_TRIGGER_EDGE_RISING		(1 << 3)
#define TAMR_TRIGGER_EDGE_BOTH			

#define TAMS_TRIGGER_SELECT_TAS			(0 << 4)
#define TAMR_TRIGGER_SELECT_TAOS		(0 << 4)
#define TAMS_TRIGGER_SELECT_TATG		(1 << 4)

#define TAMR_CLOCK_SOURCE_F1			(0 << 6)
#define TAMR_CLOCK_SOURCE_F2			(0 << 6)
#define TAMR_CLOCK_SOURCE_F8			(1 << 6)
#define TAMR_CLOCK_SOURCE_F32			(2 << 6)
#define TAMR_CLOCK_SOURCE_FC32			(3 << 6)

#define TAMS_PWM_16BIT					(0 << 5)
#define TAMS_PWM_8BIT					(1 << 5)

#define TAMR_EVENT_RELOAD				(0 << 6)
#define TAMR_EVENT_FREERUN				(1 << 6)

#define TAMR_EVENT_MULTIPLY_BY_4		(1 << 7)

#define TAMR_EVENT_UPDOWN_UDF			(0 << 4)
#define TAMR_EVENT_UPDOWN_TAIN			(1 << 4)

#define TAMR_TIMER_GATING_NONE			(0 << 3)
#define TAMR_TIMER_GATING_TIN_LOW		(2 << 3)
#define TAMR_TIMER_GATING_TIN_HIGH		(3 << 3)

/* Timer A0 mode register */
#pragma ADDRESS SFR_TA0MR				0396H
SFR8_t SFR_TA0MR;
#define TA0MR							SFR_TA0MR.all

/* Timer A1 mode register */
#pragma ADDRESS SFR_TA1MR				0397H
SFR8_t SFR_TA1MR;
#define TA1MR							SFR_TA1MR.all

/* Timer A2 mode register */
#pragma ADDRESS SFR_TA2MR				0398H
SFR8_t SFR_TA2MR;
#define TA2MR							SFR_TA2MR.all

/* Timer A3 mode register */
#pragma ADDRESS SFR_TA3MR				0399H
SFR8_t SFR_TA3MR;
#define TA3MR							SFR_TA3MR.all

/* Timer A4 mode register */
#pragma ADDRESS SFR_TA4MR				039aH
SFR8_t SFR_TA4MR;
#define TA4MR							SFR_TA4MR.all
 
/* Up-down flag */
#pragma ADDRESS SFR_UDF					0384H
SFR8_t SFR_UDF;
#define UDF								SFR_UDF.all

#define UDF_COUNT_UP					1
#define UDF_COUNT_DOWN					0

#define UDF_TA0UD						SFR_UDF.bits.b0
#define UDF_TA1UD						SFR_UDF.bits.b1
#define UDF_TA2UD						SFR_UDF.bits.b2
#define UDF_TA3UD						SFR_UDF.bits.b3
#define UDF_TA4UD						SFR_UDF.bits.b4

#define UDF_TWOPHASE_DISABLED			0
#define UDF_TWOPHASE_ENABLED			1

#define UDF_TA2P						SFR_UDF.bits.b5
#define UDF_TA3P						SFR_UDF.bits.b6
#define UDF_TA4P						SFR_UDF.bits.b7

/* One-shot start flag */
#pragma ADDRESS SFR_ONSF				0382H
SFR8_t SFR_ONSF;
#define ONSF							SFR_ONSF.all

#define ONSF_TA0OS						SFR_ONSF.bits.b0
#define ONSF_TA1OS						SFR_ONSF.bits.b1
#define ONSF_TA2OS						SFR_ONSF.bits.b2
#define ONSF_TA3OS						SFR_ONSF.bits.b3
#define ONSF_TA4OS						SFR_ONSF.bits.b4
 
#define ONSF_TAZIE						SFR_ONSF.bits.b5 /* Z-phase input enable */

#define ONSF_TA0TG_TA0IN				(0 << 6)
#define ONSF_TA0TG_TB2					(1 << 6)
#define ONSF_TA0TG_TA4					(2 << 6)
#define ONSF_TA0TG_TA1					(3 << 6)

/* Trigger select register */
#pragma ADDRESS SFR_TRGSR				0383H
SFR8_t SFR_TRGSR;
#define TRGSR							SFR_TRGSR.all

#define TRGSR_TA1TG_TA1IN				(0 << 0)
#define TRGSR_TA1TG_TB2					(1 << 0)
#define TRGSR_TA1TG_TA0					(2 << 0)
#define TRGSR_TA1TG_TA1					(3 << 0) 

#define TRGSR_TA2TG_TA2IN				(0 << 2)
#define TRGSR_TA2TG_TB2					(1 << 2)
#define TRGSR_TA2TG_TA1					(2 << 2)
#define TRGSR_TA2TG_TA3					(3 << 2)

#define TRGSR_TA3TG_TA3IN				(0 << 4)
#define TRGSR_TA3TG_TB2					(1 << 4)
#define TRGSR_TA3TG_TA2					(2 << 4)
#define TRGSR_TA3TG_TA4					(3 << 4) 
 
#define TRGSR_TA4TG_TA4IN				(0 << 6)
#define TRGSR_TA4TG_TB2					(1 << 6)
#define TRGSR_TA4TG_TA3					(2 << 6)
#define TRGSR_TA4TG_TA0					(3 << 6) 

/*******************************************************************************
 *                          TIMER B peripheral                                 *                       
 ******************************************************************************/ 

/* Timer B0 interrupt control register */
#pragma ADDRESS SFR_TB0IC				005aH
SFR8_t SFR_TB0IC;
#define TB0IC							SFR_TB0IC.all
#define TB0IC_IR						SFR_TB0IC.bits.b3

/* Timer B1 interrupt control register */
#pragma ADDRESS SFR_TB1IC				005bH
SFR8_t SFR_TB1IC;
#define TB1IC							SFR_TB1IC.all
#define TB1IC_IR						SFR_TB1IC.bits.b3

/* Timer B2 interrupt control register */
#pragma ADDRESS SFR_TB2IC				005cH
SFR8_t SFR_TB2IC;
#define TB2IC							SFR_TB2IC.all
#define TB2IC_IR						SFR_TB2IC.bits.b3

/* Timer B3 interrupt control register (62) */
#pragma ADDRESS SFR_TB3IC				0047H
SFR8_t SFR_TB3IC;
#define TB3IC							SFR_TB3IC.all
#define TB3IC_IR						SFR_TB3IC.bits.b3

/* Timer B4 interrupt control register (62) */
#pragma ADDRESS SFR_TB4IC				0046H
SFR8_t SFR_TB4IC;
#define TB4IC							SFR_TB4IC.all
#define TB4IC_IR						SFR_TB4IC.bits.b3

/* Timer B5 interrupt control register (62) */
#pragma ADDRESS SFR_TB5IC				0045H
SFR8_t SFR_TB5IC;
#define TB5IC							SFR_TB5IC.all
#define TB5IC_IR						SFR_TB5IC.bits.b3
 
/* Timer B0 */
#pragma ADDRESS TB0						0390H
unsigned int TB0;

/* Timer B1 */
#pragma ADDRESS TB1						0392H
unsigned int TB1;

/* Timer B2 */
#pragma ADDRESS TB2						0394H
unsigned int TB2;

/* Timer B3 register (62) */
#pragma ADDRESS TB3						0350H
unsigned int TB3;

/* Timer B4 register (62) */
#pragma ADDRESS TB4						0352H
unsigned int TB4;

/* Timer B5 register (62) */
#pragma ADDRESS TB5						0354H
unsigned int TB5;

#define TBMR_MODE_TIMER					0
#define TBMR_MODE_EVENT					1
#define TBMR_MODE_PULSE_MEASURE			2

#define TBMR_CLOCK_SOURCE_F1			(0 << 6)
#define TBMR_CLOCK_SOURCE_F2			(0 << 6)
#define TBMR_CLOCK_SOURCE_F8			(1 << 6)
#define TBMR_CLOCK_SOURCE_F32			(2 << 6)
#define TBMR_CLOCK_SOURCE_FC32			(3 << 6)

#define TBMR_EVENT_EDGE_FALLING			(0 << 2)
#define TBMR_EVENT_EDGE_RISING			(1 << 2)
#define TBMR_EVENT_EDGE_BOTH			(2 << 2)

#define TBMR_EVENT_SOURCE_TBIN			(0 << 7) /* for all Timer B channels */
#define TBMR_EVENT_SOURCE_TB0_OVERFLOW	(1 << 7) /* for TBMR1 */
#define TBMR_EVENT_SOURCE_TB1_OVERFLOW	(1 << 7) /* for TBMR2 */
#define TBMR_EVENT_SOURCE_TB2_OVERFLOW	(1 << 7) /* for TBMR0 */
#define TBMR_EVENT_SOURCE_TB3_OVERFLOW	(1 << 7) /* for TBMR4 */
#define TBMR_EVENT_SOURCE_TB4_OVERFLOW	(1 << 7) /* for TBMR5 */
#define TBMR_EVENT_SOURCE_TB5_OVERFLOW	(1 << 7) /* for TBMR3 */			
#define TBMR_EVENT_SOURCE_TB0_UNDERFLOW	(1 << 7) /* for TBMR1 */
#define TBMR_EVENT_SOURCE_TB1_UNDERFLOW	(1 << 7) /* for TBMR2 */
#define TBMR_EVENT_SOURCE_TB2_UNDERFLOW	(1 << 7) /* for TBMR0 */
#define TBMR_EVENT_SOURCE_TB3_UNDERFLOW	(1 << 7) /* for TBMR4 */
#define TBMR_EVENT_SOURCE_TB4_UNDERFLOW	(1 << 7) /* for TBMR5 */
#define TBMR_EVENT_SOURCE_TB5_UNDERFLOW	(1 << 7) /* for TBMR3 */

/* Timer B0 mode register */
#pragma ADDRESS SFR_TB0MR				039bH
SFR8_t SFR_TB0MR;
#define TB0MR							SFR_TB0MR.all

/* Timer B1 mode register */
#pragma ADDRESS SFR_TB1MR				039cH
SFR8_t SFR_TB1MR;
#define TB1MR							SFR_TB1MR.all

/* Timer B2 mode register */
#pragma ADDRESS SFR_TB2MR				039dH
SFR8_t SFR_TB2MR;
#define TB2MR							SFR_TB2MR.all

/* Timer B3 mode register (62) */
#pragma ADDRESS SFR_TB3MR				035bH
SFR8_t SFR_TB3MR;
#define TB3MR							SFR_TB3MR.all

/* Timer B4 mode register (62) */
#pragma ADDRESS SFR_TB4MR				035cH
SFR8_t SFR_TB4MR;
#define TB4MR							SFR_TB4MR.all

/* Timer B5 mode register (62) */
#pragma ADDRESS SFR_TB5MR				035dH
SFR8_t SFR_TB5MR;
#define TB5MR							SFR_TB5MR.all

/* Timer B3,4,5 Count start flag (62) */
#pragma ADDRESS SFR_TBSR				0340H
SFR8_t SFR_TBSR;
#define TBSR							SFR_TBSR.all

#define TBSR_TB3S						SFR_TBSR.bits.b5
#define TBSR_TB4S						SFR_TBSR.bits.b6
#define TBSR_TB5S						SFR_TBSR.bits.b7 

/*******************************************************************************
 *                    3-phase motor controller peripheral                      *                       
 ******************************************************************************/ 

/* Three-phase PWM control regester 0 (62) */
#pragma ADDRESS SFR_INVC0				0348H
SFR8_t SFR_INVC0;
#define INVC0							SFR_INVC0.all

#define INVC0_ICTB2INC_ON_A1_RLD_RISING	(2 << 0)
#define INVC0_ICTB2INC_ON_A1_RLD_FALLING	(3 << 0)
#define INVC0_ICTB2INC_ON_B2_UNDERFLOW	(0 << 0)

#define INVC0_MODE_NOTHREEPHASE			(0 << 2)
#define INVC0_MODE_THREEPHASE			(1 << 2)

#define INVC0_OUTPUT_DISABLE			(0 << 3)
#define INVC0_OUTPUT_ENABLE				(1 << 3)

#define INVC0_PHASES_ACTIVE_CONCURRENT	(0 << 4)
#define INVC0_PHASES_ACTIVE_EXCLUSIVE	(1 << 4)

#define INVC0_MODULATION_TRI			(0 << 6)
#define INVC0_MODULATION_SAW			(1 << 6)

#define INVC0_TRANSFER_TRIGGER			(1 << 7)

/* Three-phase PWM control register 1 (62) */
#pragma ADDRESS SFR_INVC1				0349H
SFR8_t SFR_INVC1;
#define INVC1							SFR_INVC1.all

#define INVC1_TATRIG_B2_UNDERFLOW_ONLY	(0 << 0)
#define INVC1_TATRIG_B2_UNDERFLOW_AND_WRITE	(1 << 0)

#define INVC1_THREEPHASE_MODE0			(0 << 1)  
#define INVC1_THREEPHASE_MODE1			(1 << 1)

#define INVC1_DIV_DEAD_TIME_CLOCK		(1 << 2)

#define INVC1_TA1_RELOAD_STATUS			(1 << 3)

#define INVC1_OUTPOLARITY_ACTIVE_LOW	(0 << 4)
#define INVC1_OUTPOLARITY_ACTIVE_HIGH	(1 << 4)

#define INVC1_DEAD_TIME_ENABLED			(0 << 5)
#define INVC1_DEAD_TIME_DISABLED		(1 << 5)

#define INVC1_DEAD_TIME_TRIGGER_PULSE	(0 << 6)
#define INVC1_DEAD_TIME_TRIGGER_PHASE	(1 << 6)

/* Three-phase output buffer register 0 (62) */
#pragma ADDRESS SFR_IDB0				034aH
SFR8_t SFR_IDB0;
#define IDB0							SFR_IDB0.all

/* Three-phase output buffer register 1 (62) */
#pragma ADDRESS SFR_IDB1				034bH
SFR8_t SFR_IDB1;
#define IDB1							SFR_IDB1.all 

#define IDB_U_ACTIVE					(0 << 0)
#define IDB_U_INACTIVE					(1 << 0)
#define IDB_NU_ACTIVE					(0 << 1)
#define IDB_NU_INACTIVE					(1 << 1)

#define IDB_V_ACTIVE					(0 << 2)
#define IDB_V_INACTIVE					(1 << 2)
#define IDB_NV_ACTIVE					(0 << 3)
#define IDB_NV_INACTIVE					(1 << 3)

#define IDB_W_ACTIVE					(0 << 4)
#define IDB_W_INACTIVE					(1 << 4)
#define IDB_NW_ACTIVE					(0 << 5)
#define IDB_NW_INACTIVE					(1 << 5)
 
/* Dead Time Timer (62) */
#pragma ADDRESS DTT						034cH
unsigned char DTT;

/* Timer B2 Interrupt Generation Frequency Set Counter(62) */
#pragma ADDRESS ICTB2					034dH
unsigned char ICTB2;

#pragma ADDRESS TB2SC					039eH
SFR8_t SFR_TB2SC;
#define TB2SC							SFR_TB2SC.all

/*******************************************************************************
 *                          External Interrupts                                *                       
 ******************************************************************************/ 

/* INT0 interrupt control register */
#pragma ADDRESS SFR_INT0IC				005dH
SFR8_t SFR_INT0IC;
#define INT0IC							SFR_INT0IC.all
#define INT0IC_IR						SFR_INT0IC.bits.b3

/* INT1 interrupt control register */
#pragma ADDRESS SFR_INT1IC				005eH
SFR8_t SFR_INT1IC;
#define INT1IC							SFR_INT1IC.all
#define INT1IC_IR						SFR_INT1IC.bits.b3

/* INT2 interrupt control register */
#pragma ADDRESS SFR_INT2IC				005fH
SFR8_t SFR_INT2IC;
#define INT2IC							SFR_INT2IC.all
#define INT2IC_IR						SFR_INT2IC.bits.b3

/* INT3 interrupt control register (62) */
#pragma ADDRESS SFR_INT3IC				0044H
SFR8_t SFR_INT3IC;
#define INT3IC							SFR_INT3IC.all
#define INT3IC_IR						SFR_INT3IC.bits.b3

/* INT4 interrupt control register */
#pragma ADDRESS SFR_INT4IC				0049H
SFR8_t SFR_INT4IC;
#define INT4IC							SFR_INT4IC.all
#define INT4IC_IR						SFR_INT4IC.bits.b3

/* INT5 interrupt control register */
#pragma ADDRESS SFR_INT5IC				0048H
SFR8_t SFR_INT5IC;
#define INT5IC							SFR_INT5IC.all
#define INT5IC_IR						SFR_INT5IC.bits.b3
 
/* interrupt factor select register (62) */
#pragma ADDRESS SFR_IFSR				035fH
SFR8_t SFR_IFSR;
#define IFSR							SFR_IFSR.all

/* ... external interrupt edge selection */ 
#define IFSR_ONE_EDGE
#define IFSR_BOTH_EDGES

#define IFSR_IFSR0						SFR_IFSR.bits.b0
#define IFSR_IFSR1						SFR_IFSR.bits.b1
#define IFSR_IFSR2						SFR_IFSR.bits.b2
#define IFSR_IFSR3						SFR_IFSR.bits.b3
#define IFSR_IFSR4						SFR_IFSR.bits.b4
#define IFSR_IFSR5						SFR_IFSR.bits.b5

/* ... shared interrupt lines: source selection */
#define IFSR_IFSR6						SFR_IFSR.bits.b6
#define IFSR_IFSR6_INT4					1
#define IFSR_IFSR6_SIO3					0

#define IFSR_IFSR7						SFR_IFSR.bits.b7
#define IFSR_IFSR7_INT5					1
#define IFSR_IFSR7_SIO4					0

/* interrupt factor select register 2 (62) */
#pragma ADDRESS SFR_IFSR2				035Eh
SFR8_t SFR_IFSR2;
#define IFSR2							SFR_IFSR2.all

/* ... shared interrupt lines: source selection */
#define IFSR2_IFSR26					SFR_IFSR2.bits.b6
#define IFSR2_IFSR26_TIMER_B3			0
#define IFSR2_IFSR26_UART0_COLLISION	1

#define IFSR2_IFSR27					SFR_IFSR2.bits.b7
#define IFSR2_IFSR27_TIMER_B4			0
#define IFSR2_IFSR27_UART1_COLLISION	1

/*******************************************************************************
 *                  common definitions for all UARTs                           *
 ******************************************************************************/ 

/* UART mode regiter */

#define UMR_MODE_DISABLED				0
#define UMR_MODE_SYNCHRONOUS			1
#define UMR_MODE_I2C					2
#define UMR_MODE_7BITS					4
#define UMR_MODE_8BITS					5
#define UMR_MODE_9BITS					6

#define UMR_CLOCK_INTERNAL				(0 << 3)
#define UMR_CLOCK_EXTERNAL				(1 << 3)

#define UMR_STOPBITS_1					(0 << 4)
#define UMR_STOPBITS_2					(1 << 4)

#define UMR_PARITY_NONE					(0 << 5)
#define UMR_PARITY_ODD					(2 << 5)
#define UMR_PARITY_EVEN					(3 << 5)

#define UMR_IOPOLARITY_NORMAL			(0 << 7)
#define UMR_IOPOLARITY_INVERTED			(1 << 7)

/* UART transmit/receive control register 0 */
#define UC0_CLOCK_SOURCE_F1SIO			(0 << 0)
#define UC0_CLOCK_SOURCE_F2SIO			(0 << 0)
#define UC0_CLOCK_SOURCE_F8SIO			(1 << 0)
#define UC0_CLOCK_SOURCE_F32SIO			(2 << 0)

#define UC0_FLOWCTRL_OFF				(1 << 4)
#define UC0_FLOWCTRL_CTS				(0 << 2)
#define UC0_FLOWCTRL_RTS				(1 << 2)

#define UC0_TXEPT						(1 << 3)

#define UC0_OUTPUT_CMOS					(0 << 5)
#define UC0_OUTPUT_OPENDRAIN			(1 << 5)

#define UC0_CLOCKPOLARITY_NORMAL		(0 << 6)
#define UC0_CLOCKPOLARITY_INVERTED		(1 << 6)

#define UC0_FORMAT_LSBFIRST				(0 << 7)
#define UC0_FORMAT_MSBFIRST				(1 << 7)

/* UART transmit/receive control register 1 */	
#define UC1_TX_DISABLED					(0 << 0)
#define UC1_TX_ENABLED					(1 << 0)

#define UC1_TI							(1 << 1)

#define UC1_RX_DISABLED					(0 << 2)
#define UC1_RX_ENABLED					(1 << 2)

#define UC1_RI							(1 << 3)

#define UC1_DATALOGIC_NORMAL			(0 << 6)
#define UC1_DATALOGIC_REVERSE			(1 << 6)

#define UC1_ERROR_OUTPUT_DISABLED		(0 << 7)
#define UC1_ERROR_OUTPUT_ENABLED		(1 << 7)

/* Get data and errors in Receive buffer register */
#define URB_DATA(reg)					((reg) & 0x01FF)						

#define URB_ABT							(1 << 11)
#define URB_OER							(1 << 12)
#define URB_FER							(1 << 13)
#define URB_PER							(1 << 14)
#define URB_SUM							(1 << 15)

#define URB_ERRORS(reg)					((reg) & (URB_ABT | URB_OER | URB_FER | URB_PER | URB_SUM))

/* UART transmit/receive control register 2 */ 
#pragma ADDRESS SFR_UCON				03b0H
SFR8_t SFR_UCON;
#define UCON							SFR_UCON.all

#define UCON_UART0_INT_TXEMPTY			(0 << 0)
#define UCON_UART0_INT_TXCOMPLETE		(1 << 0)

#define UCON_UART1_INT_TXEMPTY			(0 << 1)
#define UCON_UART1_INT_TXCOMPLETE		(1 << 1) 

#define UCON_UART0_CONTINUOUS_RECEIVE	(1 << 2)
#define UCON_UART1_CONTINUOUS_RECEIVE	(1 << 3)		

#define UCON_UART1_CLKOUT_CLK1			(0 << 4)
#define UCON_UART1_CLKOUT_CLKS1			(3 << 4)

#define UCON_UART0_CTSRTS_SHARED		(0 << 6)
#define UCON_UART0_CTSRTS_SEPARATE		(1 << 6)


/* UART Special Mode Register (1) */
#define USMR_IICM						(1 << 0)
#define USMR_ABC						(1 << 1)
#define USMR_BBS						(1 << 2)
#define USMR_LSYN						(1 << 3)
#define UMSR_ABSCS						(1 << 4)
#define UMSR_ACSE						(1 << 5)
#define UMSR_SSS						(1 << 6)

/* UART Special Mode Register 2 */
#define USMR2_IICM2						(1 << 0)
#define USMR2_CSC						(1 << 1)
#define USMR2_SWC						(1 << 2)
#define USMR2_ALS						(1 << 3)
#define USMR2_STAC						(1 << 4)
#define USMR2_SWC2						(1 << 5)
#define USMR2_SDHI						(1 << 6)

/* UART Special Mode Register 3 */
#define USMR3_CKPH						(1 << 1)
#define USMR3_NODC						(1 << 3)
#define USMR3_DL0						(1 << 5)
#define USMR3_DL1						(1 << 6)
#define USMR3_DL2						(1 << 7)

/* UART Special Mode Register 4 */
#define USMR4_STAREQ					(1 << 0)
#define USMR4_RSTAREQ					(1 << 1)
#define USMR4_STPREQ					(1 << 2)
#define USMR4_STSPSEL					(1 << 3)
#define USMR4_ACKD						(1 << 4)
#define	USMR4_ACKC						(1 << 5)
#define USMR4_SCLHI						(1 << 6)
#define USMR4_SWC9						(1 << 7)


/*******************************************************************************
 *                           UART0 peripheral                                  *
 ******************************************************************************/ 

/* UART0 transmit interrupt control register */
#pragma ADDRESS SFR_S0TIC				0051H 
SFR8_t SFR_S0TIC;
#define S0TIC							SFR_S0TIC.all
#define S0TIC_IR						SFR_S0TIC.bits.b3

/* UART0 receive interrupt control register */
#pragma ADDRESS SFR_S0RIC				0052H
SFR8_t SFR_S0RIC;
#define S0RIC							SFR_S0RIC.all
#define S0RIC_IR						SFR_S0RIC.bits.b3 

/* UART0 transmit/receive mode register */
#pragma ADDRESS SFR_U0MR				03a0H
SFR8_t SFR_U0MR;
#define U0MR							SFR_U0MR.all

/* UART0 bit rate generator */
#pragma ADDRESS SFR_U0BRG				03a1H
SFR8_t SFR_U0BRG;
#define U0BRG							SFR_U0BRG.all

/* UART0 transmit/receive control register 0 */
#pragma ADDRESS SFR_U0C0				03a4H
SFR8_t SFR_U0C0;
#define U0C0							SFR_U0C0.all
#define U0C0_TXEPT						SFR_U0C0.bits.b3

/* UART0 transmit/receive control register 1 */
#pragma ADDRESS SFR_U0C1				03a5H
SFR8_t SFR_U0C1;
#define U0C1							SFR_U0C1.all
#define U0C1_TI							SFR_U0C1.bits.b1
#define U0C1_RI							SFR_U0C1.bits.b3

/* UART0 transmit buffer register */
#pragma ADDRESS SFR_U0TB				03a2H
SFR16_t SFR_U0TB;
#define U0TB							SFR_U0TB.uiAll
#define U0TBL							SFR_U0TB.structBytes.ucLow

/* UART0 receive buffer register */
#pragma ADDRESS SFR_U0RB				03a6H
SFR16_t SFR_U0RB;
#define U0RB							SFR_U0RB.uiAll
#define U0RBL							SFR_U0RB.structBytes.ucLow

#define U0RB_ABT						SFR_U0RB.bits.b11 							
#define U0RB_OER						SFR_U0RB.bits.b12
#define U0RB_FER						SFR_U0RB.bits.b13
#define U0RB_PER						SFR_U0RB.bits.b14
#define U0RB_SUM						SFR_U0RB.bits.b15

/* UART0 special mode register (1) */
#pragma ADDRESS SFR_U0SMR				036fH
SFR8_t SFR_U0SMR;
#define U0SMR							SFR_U0SMR.all;

/* UART0 special mode register 2 */
#pragma ADDRESS SFR_U0SMR2				036eH
SFR8_t SFR_U0SMR2;			
#define U0SMR2							SFR_U0SMR2.all

/* UART0 special mode register 3 */
#pragma ADDRESS SFR_U0SMR3				036dH
SFR8_t SFR_U0SMR3;			
#define U0SMR3							SFR_U0SMR3.all

/* UART0 special mode register 4 */
#pragma ADDRESS SFR_U0SMR4				036cH
SFR8_t SFR_U0SMR4;			
#define U0SMR4							SFR_U0SMR4.all

/*******************************************************************************
 *                           UART1 peripheral                                  *
 ******************************************************************************/ 

/* UART1 transmit interrupt control register */
#pragma ADDRESS SFR_S1TIC				0053H 
SFR8_t SFR_S1TIC;
#define S1TIC							SFR_S1TIC.all
#define S1TIC_IR						SFR_S1TIC.bits.b3

/* UART1 receive interrupt control register */
#pragma ADDRESS SFR_S1RIC				0054H
SFR8_t SFR_S1RIC;
#define S1RIC							SFR_S1RIC.all
#define S1RIC_IR						SFR_S1RIC.bits.b3 

/* UART1 transmit/receive mode register */
#pragma ADDRESS SFR_U1MR				03a8H
SFR8_t SFR_U1MR;
#define U1MR							SFR_U1MR.all

/* UART1 bit rate generator */
#pragma ADDRESS SFR_U1BRG				03a9H
SFR8_t SFR_U1BRG;
#define U1BRG							SFR_U1BRG.all

/* UART1 transmit/receive control register 0 */
#pragma ADDRESS SFR_U1C0				03acH
SFR8_t SFR_U1C0;
#define U1C0							SFR_U1C0.all
#define U1C0_TXEPT						SFR_U1C0.bits.b3


/* UART1 transmit/receive control register 1 */
#pragma ADDRESS SFR_U1C1				03adH
SFR8_t SFR_U1C1;
#define U1C1							SFR_U1C1.all
#define U1C1_TI							SFR_U1C1.bits.b1
#define U1C1_RI							SFR_U1C1.bits.b3

/* UART1 transmit buffer register */
#pragma ADDRESS SFR_U1TB				03aaH
SFR16_t SFR_U1TB;
#define U1TB							SFR_U1TB.uiAll
#define U1TBL							SFR_U1TB.structBytes.ucLow

/* UART1 receive buffer register */
#pragma ADDRESS SFR_U1RB				03aeH
SFR16_t SFR_U1RB;
#define U1RB							SFR_U1RB.uiAll
#define U1RBL							SFR_U1RB.structBytes.ucLow

#define U1RB_ABT						SFR_U1RB.bits.b11 							
#define U1RB_OER						SFR_U1RB.bits.b12
#define U1RB_FER						SFR_U1RB.bits.b13
#define U1RB_PER						SFR_U1RB.bits.b14
#define U1RB_SUM						SFR_U1RB.bits.b15

/* UART1 special mode register (1) */
#pragma ADDRESS SFR_U1SMR				0373H
SFR8_t SFR_U1SMR;
#define U1SMR							SFR_U1SMR.all;

/* UART1 special mode register 2 */
#pragma ADDRESS SFR_U1SMR2				0372H
SFR8_t SFR_U1SMR2;			
#define U1SMR2							SFR_U1SMR2.all

/* UART1 special mode register 3 */
#pragma ADDRESS SFR_U1SMR3				0371H
SFR8_t SFR_U1SMR3;			
#define U1SMR3							SFR_U1SMR3.all

/* UART1 special mode register 4 */
#pragma ADDRESS SFR_U1SMR4				0370H
SFR8_t SFR_U1SMR4;			
#define U1SMR4							SFR_U1SMR4.all

/*******************************************************************************
 *                           UART2 peripheral                                  *
 ******************************************************************************/ 

/* UART2 transmit interrupt control register */
#pragma ADDRESS SFR_S2TIC				004fH 
SFR8_t SFR_S2TIC;
#define S2TIC							SFR_S2TIC.all
#define S2TIC_IR						SFR_S2TIC.bits.b3

/* UART2 receive interrupt control register */
#pragma ADDRESS SFR_S2RIC				0050H
SFR8_t SFR_S2RIC;
#define S2RIC							SFR_S2RIC.all
#define S2RIC_IR						SFR_S2RIC.bits.b3 

/* UART2 Bus collision detection interrupt control register (61) */
#pragma ADDRESS SFR_BCNIC				004aH
SFR8_t SFR_BCNIC;
#define BCNIC							SFR_BCNIC.all
#define BCNIC_IR						SFR_BCNIC.bits.b3 

/* UART2 transmit/receive mode register */
#pragma ADDRESS SFR_U2MR				0378H
SFR8_t SFR_U2MR;
#define U2MR							SFR_U2MR.all

/* UART2 bit rate generator */
#pragma ADDRESS SFR_U2BRG				0379H
SFR8_t SFR_U2BRG;
#define U2BRG							SFR_U2BRG.all

/* UART2 transmit/receive control register 0 */
#pragma ADDRESS SFR_U2C0				037cH
SFR8_t SFR_U2C0;
#define U2C0							SFR_U2C0.all
#define U2C0_TXEPT						SFR_U2C0.bits.b3


/* UART2 transmit/receive control register 1 */
#pragma ADDRESS SFR_U2C1				037dH
SFR8_t SFR_U2C1;
#define U2C1							SFR_U2C1.all
#define U2C1_TI							SFR_U2C1.bits.b1
#define U2C1_RI							SFR_U2C1.bits.b3

#define U2C1_UART2_INT_TXEMPTY			(0 << 4)
#define U2C1_UART2_INT_TXCOMPLETE		(1 << 4)

#define U2C1_UART2_CONTINUOUS_RECEIVE	(1 << 5)

/* UART2 transmit buffer register */
#pragma ADDRESS SFR_U2TB				037aH
SFR16_t SFR_U2TB;
#define U2TB							SFR_U2TB.uiAll
#define U2TBL							SFR_U2TB.structBytes.ucLow

/* UART2 receive buffer register */
#pragma ADDRESS SFR_U2RB				037eH
SFR16_t SFR_U2RB;
#define U2RB							SFR_U2RB.uiAll
#define U2RBL							SFR_U2RB.structBytes.ucLow

#define U2RB_ABT						SFR_U2RB.bits.b11 							
#define U2RB_OER						SFR_U2RB.bits.b12
#define U2RB_FER						SFR_U2RB.bits.b13
#define U2RB_PER						SFR_U2RB.bits.b14
#define U2RB_SUM						SFR_U2RB.bits.b15

/* UART2 special mode register (1) */
#pragma ADDRESS SFR_U2SMR				0377H
SFR8_t SFR_U2SMR;
#define U2SMR							SFR_U2SMR.all;

/* UART2 special mode register 2 */
#pragma ADDRESS SFR_U2SMR2				0376H
SFR8_t SFR_U2SMR2;			
#define U2SMR2							SFR_U2SMR2.all

/* UART2 special mode register 3 */
#pragma ADDRESS SFR_U2SMR3				0375H
SFR8_t SFR_U2SMR3;			
#define U2SMR3							SFR_U2SMR3.all

/* UART2 special mode register 4 */
#pragma ADDRESS SFR_U2SMR4				0374H
SFR8_t SFR_U2SMR4;			
#define U2SMR4							SFR_U2SMR4.all

/*******************************************************************************
 *              common definitions for all Serial IO interfaces                *
 ******************************************************************************/ 

/* Si/o control register */
#define SC_CLOCK_SOURCE_EXTERNAL		(0)
#define SC_CLOCK_SOURCE_F1SIO			((0 << 0) | (1 << 6))
#define SC_CLOCK_SOURCE_F2SIO			((0 << 0) | (1 << 6))
#define SC_CLOCK_SOURCE_F8SIO			((1 << 0) | (1 << 6))
#define SC_CLOCK_SOURCE_F32SIO			((2 << 0) | (1 << 6))

#define SC_SOUT_NORMAL					(1 << 2)
#define SC_SOUT_HIZ						(0 << 2)

#define SC_USE_SOUT_AND_CLK				(1 << 3)

#define SC_CLOCKPOLARITY_NORMAL			(0 << 4)
#define SC_CLOCKPOLARITY_INVERTED		(1 << 4)

#define SC_FORMAT_LSBFIRST				(0 << 5)
#define SC_FORMAT_MSBFIRST				(1 << 5)

#define SC_SOUT_LOW						(0 << 7)
#define SC_SOUT_HIGH					(1 << 7)  

/*******************************************************************************
 *              serial input/output peripheral 3                               *
 ******************************************************************************/ 

/* Si/o3 interrupt control register (62) */
#pragma ADDRESS SFR_S3IC				0049H
SFR8_t SFR_S3IC;
#define S3IC							SFR_S3IC.all
#define S3IC_IR							SFR_S3IC.bits.b3

/* Si/o3 transmit/receive register (62) */
#pragma ADDRESS SFR_S3TRR				0360H
SFR8_t SFR_S3TRR;
#define S3TRR							SFR_S3TRR.all

/* Si/o3 control register (62) */
#pragma ADDRESS SFR_S3C					0362H
SFR8_t SFR_S3C;
#define S3C								SFR_S3C.all

/* Si/o3 bit rate generator (62) */ 
#pragma ADDRESS SFR_S3BRG				0363H
SFR8_t SFR_S3BRG;
#define S3BRG							SFR_S3BRG.all 

/*******************************************************************************
 *              serial input/output peripheral 4                               *
 ******************************************************************************/ 

/* Si/o4 interrupt control register (62) */
#pragma ADDRESS SFR_S4IC				0048H
SFR8_t SFR_S4IC;
#define S4IC							SFR_S4IC.all
#define S4IC_IR							SFR_S3IC.bits.b3

/* Si/o4 transmit/receive register (62) */
#pragma ADDRESS SFR_S4TRR				0364H
SFR8_t SFR_S4TRR;
#define S4TRR							SFR_S4TRR.all

/* Si/o4 control register (62) */
#pragma ADDRESS SFR_S4C					0366H
SFR8_t SFR_S4C;
#define S4C								SFR_S4C.all

/* Si/o4 bit rate generator (62) */ 
#pragma ADDRESS SFR_S4BRG				0367H
SFR8_t SFR_S4BRG;
#define S4BRG							SFR_S4BRG.all 

/*******************************************************************************
 *                          Key input interrupt unit                           *
 ******************************************************************************/ 

/* Key input interrupt control register */
#pragma ADDRESS SFR_KUPIC				004dH
SFR8_t SFR_KUPIC;
#define KUPIC							SFR_KUPIC.all
#define KUPIC_IR						SFR_KUPIC.bits.b3

/*******************************************************************************
 *                 Analog-to-digital converter peripheral                      *
 ******************************************************************************/ 

/* A-D conversion interrupt control register */
#pragma ADDRESS SFR_ADIC				004eH
SFR8_t SFR_ADIC;
#define ADIC							SFR_ADIC.all
#define ADIC_IR							SFR_ADIC.bits.b3

/* A-D control register 0 */ 
#pragma ADDRESS SFR_ADCON0				03d6H
SFR8_t SFR_ADCON0;
#define ADCON0							SFR_ADCON0.all

#define ADCON0_CHANNEL(n)				(n & 0x7)

#define ADCON0_MODE_ONESHOT				(0 << 2)
#define ADCON0_MODE_REPEAT				(1 << 2)
#define ADCON0_MODE_SINGLE_SWEEP		(2 << 2)
#define ADCON0_MODE_REPEAT_SWEEP0		(3 << 2)
#define ADCON0_MODE_REPEAT_SWEEP1		(3 << 2)

#define ADCON0_TRIGGER_SW				(0 << 5)
#define ADCON0_TRIGGER_ADTRG			(1 << 5)

#define ADCON0_CONVERSION_START			(1 << 6)
#define ADCON0_ADST						SFR_ADCON0.bits.b6

#define ADCON0_CKS0						(1 << 7)

/* A-D control register 1 */ 
#pragma ADDRESS SFR_ADCON1				03d7H
SFR8_t SFR_ADCON1;
#define ADCON1							SFR_ADCON1.all

#define ADCON1_SWEEP0_AN0_TO_AN1		(0 << 0)
#define ADCON1_SWEEP0_AN0_TO_AN3		(1 << 0)
#define ADCON1_SWEEP0_AN0_TO_AN5		(2 << 0)
#define ADCON1_SWEEP0_AN0_TO_AN7		(3 << 0)
#define ADCON1_SWEEP1_AN0_ONLY			(0 << 0)
#define ADCON1_SWEEP1_AN0_TO_AN1		(1 << 0)
#define ADCON1_SWEEP1_AN0_TO_AN2		(2 << 0)
#define ADCON1_SWEEP1_AN0_TO_AN3		(3 << 0)

#define ADCON1_MODE_REPEAT_SWEEP1		(1 << 2)

#define ADCON1_RESOLUTION_8BITS			(0 << 3)
#define ADCON1_RESOLUTION_10BITS		(1 << 3)

#define ADCON1_CKS1						(1 << 4)

#define ADCON1_VREF_CONNECTED			(1 << 5)

#define ADCON1_ANEX_OFF					(0 << 6)
#define ADCON1_ANEX_CONVERT_ANEX0		(1 << 6)
#define ADCON1_ANEX_CONVERT_ANEX1		(2 << 6)
#define ADCON1_ANEX_EXTOPA				(3 << 6)


/* A-D control register 2 */ 
#pragma ADDRESS SFR_ADCON2				03d4H
SFR8_t SFR_ADCON2;
#define ADCON2							SFR_ADCON2.all

#define ADCON2_METHOD_NOSH				(0 << 0)
#define ADCON2_METHOD_SH				(1 << 0)

#define ADCON2_GROUP_P10				(0 << 1)
#define ADCON2_GROUP_P0					(2 << 1)
#define ADCON2_GROUP_P2					(3 << 1)

#define ADCON2_CKS2						(1 << 4)
 
/* A-D registers 0 to 7 */
#pragma ADDRESS AD0						03c0H
unsigned int AD0;
#pragma ADDRESS AD0L					03c0H
unsigned char AD0L;

#pragma ADDRESS AD1						03c2H
unsigned int AD1;
#pragma ADDRESS AD1L					03c2H
unsigned char AD1L;

#pragma ADDRESS AD2						03c4H
unsigned int AD2;
#pragma ADDRESS AD2L					03c4H
unsigned char AD2L;

#pragma ADDRESS AD3						03c6H
unsigned int AD3;
#pragma ADDRESS AD3L					03c6H
unsigned char AD3L;

#pragma ADDRESS AD4						03c8H
unsigned int AD4;
#pragma ADDRESS AD4L					03c8H
unsigned char AD4L;

#pragma ADDRESS AD5						03caH
unsigned int AD5;
#pragma ADDRESS AD5L					03caH
unsigned char AD5L;

#pragma ADDRESS AD6						03ccH
unsigned int AD6;
#pragma ADDRESS AD6L					03ccH
unsigned char AD6L;

#pragma ADDRESS AD7						03ceH
unsigned int AD7;
#pragma ADDRESS AD7L					03ceH
unsigned char AD7L;

/*******************************************************************************
 *                 Digital-to-analog converter peripheral                      *
 ******************************************************************************/ 

/* DAC control register */
#pragma ADDRESS SFR_DACON				03dcH 
SFR8_t SFR_DACON;
#define DACON							SFR_DACON.all

#define DACON_DA0OUT_ENABLE				(1 << 0)
#define DACON_DA1OUT_ENABLE				(1 << 1)

/* DAC register 0 */
#pragma ADDRESS DA0						03d8H 
unsigned char DA0;

/* DAC register 1 */
#pragma ADDRESS DA1						03daH 
unsigned char DA1;

/*******************************************************************************
 *                     CRC calculation peripheral                              *
 ******************************************************************************/ 

/* CRC data register */
#pragma ADDRESS CRCD					03bcH
unsigned int CRCD; 
/* CRC input register */
#pragma ADDRESS crcin					03beH 
unsigned char CRCIN;

/*******************************************************************************
 *                            DMA controller                                   *
 ******************************************************************************/ 

/* DMA0 source pointer */
#pragma ADDRESS SFR_SAR0				0020H
SFR20_t SFR_SAR0;
#define SAR0							SFR_SAR0.ulAll
#define SAR0W							SFR_SAR0.structWords.uiLow

 /* DMA0 destination pointer */
#pragma ADDRESS SFR_DAR0				0024H
SFR20_t SFR_DAR0;
#define DAR0							SFR_DAR0.ulAll
#define DAR0W							SFR_DAR0.structWords.uiLow
  
/* DMA0 transfer counter */
#pragma ADDRESS TCR0					0028H
unsigned int TCR0;

/* DMA0 control register */
#pragma ADDRESS SFR_DM0CON				002cH
SFR8_t SFR_DM0CON;
#define DM0CON							SFR_DM0CON.all

#define DMCON_UNIT_16BITS				(0 << 0)
#define DMCON_UNIT_8BITS				(1 << 0)

#define DMCON_TRANSFER_SINGLE			(0 << 1)
#define DMCON_TRANSFER_REPEAT			(1 << 1)

#define DMCON_DMA_REQUEST				(1 << 2)

#define DMCON_DMA_DISABLE				(0 << 3)
#define DMCON_DMA_ENABLE				(1 << 3)

#define DMCON_SOURCE_ADDRESS_FIXED		(0 << 4)
#define DMCON_SOURCE_ADDRESS_INC		(1 << 4)

#define DMCON_DEST_ADDRESS_FIXED		(0 << 5)
#define DMCON_DEST_ADDRESS_INC			(1 << 5)

/* DMA0 interrupt control register */
#pragma ADDRESS SFR_DM0IC				004bH
SFR8_t SFR_DM0IC;
#define DM0IC							SFR_DM0IC.all

/* DMA0 cause select register */
#pragma ADDRESS SFR_DM0SL				03b8H
SFR8_t SFR_DM0SL;
#define DM0SL							SFR_DM0SL.all

#define DM0SL_INT0_FALLING				0x00
#define DM0SL_SOFTWARE					0x01
#define DM0SL_TA0						0x02
#define DM0SL_TA1						0x03
#define DM0SL_TA2						0x04
#define DM0SL_TA3						0x05
#define DM0SL_TA4						0x06
#define DM0SL_TB0						0x07
#define DM0SL_TB1						0x08
#define DM0SL_TB2						0x09
#define DM0SL_UART0_TX					0x0A
#define DM0SL_UART0_RX					0x0B
#define DM0SL_UART2_TX					0x0C
#define DM0SL_UART2_RX					0x0D
#define DM0SL_ADC						0x0E
#define DM0SL_UART1_TX					0x0F
#define DM0SL_INT0_CHANGE				0x46
#define DM0SL_TB3						0x47
#define DM0SL_TB4						0x48
#define DM0SL_TB5						0x49
 
#define DMSL_TRIGGER					(1 << 7)

/* DMA1 source pointer */
#pragma ADDRESS SFR_SAR1				0030H
SFR20_t SFR_SAR1;
#define SAR1							SFR_SAR1.ulAll
#define SAR1W							SFR_SAR1.structWords.uiLow

 /* DMA1 destination pointer */
#pragma ADDRESS SFR_DAR1				0034H
SFR20_t SFR_DAR1;
#define DAR1							SFR_DAR1.ulAll
#define DAR1W							SFR_DAR1.structWords.uiLow
  
/* DMA1 transfer counter */
#pragma ADDRESS TCR1					0038H
unsigned int TCR1;

/* DMA1 control register */
#pragma ADDRESS SFR_DM1CON				003cH
SFR8_t SFR_DM1CON;
#define DM1CON							SFR_DM1CON.all

/* DMA1 interrupt control register */
#pragma ADDRESS SFR_DM1IC				004cH
SFR8_t SFR_DM1IC;
#define DM1IC							SFR_DM1IC.all

/* DMA1 cause select register */
#pragma ADDRESS SFR_DM1SL				03baH
SFR8_t SFR_DM1SL;
#define DM1SL							SFR_DM1SL.all

#define DM1SL_INT1_FALLING				0x00
#define DM1SL_SOFTWARE					0x01
#define DM1SL_TA0						0x02
#define DM1SL_TA1						0x03
#define DM1SL_TA2						0x04
#define DM1SL_TA3						0x05
#define DM1SL_TA4						0x06
#define DM1SL_TB0						0x07
#define DM1SL_TB1						0x08
#define DM1SL_TB2						0x09
#define DM1SL_UART0_TX					0x0A
#define DM1SL_UART0_RX					0x0B
#define DM1SL_UART0_ACK					DM1SL_UART0_RX
#define DM1SL_UART2_TX					0x0C
#define DM1SL_UART2_RX					0x0D
#define DM1SL_UART2_ACK					DM1SL_UART2_RX
#define DM1SL_ADC						0x0E
#define DM1SL_UART1_RX					0x0F
#define DM1SL_UART1_ACK					DM1SL_UART1_RX
#define DM1SL_SIO3						0x45
#define DM1SL_SIO4						0x46
#define DM1SL_INT1_CHANGE				0x47

/*******************************************************************************
 *                          Watchdog timer                                     *
 ******************************************************************************/ 

/* Watchdog timer start register */
#pragma ADDRESS WDTS					000eH
unsigned char WDTS; /* write something to this register to start watchdog */
 
/* Watchdog timer control register */
#pragma ADDRESS SFR_WDC					000fH
SFR8_t SFR_WDC;
#define WDC								SFR_WDC.all

#define WDC_PRESCALER_DIV16				(0 << 7)
#define WDC_PRESCALER_DIV128			(1 << 7)

#define WDC_WARM_START					(1 << 5)

#define WDC_HIGHBITS					((WDC) & 0x1F) 						 

/*******************************************************************************
 *                          Watchdog timer                                     *
 ******************************************************************************/ 

/* Addrese match interrupt enable register */
#pragma ADDRESS SFR_AIER				0009H
SFR8_t SFR_AIER;
#define AIER							SFR_AIER.all

#define AIER_AIE0_ENABLE				(1 << 0)
#define AIER_AIE1_ENABLE				(1 << 1)

/* Addrese match interrupt enable register 2 */
#pragma ADDRESS SFR_AIER2				01bbH
SFR8_t SFR_AIER2;
#define AIER2							SFR_AIER2.all

#define AIER2_AIE2_ENABLE				(1 << 0)
#define AIER2_AIE3_ENABLE				(1 << 1)

/* Address match interrupt register 0 */
#pragma ADDRESS SFR_RMAD0				0010H
SFR20_t SFR_RMAD0;
#define RMAD0							SFR_RMAD0.ulAll
#define RMAD0W							SFR_RMAD0.structWords.uiLow

/* Address match interrupt register 1 */
#pragma ADDRESS SFR_RMAD1				0014H
SFR20_t SFR_RMAD1;
#define RMAD1							SFR_RMAD1.ulAll
#define RMAD1W							SFR_RMAD1.structWords.uiLow
 
/* Address match interrupt register 2 */
#pragma ADDRESS SFR_RMAD2				01b8H
SFR20_t SFR_RMAD2;
#define RMAD2							SFR_RMAD2.ulAll
#define RMAD2W							SFR_RMAD2.structWords.uiLow

/* Address match interrupt register 3 */
#pragma ADDRESS SFR_RMAD3				01bcH
SFR20_t SFR_RMAD3;
#define RMAD3							SFR_RMAD3.ulAll
#define RMAD3W							SFR_RMAD3.structWords.uiLow

/*******************************************************************************
 *                          Protection unit                                    *
 ******************************************************************************/ 

/* Protect register */
#pragma ADDRESS SFR_PRCR				000aH 
SFR8_t SFR_PRCR;
#define PRCR							SFR_PRCR.all

#define PRCR_WE_CM0						(1 << 0)
#define PRCR_WE_CM1						(1 << 0)
#define PRCR_WE_CM2						(1 << 0)
#define PRCR_WE_PLC0					(1 << 0)
#define PRCR_WE_PCLKR					(1 << 0)

#define PRCR_WE_PM0						(1 << 1)
#define PRCR_WE_PM1						(1 << 1)
#define PRCR_WE_PM2						(1 << 1)
#define PRCR_WE_TB2SC					(1 << 1)
#define PRCR_WE_INVC0					(1 << 1)

#define PRCR_WE_PD9						(1 << 2)
#define PRCR_WE_S3C						(1 << 2)
#define PRCR_WE_S4C						(1 << 2)

#define PRCR_WE_VCR2					(1 << 3)
#define PRCR_WE_D4INT					(1 << 3)

/*******************************************************************************
 *                   Processor mode  and system control                        *
 ******************************************************************************/ 

/* Processor mode register 0 */
#pragma ADDRESS SFR_PM0					0004H 
SFR8_t SFR_PM0;
#define PM0								SFR_PM0.all

#define PM0_PMODE_SINGLECHIP			0
#define PM0_PMODE_MEMORYEXPANSION		1
#define PM0_PMODE_MICROPROCESSOR		3

#define PM0_BHE_WR						(0 << 2)
#define PM0_WRH_WRL						(1 << 2)

#define PM0_SW_RESET					(1 << 3)

#define PM0_MUXBUS_NONE					(0 << 4)
#define PM0_MUXBUS_CS1					(1 << 4)
#define PM0_MUXBUS_CS2					(2 << 4)
#define PM0_MUXBUS_ALL					(3 << 4)

#define PM0_P4LFUNC_ADDRESS				(0 << 6)
#define PM0_P4LFUNC_PORT				(1 << 6)

#define PM0_BCLK_OUTPUT_ENABLE			(0 << 7)
#define PM0_BCLK_OUTPUT_DISABLE			(1 << 7)

/* Processor mode register 1 */
#pragma ADDRESS SFR_PM1					0005H
SFR8_t SFR_PM1;
#define PM1								SFR_PM1.all

#define PM1_CS2_BLOCKA_DISABLE			(0 << 0)
#define PM1_CS2_BLOCKA_ENABLE			(1 << 0)

#define PM1_P3HFUNC_ADDRESS				(0 << 1)
#define PM1_P3HFUNC_PORT				(1 << 1)

#define PM1_WATCHDOG_MODE_INTERRUPT		(0 << 2)
#define PM1_WATCHDOG_MODE_RESET			(1 << 2)

#define PM1_MEXPAND_1M					(0 << 4)
#define PM1_MEXPAND_4M					(3 << 4)

#define PM1_IMEM_WAIT_STATES_0			(0 << 7)
#define PM1_IMEM_WAIT_STATES_1			(1 << 7)

/* Chip select control register */
#pragma ADDRESS SFR_CSR					0008H
SFR8_t SFR_CSR;
#define CSR								SFR_CSR.all

#define CSR_CS_ENABLE(n)				(1 << ((n) & 0x3))

#define CSR_CS_WAIT_STATES_1(n)			(1 << (((n) & 0x3) + 4))
#define CSR_CS_WAIT_STATES_0(n)			0

/* data bank register (62) */
#pragma ADDRESS SFR_DBR					000bH
SFR8_t SFR_DBR;
#define DBR								SFR_DBR.all

#define DBR_OFFSET_OFF					(0 << 2)
#define DBR_OFFSET_ON					(1 << 2)

#define	DBR_BANK(n)						(((n) & 0x7) << 3)				
 
/* System clock control register 0 */
#pragma ADDRESS SFR_CM0					0006H
SFR8_t SFR_CM0;
#define CM0								SFR_CM0.all

#define CM0_P57FUNC_PORT				(0 << 0)
#define CM0_P57FUNC_FC					(1 << 0)
#define CM0_P57FUNC_F8					(2 << 0)
#define CM0_P57FUNC_F32					(3 << 0)

#define CM0_WAITMODE_STOP_PCLOCK		(1 << 0)

#define CM0_XC_DRIVE_CAPACITY_LOW		(0 << 3)
#define CM0_XC_DRIVE_CAPACITY_HIGH		(1 << 3)

#define CM0_P8687FUNC_PORT				(0 << 4)
#define CM0_P8687FUNC_XC				(1 << 4)

#define CM0_MCLOCK_ON					(0 << 5)
#define CM0_MCLOCK_STOP					(1 << 5)

#define CM0_MCLOCK_DIV_OTHER			(0 << 6)
#define CM0_MCLOCK_DIV_8				(1 << 6)

#define CM0_SCLOCK_OTHER				(0 << 7)
#define CM0_SCLOCK_SUB_CLOCK			(1 << 7)									
 
/* System clock control register 1 */
#pragma ADDRESS SFR_CM1					0007H
SFR8_t SFR_CM1;
#define CM1								SFR_CM1.all

#define CM1_CLOCKS_ON					(0 << 0)
#define CM1_CLOCKS_STOP					(1 << 0)

#define CM1_SCLOCK_MAIN					(0 << 1)
#define CM1_SCLOCK_PLL					(1 << 1)

#define CM1_X_DRIVE_CAPACITY_LOW		(0 << 5)
#define CM1_X_DRIVE_CAPACITY_HIGH		(1 << 5)

#define CM1_MCLOCK_DIV1					(0 << 6)
#define CM1_MCLOCK_DIV2					(1 << 6)
#define CM1_MCLOCK_DIV4					(2 << 6)
#define CM1_MCLOCK_DIV16				(3 << 6)

#endif // SFR62_H
