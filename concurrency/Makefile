CC=gcc
CFLAGS=-g -Wall -std=c99

SRCS1 = pthreads.c mutex.c
DEPS1 = 
OBJS1 = $(patsubst %.c,%.o,$(SRCS1))
CMDS1 = $(basename $(SRCS1))
LIBS1 = -lpthread

SRCS2 = bbq.c bbq_test.c
DEPS2 = bbq.h
OBJS2 = $(patsubst %.c,%.o,$(SRCS2))
CMDS2 = bbq_test
LIBS2 = -lpthread


.PHONY: all
all: $(CMDS1) $(CMDS2)

$(OBJS1): %.o: %.c $(DEPS1)
	$(CC) $(CFLAGS) -c -o $@ $<

$(CMDS1): %: $(OBJS1)
	$(CC) $(CFLAGS) -o $@ $@.o $(LIBS1)

$(OBJS2): %.o: %.c $(DEPS2)
	$(CC) $(CFLAGS) -c -o $@ $<

$(CMDS2): %: $(OBJS2)
	$(CC) $(CFLAGS) -o $@ $(OBJS2) $(LIBS2)

.PHONY: clean
clean:
	/bin/rm -f $(CMDS1) $(OBJS1) $(CMDS2) $(OBJS2)
