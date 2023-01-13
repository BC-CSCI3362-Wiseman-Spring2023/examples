CC=gcc
CFLAGS=-g -Wall

# assuming here a 1:1 mapping from c file to executable
SRCS = waste_time_forever.c memory_addresses.c
OBJS = $(patsubst %.c,%.o,$(SRCS))
CMDS = $(basename $(SRCS))

.PHONY: all
all: $(CMDS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(CMDS): %: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $@.o

.PHONY: clean
clean:
	/bin/rm -f $(CMDS) $(OBJS)
