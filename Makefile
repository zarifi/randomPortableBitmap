OFILES = random-pbm.o xmalloc.o
TARGET = random
CC = cc
CFLAGS = -Wall -pedantic -std=c99 -O2
$(TARGET): $(OFILES)
		$(CC) $(OFILES) -o $@

clean:
		rm -f $(OFILES) $(TARGET)

#This is the output of "gcc -MM":


random-pbm.o: random-pbm.c array.h
xmalloc.o: xmalloc.c xmalloc.h
