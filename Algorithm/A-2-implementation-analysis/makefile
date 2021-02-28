CC=gcc
CFLAGS= -Wall -std=c99
FILENAME=main
TARGET=x$(FILENAME)

all: *.c
#	$(CC) $(CFLAGS) -o $(TARGET) -lm  *.c

	make -s $(TARGET).o # TODO: stop suppressing with -s logs and fix
	make -s $(TARGET) # TODO: stop suppressing logs with -s and fix

$(TARGET).o : *.c
	$(CC) $(CFLAGS) -g -c *.c

$(TARGET): *.o
	$(CC) $(CFLAGS) *.o -o $(TARGET) -lm

clean:
	rm -rf *.o
	rm -rf $(TARGET)