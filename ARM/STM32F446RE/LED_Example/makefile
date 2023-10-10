CC = arm-none-eabi-gcc

CFLAGS = -c -mcpu=$(MACH) -std=gnu11 -mthumb -Wall

LDFLAGS = -T Stm32F446_LS.ld -nostdlib -Wl,-Map=final.map

MACH = cortex-m4

all: main.o GPIO_prog.o RCC_prog.o STM32_F446reStartup.o final.elf

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@

GPIO_prog.o: GPIO_prog.c
	$(CC) $(CFLAGS) $^ -o $@

RCC_prog.o: RCC_prog.c
	$(CC) $(CFLAGS) $^ -o $@

STM32_F446reStartup.o : STM32_F446reStartup.c
	$(CC) $(CFLAGS) $^ -o $@

final.elf: main.o GPIO_prog.o RCC_prog.o STM32_F446reStartup.o
	$(CC) $(LDFLAGS) $^ -o $@

symtbl: final.elf
	arm-none-eabi-nm $^ > SymbolTable.txt

clean:
	rm -rf *.o *.elf *.map *.txt

load:
	openocd -f "F:\Learning\Courses\Embeded System\ARM\Amgad Samir\Online\Tools\OpenOCD\xpack-openocd-0.12.0-2\openocd\scripts\board\st_nucleo_f4.cfg"

