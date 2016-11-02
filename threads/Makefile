CC ?= gcc

CFLAGS ?= -Wall -std=gnu99 -lpthread

INCDIR = ../lib
INCLUDES = $(addprefix -I, $(INCDIR))
EXEC = simple_thread
SRC = $(wildcard $(INCDIR)/*.c)

all: $(EXEC)

simple_thread: simple_thread.c
	$(CC) $(INCLUDES) -o $@ $@.c $(SRC) $(CFLAGS)

clean:
	rm $(EXEC)
