CFLAGS = -ansi -pedantic -ggdb -lm
CC = gcc
BIN = loldog

SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(wildcard *.c))
LIBS := $(wildcard *.h)

$(BIN): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(BIN)

.PHONY clean list install:
clean:
	rm $(OBJS) $(BIN)

list:
	echo .c: $(SRCS) 
	echo .o: $(OBJS) 
	echo .h: $(LIBS)

install:
	install loldog /usr/bin
