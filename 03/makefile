CC=g++
IDIR =include
ODIR=obj
CFLAGS=-I$(IDIR)
EXECUTABLE1 = exe1
EXECUTABLE2 = exe2
EXECUTABLE3 = exe3
EXEs = exe1 exe2 exe3

_OBJ1 = SimpleMCMain3.o PayOff2.o Random1.o SimpleMC2.o 
OBJ1 = $(patsubst %,$(ODIR)/%,$(_OBJ1))

_OBJ2 = SimpleMCMain4.o PayOff2.o Random1.o SimpleMC2.o 
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

_OBJ3 = SimpleMCMain5.o DoubleDigital.o PayOff2.o Random1.o SimpleMC2.o 
OBJ3 = $(patsubst %,$(ODIR)/%,$(_OBJ3))

all: $(EXEs)

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE1): $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)

$(EXECUTABLE2): $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS)

$(EXECUTABLE3): $(OBJ3)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o exe1 exe2 exe3
