IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs --coverage

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = catch.hpp pilha.hpp teste_pilha.hpp 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = pilhaS.o pilhaD.o teste_pilha.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pilha: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
