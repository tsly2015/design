CC=g++
IDIR =include
ODIR=obj
CFLAGS=-I$(IDIR)
EXECUTABLE1 = exe1
EXECUTABLE2 = exe2
EXECUTABLE3 = exe3
EXECUTABLE4 = exe4
EXEs = exe1 exe2 exe3 exe4

_OBJ1 = VanillaMain1.o PayOff2.o Random1.o SimpleMC3.o DoubleDigital.o Vanilla1.o  
OBJ1 = $(patsubst %,$(ODIR)/%,$(_OBJ1))


_OBJ2 = VanillaMain2.o PayOff3.o Random1.o SimpleMC4.o Vanilla2.o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

_OBJ3 = VanillaMain3.o PayOff3.o Random1.o SimpleMC5.o Vanilla3.o PayOffBridge.o
OBJ3 = $(patsubst %,$(ODIR)/%,$(_OBJ3))

_OBJ4 = VanillaMain4.o PayOff3.o Random1.o SimpleMC6.o Vanilla3.o PayOffBridge.o Parameters.o
OBJ4 = $(patsubst %,$(ODIR)/%,$(_OBJ4))


all: $(EXEs)

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE1): $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)

$(EXECUTABLE2): $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS)

$(EXECUTABLE3): $(OBJ3)
	$(CC) -o $@ $^ $(CFLAGS)

$(EXECUTABLE4): $(OBJ4)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o exe1 exe2 exe3 exe4
