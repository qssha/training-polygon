/*
 * attiny13 two led bliking using timer 
 */ 

#define F_CPU 1200000UL
#define LED1 PB0
#define LED2 PB4
#define BUTTON PB1

#include <avr/io.h>     
#include <inttypes.h>
#include <util/delay.h> 
#include <avr/interrupt.h>

ISR(TIM0_COMPA_vect)
{
	PORTB ^= (1 << LED1);
	PORTB ^= (1 << LED2);
}

int main(void)
{
	DDRB |= (1 << LED1);
	DDRB |= (1 << LED2);

	PORTB |= (1 << LED1); 
	PORTB &= ~(1 << LED2);

	TCCR0A = 0x02; // режим подсчета импульсов (сброс при совпадении)
	TCCR0B = (1 << CS02) | (0 << CS01) | (1 << CS00); // предделитель clk/1024 (101)
	TCNT0 = 0x00; // начальное значение счётчика импульсов
	OCR0A = 0xFF; // максимальный предел счета (0-255)
	TIMSK0 |= (1 << OCIE0A); // разрешение прерывания по совпадению со значением регистра OCR0A
  
	sei(); // Разрешаем прерывания глобально: SREG |= (1<<SREG_I)

    while (1) 
    {
    }
}
