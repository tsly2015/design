# ./configure; make; make install

CC=g++
IDIR =include
ODIR=obj
CFLAGS=-I$(IDIR)
EXECUTABLE1 = exe1
EXECUTABLE2 = exe2
EXEs = exe1 exe2

_OBJ1 = SimpleMCMain1.o Random1.o 
OBJ1 = $(patsubst %,$(ODIR)/%,$(_OBJ1))

_OBJ2 = SimpleMCMain2.o PayOff1.o Random1.o SimpleMC.o 
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

all: $(EXEs)

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE1): $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS)

$(EXECUTABLE2): $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS)

#how to auto call?


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o exe1 exe2
