CC ?= gcc

CFLAGS ?= -Wall -std=gnu99 -lpthread

INCDIR = ../lib
INCLUDES = $(addprefix -I, $(INCDIR))
EXEC += simple_thread \
		thread_incr \
		thread_multijoin \
		thread_cancel \
		thread_cleanup
SRC = $(wildcard $(INCDIR)/*.c)

all: $(EXEC)

simple_thread: simple_thread.c
	$(CC) $(INCLUDES) -o $@ $@.c $(SRC) $(CFLAGS)

thread_incr: thread_incr.c
	$(CC) $(INCLUDES) -o $@ $@.c $(SRC) $(CFLAGS)

thread_multijoin: thread_multijoin.c
	$(CC) $(INCLUDES) -o $@ $@.c $(SRC) $(CFLAGS)

thread_cancel: thread_cancel.c
	$(CC) $(INCLUDES) -o $@ $@.c $(SRC) $(CFLAGS)

thread_cleanup: thread_cleanup.c
	$(CC) $(INCLUDES) -o $@ $@.c $(SRC) $(CFLAGS)

clean:
	rm $(EXEC)
