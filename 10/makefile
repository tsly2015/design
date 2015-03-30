CC=g++
IDIR =include
ODIR=obj
CFLAGS=-I$(IDIR)
EXECUTABLE = exe
EXEs = exe

_OBJ = PayFactoryMain.o PayOff3.o PayOffBridge.o PayOffFactory.o PayOffRegistration.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: $(EXEs)

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o exe
