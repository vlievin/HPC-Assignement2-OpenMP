# define the compiler to use
CC=suncc
# flags
CFLAGS=-g #-O3
LDFLAGS=
# macro: sources
SOURCES= main.c gaussseidel.c utils.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=poisson

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf *.exe




# DO NOT DELETE
