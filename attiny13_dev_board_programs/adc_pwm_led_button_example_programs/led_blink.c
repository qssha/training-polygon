/*
 * attiny13 board led blink
 */

#define F_CPU 1200000UL // 9.6 / 8 = 1.2 Mhz частота по-умолчанию
#define LED PB0

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

int main(void)
{

	DDRB |= (1 << LED);
	PORTB |= (1 << LED); // LED выключен так как подключен к VCC

	while (1) {
		_delay_ms (1000);    // задержка 1 секунда
		PORTB ^= (1 << LED); // инвертируем пин LED
	}
}
