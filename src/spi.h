#ifndef SPI_H
#define SPI_H

/*! Access to SPI Hardware Port (SIO3) -> polling based, i.e. does not need interrupts 
 * enabled! 
 *
 * (based on implementation of Georg Müller, 
 * Hochschule Mittweida (FH) FB: Informations- und Elektrotechnik)
 */ 

// Module initialization
void SPI_Init(void);

/* Combined read and write single byte.
 * 
 * This is always done since an SPI device cannot be written without reading and vice versa.
 */ 
unsigned char SPI_ReadWriteByte(unsigned char byte);

// Read single byte
unsigned char SPI_ReadByte(void);

// write single byte 
void SPI_WriteByte(unsigned char byte);

#endif // SPI_H
