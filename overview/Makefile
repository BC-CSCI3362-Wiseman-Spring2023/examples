CC=gcc
CFLAGS=-g -Wall -std=c99

# assuming here a 1:1 mapping from c file to executable
SRCS1 = waste_time_forever.c memory_addresses.c write_file.c fifo_source.c fifo_sink.c
OBJS1 = $(patsubst %.c,%.o,$(SRCS1))
CMDS1 = $(basename $(SRCS1))

SRCS2 = pthreads.c mutex.c
OBJS2 = $(patsubst %.c,%.o,$(SRCS2))
CMDS2 = $(basename $(SRCS2))
LIBS2 = -lpthread

.PHONY: all
all: $(CMDS1) $(CMDS2)

$(OBJS1): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(CMDS1): %: %.o
	$(CC) $(CFLAGS) -o $@ $@.o

$(OBJS2): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(CMDS2): %: %.o
	$(CC) $(CFLAGS) -o $@ $@.o $(LIBS2)

.PHONY: clean
clean:
	/bin/rm -f $(CMDS1) $(OBJS1) $(CMDS2) $(OBJS2)
