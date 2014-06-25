# makefile (use -pg for profiling)

MAINFILE = examples/basic.c
OUTPUT = basic

IDIR = src
CC = gcc
DEBUG = -g
PROFILE =
CFLAGS = -Wall -std=c99 -w $(DEBUG) -I$(IDIR) $(PROFILE)

SDIR = src
ODIR = bin
LDIR = lib
TDIR = test
LIBS = -lm -lpthread -lrt

_DEPS = dequeue.h seta.h seta_internal.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = closure.o lists.o processor.o dequeue.o logger.o ready_queue.o graph_dot.o msg.o scheduler.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_TOBJ = dequeue_test.o
TOBJ = $(patsubst %,$(ODIR)/%,$(_TOBJ))

$(ODIR)/%_test.o: $(TDIR)/%_test.c $(DEPS)
	$(CC) $(CFLAGS) -I$(LDIR)/minunit $(OBJ) -o $@ $< $(PROFILE) $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

all: dir $(ODIR)/$(OUTPUT)

dir:
	mkdir -p $(ODIR)

$(ODIR)/$(OUTPUT): $(OBJ)
	$(CC) -I$(IDIR) -o $@ $^ $(MAINFILE) $(PROFILE) $(LIBS)

test: test_setup dir $(TOBJ)
	$(foreach test_file, $(wildcard $(ODIR)/*_test.o), ./$(test_file))

test_setup: all
ifeq "$(wildcard $(LDIR) )" ""
	mkdir -p $(LDIR)
	git clone https://github.com/siu/minunit.git $(LDIR)/minunit;
endif

clean:
	rm -rf $(ODIR) *~

distclean: clean
	rm -rf $(LDIR)

.PHONY: clean

doc: doc/html
.PHONY: doc

doc/html:
	cd doc && doxygen

docclean:
	rm -r doc/html
.PHONY: docclean
