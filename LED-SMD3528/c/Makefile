CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = led-strip-smd3528.o
EXTRA_LIBS=-lwiringPi
CFLAGS=-std=c99

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

led-strip-smd3528: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

.PHONY: clean

clean:
	rm -f led-strip-smd3528 $(OBJ) 
