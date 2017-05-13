#include "fsm.h"

static enum {
	Mode_None,
	Mode_Manual, 
	Mode_Auto
} mode = Mode_None;

////////////////////////////////////////////////////////////////////////////////
// manual operation mode
////////////////////////////////////////////////////////////////////////////////

// TODO: define states for manual mode here

// TODO: define an input type for manual mode here

// TODO: insert FSM table for manual mode here

static Actuators_t doManualCycle(Sensors_t sensors, int doInit) {
	Actuators_t actuators;
		
	if(doInit) {
		// TODO: set initial state
	} 	

	// TODO: fill input structure
	
	// TODO: table based transition and output function	

		
	return actuators; 	
} 

////////////////////////////////////////////////////////////////////////////////
// automatic operation mode
////////////////////////////////////////////////////////////////////////////////

// states
typedef enum{
	// TODO: add states here
	
	Auto_Initial // = ?
} AutoState_t;

// These are the FSM inputs (do not mix up with system input type Sensors_t!)
typedef union {
	struct {		
		unsigned char lb: 1; 		// either approximation or collision (or both) light barriers triggered		
		unsigned char closed: 1;	// door is closed		
		unsigned char open: 1;		// door is open		
		unsigned char _reserved: 5;	// fill remaining bits to prevent compiler "optimization" writing garbage into them
	} single;
	unsigned char all;
} AutoInputs_t;

static const struct { 
	AutoState_t nextState;	
	Actuators_t output;
} autoTable[2][8] = {
	/************************************************************
	 *             |  inputs   ||                  |  outputs   *	
	 *             |   | c |   ||                  |   | motor  *
	 *             |   | l |   ||                  |   | c |    *
	 *             | o | o |   ||                  | l | l | o  *
	 *             | p | s |   ||                  | a | o | p  *
	 * current     | e | e | l ||                  | m | s | e  *
	 * state       | n | d | b || ->   next state, | p | e | n  * 
	 ***********************************************************/	 	 	 	 
	
	// TODO: add table here
};

#define DOOR_CLOSE_DELAY	(5000 / FSM_INTERVAL_MS) // wait 5 seconds before closing the door

static Actuators_t doAutoCycle(Sensors_t sensors, int doInit) {
	Actuators_t actuators;
	AutoInputs_t inputs;
	static AutoState_t state;
	static int closeDelayCounter;
		
	if(doInit) {
		closeDelayCounter = 0;
		state = Auto_Initial;
	} 
	
	// fill input structure
	inputs.all = 0;
	if(sensors.single.limit_open) inputs.single.open = 1;
	if(sensors.single.limit_closed) inputs.single.closed = 1;
	if(sensors.single.lb_approximation || sensors.single.lb_collision) inputs.single.lb = 1;
	
	// table based transition and output function	
	actuators = autoTable[state][inputs.all].output;
	state = autoTable[state][inputs.all].nextState;	
	
	// door close delay
	if(actuators.single.motor_close) {
		if(closeDelayCounter > 0) {
			closeDelayCounter--;
			actuators.single.motor_close = 0;
			actuators.single.warn_lamp = 0;
		} 
	} else closeDelayCounter = DOOR_CLOSE_DELAY;
		
	return actuators;
} 

////////////////////////////////////////////////////////////////////////////////
// Error Detection
////////////////////////////////////////////////////////////////////////////////

static unsigned char errorMask;

#define SENSOR_ERROR_DELAY (2000 / FSM_INTERVAL_MS) 

static unsigned char detectErrors(Sensors_t sensors, Actuators_t actuators) {
	unsigned char mask = 0;
	
	if(sensors.single.limit_open && sensors.single.limit_closed) mask |= 0x1;  

	// TODO: handle more errors here
	
	return mask;
}

////////////////////////////////////////////////////////////////////////////////
// Top Level State Machine
////////////////////////////////////////////////////////////////////////////////

void FSM_Init() {
	mode = Mode_None;
	errorMask = 0;
}

Actuators_t FSM_Cycle(Sensors_t sensors) {	
	Actuators_t actuators;
	if(sensors.single.mode_auto){
		// automatic operating mode
		actuators = doAutoCycle(sensors, (mode != Mode_Auto));
		mode = Mode_Auto;
	} else {
		// manual operating mode
		actuators = doManualCycle(sensors, (mode != Mode_Manual));
		mode = Mode_Manual;
	}

	// error detection	
	errorMask = detectErrors(sensors, actuators);
	if(errorMask) {
		actuators.single.leds = errorMask;
		actuators.single.motor_open = actuators.single.motor_close = 0;
		actuators.single.warn_lamp = 1;
		mode = Mode_None;
	}

	return actuators;
} 

// for simulator only
int FSM_GetCycleTime() {
	return FSM_INTERVAL_MS;
}
