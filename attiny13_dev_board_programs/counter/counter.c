/*
 * attiny13 counter
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <util/delay.h>

#define F_CPU 1200000UL

#define LED0 PB4 

#define BUTTON PB1

volatile uint8_t counter = 0;

// По умолчанию сброс счетчика при значении 2
uint8_t counter_limit = 2;

// обработчик прерываний INT0
ISR(INT0_vect)
{
	_delay_ms (50); // антидребезг кнопки

	counter++;
	if (counter >= counter_limit) {
		PORTB &= ~(1 << LED0);
		_delay_ms (2000);
		PORTB |= (1 << LED0);
		counter = 0;
	}
}

int main(void)
{
	// Светидиод:
	DDRB |= (1 << LED0); // выходы = 1
	PORTB |= (1 << LED0); // по умолчанию отключены
			
        DDRB &= ~(1 << BUTTON); // выставляем пин BUTTON на вход
	PORTB |= (1 << BUTTON);  // включаем подтягивание внутреннего резистора

	// Считывание максимального значения счетчика из внутренней памяти
	counter_limit = eeprom_read_byte(0);

	// Настройка прерывание INT0 по нарастающему фронту
	GIMSK |= (1 << INT0);
        MCUCR |= (1 << ISC00);
	MCUCR |= (1 << ISC01);

	sei(); //разрешаем глобально прерывания
  
	while(1)
	{
	}
}
