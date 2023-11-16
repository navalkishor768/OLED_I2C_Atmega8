/*
 * i2cnaval.h
 *
 * Created: 29/10/2023 06:46 PM
 *  Author: Navalkishor Kumawat
 */ 


#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
#include <string.h>


//Function To Initialize the I2C Module
void i2c_init();

//Function to start i2c
void i2c_start(void);

//Function to write a unsigned char on i2c bus
void i2c_write(unsigned char data);

//Function to stop i2c bus
void i2c_stop();

#endif /* I2C_H_ */
