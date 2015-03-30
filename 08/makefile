CC=g++
IDIR =include
ODIR=obj
CFLAGS=-I$(IDIR)
EXECUTABLE = exe
EXEs = exe

_OBJ = TreeMain.o PayOff3.o PayOffBridge.o Parameters.o Arrays.o Normals.o TreeProducts.o TreeAmerican.o TreeEuropean.o BinomialTree.o BlackScholesFormulas.o PayOffForward.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: $(EXEs)

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o exe
