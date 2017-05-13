#ifndef SYSDEFS_H
#define SYSDEFS_H

/* datatype representing all system (not FSM!) inputs */
typedef union{
	struct{
		/* Mode switch: automatic = 1, manual = 0*/
		unsigned char mode_auto: 1;
		/* close request button for manual mode */                                         
		unsigned char button_close: 1;
		/* open request button for manual mode */
		unsigned char button_open: 1;
		/* unused */
		unsigned char _reserved1: 1;
		/* limit switch indicating door open when 1 */
		unsigned char limit_open: 1;
		/* limit switch indicating door closed when 1 */
		unsigned char limit_closed: 1;
		/* safety light barrier. 1 indicates that something is within the frame of the door. */  
		unsigned char lb_collision: 1;
		/* light barrier indicating open request for automatic mode ("wired OR" combination of both sides) */
		unsigned char lb_approximation: 1;
	}single;
	/* access all sensors at once */
	unsigned char all;
} Sensors_t;                         

/* datatype representing all system (not FSM!) outputs */
typedef union{
	struct{
		/* flashing warn lamp */ 
		unsigned char warn_lamp: 1;
		/* turn motor to close the door */
		unsigned char motor_close: 1;
		/* turn motor to open the door */
		unsigned char motor_open: 1;
		/* 5 user programmable LEDs for error status */
		unsigned char leds: 5; 
	} single;
	/* access all actuators at once */
	unsigned char all;
} Actuators_t;

/* Execution interval of state machine code in milliseconds. Can be used for timing calculations */ 
#define FSM_INTERVAL_MS		20 

#endif // SYSDEFS_H
