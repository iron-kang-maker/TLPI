CC ?= gcc

CFLAGS ?= -Wall -std=gnu99

INCDIR = ../lib
INCLUDES = $(addprefix -I, $(INCDIR))
EXEC = t_fork fork_file_sharing fork_whos_on_first fork_sig_sync
SRC = $(wildcard $(INCDIR)/*.c)

all: $(EXEC)

t_fork: t_fork.c
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ $@.c $(SRC) 

fork_file_sharing: fork_file_sharing.c
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ $@.c $(SRC) 

fork_whos_on_first: fork_whos_on_first.c
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ $@.c $(SRC)

fork_sig_sync: fork_sig_sync.c
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ $@.c $(SRC)

clean:
	rm -f $(EXEC)
