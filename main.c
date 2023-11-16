/*
 * OLED_I2C_Atmega8.c
 *
 * Created: 30-10-2023 20:42:32
 * Author : naval
 */ 
#ifndef F_CPU
#define F_CPU	16000000UL
#endif

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "i2cnaval.c"
#include "i2c_oled_SSD1306.c"


int main(void)
{
	/* Replace with your application code */
	char x = 0,str[5];
	DDRD = 0xFF;
	PORTD = 0x00;

	lcd_init(LCD_DISP_ON);
	_delay_ms(10);
	
	lcd_puts("Hello World");
	_delay_ms(4000);
	lcd_clrscr();

	lcd_puts("Temp ");
	_delay_ms(10);
	while (1)
	{
		PORTD = 0x00;
		_delay_ms(500);
		PORTD = 0xff;
		_delay_ms(500);
		lcd_gotoxy(0,3);
		sprintf(str,"%d °C",x);
		lcd_puts(str);
		x++;
		if(x==255)
		{
			lcd_clrscr();
			x=0;
		}
		
	}
}
