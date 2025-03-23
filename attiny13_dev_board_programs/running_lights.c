/*
 * attiny13 running lights
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 1200000UL

#define LED0 PB0 
#define LED1 PB1 

#define BUTTON PB2

volatile _Bool direction = 0; // Направление бегущего огонька

// обработчик прерываний PCINT0
ISR(PCINT0_vect)
{
	_delay_ms (50); // антидребезг кнопки
	if ((PINB & (1 << BUTTON)) == 0) 
	{
		direction = !direction;
	} 
	while ((PINB & (1 << BUTTON)) == 0) {} 
}

ISR(TIM0_COMPA_vect)
{
	static unsigned char light = 3;
	if (!direction) // прямое направление
	{
		if ((light > 0) & (light < 0x0c)) light <<= 1;
		else light = 0x03;
	}
	else // обратное направление
	{
		if (light > 0) light >>= 1;
		else light = 0x03;
	}
	PORTB = (PORTB & 0x3c) | (light & 0x3); // Подставляем в младшие 2 бита порта "B" значение переменной light, PORTB имеет 6 выставляемых битов, поэтому
						// используем маску 0x3c=00111100
}

int main(void)
{
	// Светидиоды:
	DDRB |= (1 << LED0) | (1 << LED1); // выходы = 1
	PORTB |= ((1 << LED0) | (1 << LED1)); // по умолчанию отключены

	// Настройка прерывания по кнопке BUTTON
	
	DDRB &= ~(1 << BUTTON); // выставляем пин BUTTON на вход
	PORTB |= (1 << BUTTON);  // включаем подтягивание внутреннего резистора

	GIMSK |= (1 << PCIE); // включить внешние прерывания enable external interrupt
	PCMSK |= (1 << BUTTON); // включить прерывание по пину BUTTON0

	// Настройка прерываний по счётчику/таймеру
	TCCR0A = 0x02; // режим подсчета импульсов (сброс при совпадении)
	TCCR0B = (1 << CS02) | (0 << CS01) | (1 << CS00); // предделитель clk/1024 (101)
	TCNT0 = 0x00; // начальное значение счётчика импульсов
	OCR0A = 0xFF; // максимальный предел счета (0-255)
	TIMSK0 |= (1 << OCIE0A); // разрешение прерывания по совпадению со значением регистра OCR0A
  
	sei(); //разрешаем глобально прерывания
  
	while(1)
	{
	}
}
