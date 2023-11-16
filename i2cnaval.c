/*
 * i2cnaval.c
 *  Author:Navalkishor Kumawat
 *  Created: 29/10/2023 06:50 PM
 */
#include <avr/io.h>
#include "i2cnaval.h"

void i2c_init(void)
{
	TWSR=0x00;
	TWBR=0x48;
	TWCR=0x00;

}

void i2c_start(void)
{
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
}

void i2c_write(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
	
}

unsigned char i2c_read(unsigned char ackVal)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(ackVal<<TWEA);
	while(!(TWCR & (1<<TWINT)));
	return TWDR;

}


void i2c_stop()
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	//for(int x=0;x<10;x++);	//wait for sometime
	_delay_ms(10);

}
