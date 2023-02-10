CC=gcc
CFLAGS=-g -Wall -std=c99

# assuming here a 1:1 mapping from c file to executable
SRCS1 = segments.c fds.c fork.c wait.c exec.c redirect1.c redirect2.c pipe1.c pipe2.c
OBJS1 = $(patsubst %.c,%.o,$(SRCS1))
CMDS1 = $(basename $(SRCS1))

.PHONY: all
all: $(CMDS1)

$(OBJS1): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(CMDS1): %: %.o
	$(CC) $(CFLAGS) -o $@ $@.o

.PHONY: clean
clean:
	/bin/rm -f $(CMDS1) $(OBJS1)
