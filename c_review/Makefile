CC=gcc
CFLAGS=-g -Wall --std=c99

# assuming here a 1:1 mapping from c file to executable
SRCS = hello_world.c printf.c conditions.c arrays.c functions.c args.c pointers.c vla.c arrays2.c sizeof.c malloc.c
OBJS = $(patsubst %.c,%.o,$(SRCS))
CMDS = $(basename $(SRCS))

.PHONY: all
all: $(CMDS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(CMDS): %: %.o
	$(CC) $(CFLAGS) -o $@ $@.o

.PHONY: clean
clean:
	/bin/rm -f $(CMDS) $(OBJS)
