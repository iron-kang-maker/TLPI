CC ?= gcc

CFLAGS ?= -Wall -lrt -lpthread

INCDIR = ../lib
INCLUDES = $(addprefix -I, $(INCDIR))
EXEC = ptmr_sigev_signal ptmr_sigev_thread timed_read real_time
SRC = $(wildcard  $(INCDIR)/*.c) 

all: $(EXEC)

ptmr_sigev_signal: ptmr_sigev_signal.c 
	$(CC) $(INCLUDES) -o $@ $@.c $(SRC) $(CFLAGS)

ptmr_sigev_thread: ptmr_sigev_thread.c 
	$(CC) $(INCLUDES) -o $@ $@.c $(SRC) $(CFLAGS)

timed_read: timed_read.c 
	$(CC) $(INCLUDES) -o $@ $@.c $(SRC) $(CFLAGS)

real_time: real_time.c 
	$(CC) $(INCLUDES) -o $@ $@.c $(SRC) $(CFLAGS)

clean:
	rm $(EXEC)
