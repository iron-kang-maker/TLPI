CC ?= gcc

CFLAGS ?= -Wall -std=gnu99

INCDIR = ../lib
INCLUDES = $(addprefix -I, $(INCDIR))
EXEC = t_fork
SRC = $(wildcard *.c $(INCDIR)/*.c) 

all: $(EXEC)

t_fork: t_fork.c 
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ $(SRC) 

clean:
	rm t_fork
