/*
 * Praktikum MRT2 
 * ART3 Türsteuerung
 * Institut für Automatisierungstechnik
 * letztes Update Mai 2017
 * Autor: M.Herhold
 */

#include "DoorInterface.h"
#include "DoorControl.h"
#include <iostream>
using namespace std;
#define closetime 5

int modus = 0;
int state_mode_new = 0;
int state_mode_old = 0;
bool zeit = false;
bool vorgangoeffnen = false;
bool breakdown = false;
//bool merkers = false;
//bool merkero = false;

struct in {
	bool S1;
	bool S2;
	bool E1;
	bool E2;
	bool X1;
	bool X2;
	bool X3;
	bool LS1;
	bool LS2;
	bool BE;
	bool B;
} input;

struct out {					//Ausgangsstruktur
	bool Y1;
	bool Y2;
	bool Y3;
} output ;

bool senread(){  					// read sensor: eingabewerte einlesen und in Struktur einarbeiten
	int ioinput;
	DoorInterface interface;
	interface.DIO_Read(&ioinput);

	input.S1=(ioinput & 1);

	ioinput= ioinput>>1;
	input.S2=(ioinput & 1);

	ioinput= ioinput>>1;
	input.E1=(ioinput & 1);

	ioinput= ioinput>>1;
	input.E2=(ioinput & 1);

	ioinput= ioinput>>1;
	input.X1=(ioinput & 1);

	ioinput= ioinput>>1;
	input.X2=(ioinput & 1);

	ioinput= ioinput>>1;
	input.LS1=(ioinput & 1);

	ioinput= ioinput>>1;
	input.X3=(ioinput & 1);

	ioinput= ioinput>>1;
	input.LS2=(ioinput & 1);

	ioinput= ioinput>>1;
	input.BE=(ioinput & 1);

	ioinput= ioinput>>1;
	input.B=(ioinput & 1);

	ioinput= ioinput>>1;

	if (ioinput<=32){
		return false;
	}
	return true;
}

bool outwrite(){						//write output Ausgabewerte aus Struktur auslesen und an Funktion übergeben.
	long int op = 0;
	op = output.Y3;
	op = op<<1;
	op = op | output.Y2;
	op = op<<1;
	op = op | output.Y1;
	DoorInterface interface;
	interface.DIO_Write(op);
	return true;
}

int model() {
	int vorgang = 0;
	int state = 0;
	if (!input.S1 && !input.S2) // Automatikbetrieb
	{
		vorgang++;
		state = 0;
		cout<<"Automatikbetrieb"<<endl;
	}
	if (!input.S1 && input.S2) // Handbetrieb
	{
		vorgang++;
		state = 1;
		cout<<"Handbetrieb"<<endl;
	}
	if (input.S1 && !input.S2)	// Reparatur
	{
		vorgang++;
		state=2;
		cout<<"Reparatur"<<endl;
	}
	if (input.S1 && input.S2) // PST_AUS
	{
		vorgang++;
		state = 3;
		cout<<"Prozesssteuerung aus"<<endl;
	}
	if (vorgang>1)
	{
		return 127;
	}
	return state;
}

int betriebszustand () {
	if (breakdown)
	{
		cout<<"Error"<<endl;
	}
	else {
		if (modus==0)
		{
		if(input.BE&&input.B&&input.LS1&&input.LS2&&input.X3&&input.X2 && !input.X1 && !zeit){
			return 1;//zeitveroegerung
		}
		if(input.BE && input.B && input.LS1 && input.LS2 && input.X3 && input.X2 && !input.X1 && zeit){
			return 2;//schliessen
		}
		if(input.BE && input.B && input.LS1 && input.LS2 && !input.X3 && !input.X2 && !vorgangoeffnen){
			return 3;//geschlossen
		}
		if(((!input.BE || !input.B || !input.LS1 || !input.LS2) && input.X1)||(vorgangoeffnen && input.X1)) {
			return 4;//oeffnen
		}
		if((!input.BE || !input.B || !input.LS1 || !input.LS2) && !input.X1) {
			return 5;//offen
		}
		return 6;
		}
		if (modus == 1){
		if(!input.E1 && input.E2 && input.X3){
			return 2;//schliessen
		}
		if(input.E2 && !input.X3){
			return 3;//geschlossen
		}
		if( !input.E2 && input.X1){
			return 4;//oeffnen
		}
		if( !input.E2 && !input.X1){
			return 5;//geoffnet
		}
		return 6; //fehlerfall
		}

	}
	return 0; //PST Aus
}

void steuern(){
	printf("Betriebszustand: %d",state_mode_new);
	DoorInterface interface;
	switch (state_mode_new) {
	case 0: {							//PST_AUS
		output.Y1 = 0;
		output.Y2 = 0;
		output.Y3 = 0;
		bool test = outwrite();
		vorgangoeffnen = 0;
		zeit = 0;
		break;
	}
	case 1: {							//zeitveroegerung
		int h = interface.StartTimer(closetime);
		zeit = 1;
		break;
	}
	case 2: {							//schliessen
		output.Y1 = 0;
		output.Y2 = 1;
		output.Y3 = 1;
		bool test = outwrite();
		vorgangoeffnen = 0;
		//zeit=false;
		break;
	}
	case 3: {							//geschlossen
		output.Y1 = 0;
		output.Y2 = 0;
		output.Y3 = 0;
		bool test = outwrite();
		vorgangoeffnen = 0;
		zeit = 0;
		break;
	}
	case 4: {							//oeffnen
		output.Y1 = 1;
		output.Y2 = 0;
		output.Y3 = 0;
		bool test = outwrite();
		zeit = 0;
		vorgangoeffnen = 1;
		break;
	}
	case 5: {							//offen
		output.Y1 = 0;
		output.Y2 = 0;
		output.Y3 = 0;
		bool test = outwrite();
		vorgangoeffnen = 0;
		zeit = 0;
		break;
	}
	case 6: {							//fehler
		output.Y1 = 0;
		output.Y2 = 0;
		output.Y3 = 0;
		bool test = outwrite();
		vorgangoeffnen = 0;
		cout<<"Error"<<endl;
		state_mode_new = 0;
		state_mode_old = 0;
		modus = 0;
		breakdown = 1;
		zeit = 0;
		break;
	}
	}
}



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
    control.DoorControl();
    control.run();

    while(!breakdown){
	    	//int timer = interface.StartTimer(0.05); //set Timer
	    	bool readvalue = senread();
	    	modus = model();
	    	breakdown = (readvalue);
	    	state_mode_new = betriebszustand();
	    	if(state_mode_new!=state_mode_old){
	    		steuern();
	    	}
	    	state_mode_old = state_mode_new;
	    	if(breakdown){
	    		cout<<"Error"<<endl;
	    	}
	    }
	
	return 0;
}