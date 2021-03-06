# define the compiler to use
CC=suncc
### flags
# -fast -xO3 -xO5 
CFLAGS=-g -fast -xopenmp -xvpara -xloopinfo -xtarget=ivybridge
LDFLAGS= -fast
LIBS = -lm -xopenmp
# macro: sources
SOURCES= main.c gaussseidel.c jacobi.c utils.c 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=poisson

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf poisson
