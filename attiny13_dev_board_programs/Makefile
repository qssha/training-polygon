files = led_blink
current_prog_file = led_blink

hex_prog_path = ./hex_prog/
hex_prog=$(addprefix $(hex_prog_path), $(files))
hex_prog_prog=$(addprefix $(hex_prog_path), $(current_prog_file))

INC = ./include
INC_PARAMS=$(foreach d, $(INC), -I$d)

mcu_name = attiny13

CC=avr-gcc
CFLAGS=-Wall -Os -mmcu=$(mcu_name)

all: $(hex_prog).hex

$(hex_prog_path)%.hex: $(hex_prog).o
	avr-objcopy -j .text -j .data -O ihex $< $@

$(hex_prog_path)%.o: $(source_path)%.c | $(hex_prog_path)
	$(CC) $(INC_PARAMS) $< $(CFLAGS) -o $@

$(hex_prog_path):
	mkdir -p $(hex_prog_path)

prog: $(hex_prog_prog).hex
	 avrdude -p $(mcu_name) -c usbasp -e -U flash:w:$< -B4

clean:
	rm -rf $(hex_prog_path)
