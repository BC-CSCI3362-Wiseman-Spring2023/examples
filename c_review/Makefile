CC=gcc
CFLAGS=-g -Wall --std=c99

# assuming here a 1:1 mapping from c file to executable
SRCS = hello_world.c printf.c conditions.c arrays.c functions.c args.c pointers.c vla.c arrays2.c sizeof.c malloc.c functions2.c structs.c
OBJS = $(patsubst %.c,%.o,$(SRCS))
CMDS = $(basename $(SRCS))

SRCS2 = common.c userlist.c addusers.c
DEPS2 = common.h userlist.h
OBJS2 = $(patsubst %.c,%.o,$(SRCS2))
CMDS2 = addusers

.PHONY: all
all: $(CMDS) $(CMDS2)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(CMDS): %: %.o
	$(CC) $(CFLAGS) -o $@ $@.o

$(OBJS2): %.o: %.c $(DEPS2)
	$(CC) $(CFLAGS) -c -o $@ $<

$(CMDS2): %: $(OBJS2)
	$(CC) $(CFLAGS) -o $@ $(OBJS2)

.PHONY: clean
clean:
	/bin/rm -f $(CMDS) $(OBJS) $(CMDS2) $(OBJS2)
