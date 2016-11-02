CC ?= gcc

CFLAGS ?= -Wall -std=gnu99

INCDIR = ../lib
INCLUDES = $(addprefix -I, $(INCDIR))
EXEC = t_sigsuspend 
SRC = $(wildcard $(INCDIR)/*.c)

all: $(EXEC)

t_sigsuspend: t_sigsuspend.c
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ $@.c $(SRC) 

clean:
	rm -f $(EXEC)
