/*
 * attiny13 board change led status by button interrupt
 */

#define LED PB0
#define BUTTON PB1

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// обработчик прерываний PCINT0
ISR(PCINT0_vect)
{
	_delay_ms (50); // антидребезг кнопки
	if ((PINB & (1 << BUTTON)) == 0)
	{
	PORTB ^= (1 << LED);
	while ((PINB & (1 << BUTTON)) == 0 ) {}
	}
}

int main(void)
{
	DDRB |= (1 << LED);
	PORTB |= (1 << LED); // LED выключен так как подключен к VCC

	DDRB &= ~((1 << BUTTON)); // выставляем пин BUTTON на вход
	PORTB |= (1 << BUTTON);  // включаем подтягивание внутреннего резистора

	GIMSK |= (1 << PCIE); // включить внешние прерывания enable external interrupt
	PCMSK |= (1 << BUTTON); // включить прерывание по пину BUTTON
	sei(); // SREG |= (1 << SREG_I) - включить прерывания глобально

	while (1)
	{
	}
}
