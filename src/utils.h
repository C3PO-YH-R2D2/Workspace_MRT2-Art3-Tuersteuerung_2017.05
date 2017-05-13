#ifndef BASEUTILS_H
#define BASEUTILS_H

// Verzögerung
#define nop() 					asm volatile("NOP")

// Interrupts global aktivieren
#define enable_interrupts()		do{ nop(); nop(); nop(); asm volatile("FSET I"); }while(0)

// Interrupts global deaktivieren
#define disable_interrupts()	asm volatile ("FCLR I")

// Taktfrequenz des Chips in Hz
#define F_CPU					16000000 

#endif // BASEUTILS_H
