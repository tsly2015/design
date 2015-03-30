CC=g++
IDIR =include
ODIR=obj
CFLAGS=-I$(IDIR)
EXECUTABLE1 = exe1
EXECUTABLE2 = exe2
EXECUTABLE3 = exe3
EXEs = exe1 exe2 exe3

_OBJ1 = RandomMain1.o PayOff3.o Random1.o SimpleMC7.o Vanilla3.o PayOffBridge.o Parameters.o MCStatistics.o ConvergenceTable.o 
OBJ1 = $(patsubst %,$(ODIR)/%,$(_OBJ1))

_OBJ2 = RandomMain3.o PayOff3.o Random2.o SimpleMC8.o Vanilla3.o PayOffBridge.o Parameters.o MCStatistics.o ConvergenceTable.o Arrays.o Normals.o ParkMiller.o AntiThetic.o 
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

_OBJ3 = RandomMain2.o PayOff3.o Random2.o Random3.o SimpleMC8.o Vanilla3.o PayOffBridge.o Parameters.o MCStatistics.o ConvergenceTable.o Arrays.o Normals.o AntiThetic.o 
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
