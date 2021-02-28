CC=gcc
CFLAGS= -Wall -std=c99
FILENAME=main
TARGET=x$(FILENAME)

all: *.c
#	$(CC) $(CFLAGS) -o $(TARGET) -lm  *.c

	make  $(TARGET).o 
	make  $(TARGET) 

$(TARGET).o : *.c
	$(CC) $(CFLAGS) -g -c *.c

$(TARGET): *.o
	$(CC) $(CFLAGS) *.o -o $(TARGET) -lm

clean:
	rm -rf *.o
	rm -rf $(TARGET)