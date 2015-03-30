CC=g++
IDIR =include
ODIR=obj
CFLAGS=-I$(IDIR)
EXECUTABLE = exe
EXEs = exe

_OBJ = EquityFXMain.o PayOff3.o Random2.o PayOffBridge.o Parameters.o MCStatistics.o ConvergenceTable.o Arrays.o Normals.o ParkMiller.o AntiThetic.o PathDependent.o PathDependentAsian.o ExoticEngine.o ExoticBSEngine.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all: $(EXEs)

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o exe
