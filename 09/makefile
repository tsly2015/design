CC=g++
IDIR =include
ODIR=obj
CFLAGS=-I$(IDIR)
EXECUTABLE1 = exe1
EXECUTABLE2 = exe2
EXEs = exe1 exe2

_OBJ1 = SolveMain1.o Normals.o BlackScholesFormulas.o BSCallClass.o
OBJ1 = $(patsubst %,$(ODIR)/%,$(_OBJ1))

_OBJ2 = SolveMain2.o Normals.o BlackScholesFormulas.o BSCallTwo.o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))


all: $(EXEs)

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE1): $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)

$(EXECUTABLE2): $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o exe1 exe2
