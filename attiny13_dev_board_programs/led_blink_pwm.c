/*
 * attiny13 led blinking with PWM 
 */ 

#define F_CPU 1200000UL
#define LED PB0 // OC0A

#include <avr/io.h>     
#include <inttypes.h>
#include <util/delay.h> 
#include <avr/interrupt.h>

int main(void)
{
	DDRB |= (1 << LED); // выходы = 1
	PORTB |= (1 << LED); // по умолчанию LED выключен так как подключен к VCC

	// Таймер для ШИМ:
	TCCR0A = 0x83; // режим ШИМ, неинверсный сигнал на выходе OC0A
	TCCR0B = 0x02; // предделитель тактовой частоты CLK/8

	TCNT0=0; // начальное значение счётчика
	OCR0A=255; // регистр совпадения A
  
	while(1)
	{
	do // Нарастание яркости
	{
		OCR0A--;
		_delay_ms(20);
	}
	while(OCR0A!=0);

	_delay_ms(1000); // Пауза 1 сек.

	do // Затухание
	{
		OCR0A++;
		_delay_ms(20);
	}
	while(OCR0A!=255);

	_delay_ms(1000); // Пауза 1 сек.
	}
}
