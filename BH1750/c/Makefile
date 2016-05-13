CC=gcc
CFLAGS=-I.
DEPS =
OBJ = BH1750.o
EXTRA_LIBS=-lwiringPi

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

BH1750: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

.PHONY: clean

clean:
	rm -f BH1750 $(OBJ)
