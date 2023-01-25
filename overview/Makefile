CC=gcc
CFLAGS=-g -Wall -std=c99

# assuming here a 1:1 mapping from c file to executable
SRCS = waste_time_forever.c memory_addresses.c write_file.c fifo_source.c fifo_sink.c
OBJS = $(patsubst %.c,%.o,$(SRCS))
CMDS = $(basename $(SRCS))

.PHONY: all
all: $(CMDS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(CMDS): %: %.o
	$(CC) $(CFLAGS) -o $@ $@.o

.PHONY: clean
clean:
	/bin/rm -f $(CMDS) $(OBJS)
