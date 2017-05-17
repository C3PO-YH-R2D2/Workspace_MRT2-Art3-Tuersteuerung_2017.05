/*
 * Praktikum MRT2 
 * ART3 Türsteuerung
 * Institut für Automatisierungstechnik
 * letztes Update Mai 2017
 * Autor: M.Herhold
 */

#include "DoorInterface.h"
#include "DoorControl.h"
#define closedoor 5

bool abbruch = false;
int modus = 0;
int z_mode = 0;
int z_mode_old = 0;
bool zeit = false;
bool vorgangoeffnen = false;
bool abbruch = false;
bool merkers = false;
bool merkero = false;

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
} eingaenge;

struct out {					//Ausgangsstruktur
	bool Y1;
	bool Y2;
	bool Y3;
} ausgaenge ;

bool einlesen(){  					// eingabewerte einlesen und in Struktur einarbeiten
	int ioinput;
	int zaehler=0;
	DoorInterface interface;
	interface.DIO_Read(&ioinput);
	eingaenge.S1=(ioinput & 1);

	ioinput= ioinput>>1;
	eingaenge.S2=(ioinput & 1);

	ioinput= ioinput>>1;
	eingaenge.E1=(ioinput & 1);

	ioinput= ioinput>>1;
	eingaenge.E2=(ioinput & 1);

	ioinput= ioinput>>1;
	eingaenge.X1=(ioinput & 1);

	ioinput= ioinput>>1;
	eingaenge.X2=(ioinput & 1);

	ioinput= ioinput>>1;
	eingaenge.LS1=(ioinput & 1);

	ioinput= ioinput>>1;
	eingaenge.X3=(ioinput & 1);

	ioinput= ioinput>>1;
	eingaenge.LS2=(ioinput & 1);

	ioinput= ioinput>>1;
	eingaenge.BE=(ioinput & 1);

	ioinput= ioinput>>1;
	eingaenge.B=(ioinput & 1);

	ioinput= ioinput>>1;

	if (ioinput<=32){
		return false;
	}
	return true;
}

bool ausgeben(){						//Ausgabewerte aus Struktur auslesen und an Funktion übergeben.
	long int output=0;
	output=ausgaenge.Y3;
	output=output<<1;
	output= output | ausgaenge.Y2;
	output=output<<1;
	output= output | ausgaenge.Y1;
	DoorInterface interface;
	interface.DIO_Write(output);
	return true;
}

int modi() {
	int vorgang=0;
	int zustand=0;
	if (!eingaenge.S1 && !eingaenge.S2) // Automatikbetrieb
	{
		vorgang++;
		zustand = 0;
		printf("Automatikbetrieb");
	}
	if (!eingaenge.S1 && eingaenge.S2) // Handbetrieb
	{
		vorgang++;
		zustand = 1;
		printf("Handbetrieb");
	}
	if (eingaenge.S1 && !eingaenge.S2)	// Reparatur
	{
		vorgang++;
		zustand=2;
		printf("Reparatur");
	}
	if (eingaenge.S1 && eingaenge.S2) // PST_AUS
	{
		vorgang++;
		zustand = 3;
		printf("Prozesssteuerung aus");
	}
	if (vorgang>1)
	{
		return 127;
	}
	return zustand;
}

int betriebszustand () {
	if (abbruch)
	{
		printf("Fehler! abbruch");
	}
	else {
		if (modus==0)
		{
		if(eingaenge.BE && eingaenge.B && eingaenge.LS1 && eingaenge.LS2 && eingaenge.X3 && eingaenge.X2 && !eingaenge.X1 && !zeit){
			return 1;//zeitveroegerung
		}
		if(eingaenge.BE && eingaenge.B && eingaenge.LS1 && eingaenge.LS2 && eingaenge.X3 && eingaenge.X2 && !eingaenge.X1 && zeit){
			return 2;//schliessen
		}
		if(eingaenge.BE && eingaenge.B && eingaenge.LS1 && eingaenge.LS2 && !eingaenge.X3 && !eingaenge.X2 && !vorgangoeffnen){
			return 3;//geschlossen
		}
		if(((!eingaenge.BE || !eingaenge.B || !eingaenge.LS1 || !eingaenge.LS2) && eingaenge.X1)||(vorgangoeffnen && eingaenge.X1)) {
			return 4;//oeffnen
		}
		if((!eingaenge.BE || !eingaenge.B || !eingaenge.LS1 || !eingaenge.LS2) && !eingaenge.X1) {
			return 5;//offen
		}
		return 6;
		}
		if (modus == 1){
		if(!eingaenge.E1 && eingaenge.E2 && eingaenge.X3){
			return 2;//schliessen
		}
		if(eingaenge.E2 && !eingaenge.X3){
			return 3;//geschlossen
		}
		if( !eingaenge.E2 && eingaenge.X1){
			return 4;//oeffnen
		}
		if( !eingaenge.E2 && !eingaenge.X1){
			return 5;//geoffnet
		}
		return 6; //fehlerfall
		}

	}
	return 0; //PST Aus
}

void steuern(){
	printf("Betriebszustand: %d",z_mode);
	DoorInterface interface;
	switch (z_mode) {
	case 0: {							//PST_AUS
		ausgaenge.Y1=false;
		ausgaenge.Y2=false;
		ausgaenge.Y3=false;
		bool test=ausgeben();
		vorgangoeffnen=false;
		zeit=false;
		break;
	}
	case 1: {							//zeitveroegerung
		int h = interface.StartTimer(closedoor);
		zeit=true;
		break;
	}
	case 2: {							//schliessen
		ausgaenge.Y1=false;
		ausgaenge.Y2=true;
		ausgaenge.Y3=true;
		bool test=ausgeben();
		vorgangoeffnen=false;
		//zeit=false;
		break;
	}
	case 3: {							//geschlossen
		ausgaenge.Y1=false;
		ausgaenge.Y2=false;
		ausgaenge.Y3=false;
		bool test=ausgeben();
		vorgangoeffnen=false;
		zeit=false;
		break;
	}
	case 4: {							//oeffnen
		ausgaenge.Y1=true;
		ausgaenge.Y2=false;
		ausgaenge.Y3=false;
		bool test=ausgeben();
		zeit=false;
		vorgangoeffnen=true;
		break;
	}
	case 5: {							//offen
		ausgaenge.Y1=false;
		ausgaenge.Y2=false;
		ausgaenge.Y3=false;
		bool test=ausgeben();
		vorgangoeffnen=false;
		zeit=false;
		break;
	}
	case 6: {							//fehler
		ausgaenge.Y1=false;
		ausgaenge.Y2=false;
		ausgaenge.Y3=false;
		bool test=ausgeben();
		vorgangoeffnen=false;
		printf("Fehler! Programmabbruch");
		z_mode=0;
		z_mode_old=0;
		modus=0;
		abbruch=true;
		zeit=false;
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

    while(!abbruch){
	    	//int timer = interface.StartTimer(0.05); //set Timer
	    	bool okl = einlesen();
	    	modus = modi();
	    	abbruch = (okl);
	    	z_mode = betriebszustand();
	    	
	    }
	
	return 0;
}