progs_names = led_blink led_blink_pwm
current_flash_prog_name = led_blink_pwm

source_path = ./
hex_path = ./hex_progs/

progs=$(addprefix $(hex_path), $(progs_names))
hex_progs=$(progs:=.hex)

current_flash_prog=$(addprefix $(hex_path), $(current_flash_prog_name))
hex_flash=$(current_flash_prog:=.hex)

INC = ./include
INC_PARAMS=$(foreach d, $(INC), -I$d)

mcu_name = attiny13

CC=avr-gcc
CFLAGS=-Wall -Os -mmcu=$(mcu_name)

AVRDUDE=avrdude-v8.0

all: $(hex_progs)

$(hex_path)%.hex: %.o
	avr-objcopy -j .text -j .data -O ihex $< $@

%.o: $(source_path)%.c | $(hex_path)
	$(CC) $(INC_PARAMS) $< $(CFLAGS) -o $@

$(hex_path):
	mkdir -p $(hex_path)

flash: $(hex_flash)
	$(AVRDUDE) -p $(mcu_name) -c usbasp -e -U flash:w:$< -B4

clean:
	rm -f $(hex_path)*.hex
