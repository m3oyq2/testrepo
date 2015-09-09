PRG = MorseTest
AVRDUDE_TGT = t85
PROGRAMMER = avrispmkII
## Add more .o's here for further code files
OBJ = main.o libmorse.o 
MMCU = attiny85
CFLAGS = -Wall -ffreestanding -mmcu=$(MMCU) -g3 -O1 -std=c99
CFLAGS += -DF_CPU=$(F_CPU)
LDFLAGS = -Wl,-Map,$(PRG).map,--cref
LIBS =
CC = avr-gcc
OBJCOPY = avr-objcopy

## 1MHz Clock
F_CPU = 10000000

all: $(PRG).elf $(PRG).hex #doc


$(PRG).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

$(PRG).hex: $(PRG).elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@



clean:
	rm -rf *.o *.deps *.map *.elf *.hex ../doc

flash:
	avrdude -p $(AVRDUDE_TGT) -c $(PROGRAMMER) -e -P usb -U flash:w:$(PRG).hex

doc:
	doxygen $(PRG).doxyfile
commit: clean
	cd ../ && svn commit
