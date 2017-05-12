/*
 * Praktikum MRT2 
 * ART3 Türsteuerung
 * Institut für Automatisierungstechnik
 * letztes Update Mai 2017
 * Autor: M.Herhold
 */

#include "DoorInterface.h"
#include "DoorControl.h"


DoorControl::DoorControl() : door_if(false, true)
{
	door_if.SecondLevelInit();
}

DoorControl::~DoorControl()
{
	door_if.quit_doorcontrol_flag = true;
}

void DoorControl::run()
{
	int i = 50;
	
	door_if.DebugString("Please wait 10 Seconds for auto exit, or press 'q'.");
	while( !door_if.quit_doorcontrol_flag && i-- ){
		door_if.StartTimer(0.2);
	}
}

/* If "show_ui" of class DoorInterface is active use "External Tools" -> run in xterm"
 * to execute from Eclipse IDE */
int main (int argc, char *argv[])
{
	// ... insert your class initialisation and loop code here ...
	// example start:

	DoorControl control;
	control.run();
	
	return 0;
}
