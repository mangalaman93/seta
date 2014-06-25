# makefile (use -pg for profiling)

MAINFILE = examples/basic.c
OUTPUT = basic

IDIR = src
CC = gcc
DEBUG = -g
PROFILE =
CFLAGS = -Wall -c -std=c99 -w $(DEBUG) -I$(IDIR) $(PROFILE)

SDIR = src
ODIR = bin
LIBS = -lm -lpthread

_DEPS = dequeue.h seta.h seta_internal.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = closure.o lists.o processor.o dequeue.o logger.o ready_queue.o graph_dot.o msg.o scheduler.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

all: dir $(ODIR)/$(OUTPUT)

dir:
	mkdir -p $(ODIR)

$(ODIR)/$(OUTPUT): $(OBJ)
	$(CC) -I$(IDIR) -o $@ $^ $(MAINFILE) $(PROFILE) $(LIBS)

clean:
	rm -rf $(ODIR) *~

.PHONY: clean
