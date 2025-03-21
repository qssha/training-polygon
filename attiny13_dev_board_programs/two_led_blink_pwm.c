/*
 * attiny13 led blinking with PWM 
*/ 

#define F_CPU 1200000UL
#define LED1 PB0 // OC0A
#define LED2 PB1 // OC0B

#include <avr/io.h>     
#include <inttypes.h>
#include <util/delay.h> 
#include <avr/interrupt.h>

int main(void)
{
	DDRB |= ((1 << LED1) | (1 << LED2)); // выходы = 1
	PORTB |= (1 << LED1); // по умолчанию LED1 выключен так как подключен к VCC
	PORTB &= ~(1 << LED2); // по умолчанию LED2 включен так как подключен к VCC

	// Таймер для ШИМ:
	TCNT0=0; // начальное значение счётчика
	OCR0A=255; // регистр совпадения A
	OCR0B=0; // регистр совпадения B

	TCCR0A = 0xa1; // режим ШИМ с коррекцией фазы, неинверсный сигнал на выходах OC0A и OC0B
	TCCR0B = 0x02; // предделитель тактовой частоты CLK/8
  
	while(1)
	{
	_delay_ms(1000); // Пауза 1 сек.
	do // Нарастание яркости
	{
		OCR0A--;
		OCR0B++;
		_delay_ms(50);
	}
	while(OCR0A!=0);

	_delay_ms(1000); // Пауза 1 сек.

	do // Затухание
	{
		OCR0A++;
		OCR0B--;
		_delay_ms(50);
	}
	while(OCR0A!=255);

	}
}
