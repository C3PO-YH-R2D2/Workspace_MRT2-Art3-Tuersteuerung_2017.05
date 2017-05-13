#include "sfr62.h"
#include "utils.h"
#include "spi.h"

#include "fsm.h"

static void hwInit(){
	// do not allow interrupts while configuring system!
	disable_interrupts();
	
	// disable clock prescaler	
	PRCR = PRCR_WE_CM0;
	CM0 &= ~CM0_MCLOCK_DIV_8;
	PRCR = 0;
		
	// init SPI peripheral for communication with IO extension board
	SPI_Init();
	// configure chip select line on pin P1_3 (not managed by SPI peripheral)
	P1_3 = 1; // idle level 
	PD1_3 = PD_OUTPUT;
	
	// configure Timer A0	
	TA0MR = TAMR_MODE_TIMER | TAMR_CLOCK_SOURCE_F8;
	TA0 = (F_CPU / 8) / (1000 / FSM_INTERVAL_MS);
	UDF_TA0UD = UDF_COUNT_DOWN;
	TA0IC = IC_LEVEL(1);
	TABSR_TA0S = 1; // start Timer A0
	
	// System is now fully configured, allow interrupt processing		
	enable_interrupts();
}

volatile int timerExpiredFlag = 0;

#pragma INTERRUPT TimerA0_InterruptHandler
void TimerA0_InterruptHandler(void){
	timerExpiredFlag = 1;
}

static Sensors_t readWriteIO(Actuators_t actuators){
	Sensors_t sensors;

	P1_3 = 0;					// activate chip select line
	SPI_ReadWriteByte(0xFF);	// address of extension board
	sensors.all = SPI_ReadWriteByte(actuators.all);
	P1_3 = 1;                	// release chip select line
	
	return sensors;
}

void main(void){
	
	Sensors_t sensors;
	Actuators_t actuators = {{0}};
 
	hwInit();
	FSM_Init();
		
	while(1){
		if(timerExpiredFlag){
			timerExpiredFlag = 0;
			
			sensors = readWriteIO(actuators);
			
			actuators = FSM_Cycle(sensors);
			
			readWriteIO(actuators);
		}
	}
}
