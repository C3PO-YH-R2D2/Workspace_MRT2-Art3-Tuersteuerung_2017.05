#include "spi.h"
#include "sfr62.h"

static unsigned char lastWrittenByte;

void SPI_Init(void){
	lastWrittenByte = 0;

	// Init SIO hardware and Port pins
	PUR2 |= PUR2_P9_0_TO_3;		
	PRCR = PRCR_WE_PD9;
	PD9 |= (1 << 0 /*CLK*/) | (1 << 2/* DOUT*/);
	PRCR = PRCR_WE_PD9;
	PD9 &= ~(1 << 1 /*DIN*/);
	
	PRCR = PRCR_WE_S3C;
	S3C = SC_CLOCK_SOURCE_F1SIO | SC_USE_SOUT_AND_CLK | SC_FORMAT_MSBFIRST | SC_SOUT_HIGH;	
	S3IC_IR = 0; // reset interrupt request flag
	
	S3BRG = 10; // clock source is external 16 MHz / 11 (= value set + 1)                        
}

unsigned char SPI_ReadWriteByte(unsigned char byte){	
	S3TRR = lastWrittenByte = byte;
	while(!S3IC_IR);	// Wait until operation has finished (interrupt request flag set)
	S3IC_IR = 0;		// reset interrupt request flag
	return S3TRR;
}

unsigned char SPI_ReadByte(void){
	return SPI_ReadWriteByte(lastWrittenByte);
}

void SPI_WriteByte(unsigned char byte){
	SPI_ReadWriteByte(byte);
}
