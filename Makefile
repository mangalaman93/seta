# makefile (use -pg for profiling)

MAINFILE = examples/fibonacci_info.c
OUTPUT = fibonacci_info

IDIR = include
CC = gcc
DEBUG = -g
PROFILE =
CFLAGS = -Wall -std=c99 -w $(DEBUG) -I$(IDIR) $(PROFILE)
VALGRIND = valgrind --leak-check=full

SDIR = src
ODIR = bin
LDIR = lib
TDIR = test
LIBS = -lm -lpthread -lrt

_DEPS = closure.h dequeue.h graph_dot.h lists.h logger.h msg.h processor.h ready_queue.h scheduler.h seta.h seta_internal.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = logger.o dequeue.o msg.o lists.o closure.o graph_dot.o ready_queue.o processor.o seta.o
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

testvalgrind: test_setup dir $(TOBJ)
	$(foreach test_file, $(wildcard $(ODIR)/*_test.o), $(VALGRIND) ./$(test_file))

test_setup: all
ifeq "$(wildcard $(LDIR) )" ""
	mkdir -p $(LDIR)
	git clone https://github.com/siu/minunit.git $(LDIR)/minunit
endif

distclean: clean docclean
	rm -rf $(LDIR)

docclean:
	rm -rf doc/html

clean:
	rm -rf $(ODIR) *~

doc: doc/html

doc/html:
	cd doc && doxygen

.PHONY: clean doc docclean
