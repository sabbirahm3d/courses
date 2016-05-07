SRC = jkflop.v
TESTBENCH = test.v
# TBOUTPUT = waves.lxt	
# THIS NEEDS TO MATCH THE OUTPUT FILE
#FROM YOUR TESTBENCH
COMPILER = iverilog
SIMULATOR = vvp
VIEWER = gtkwave

#OPTIONS
COFLAGS = -v -o
SFLAGS = -v
SOUTPUT = -lxt		#SIMULATOR OUTPUT TYPE
#TOOL OUTPUT
EXE = proj2.out			#COMPILER OUTPUT

compile: $(TESTBENCH) $(SRC)
	$(COMPILER) $(SRC) $(TESTBENCH) -o $(EXE)

clean:
	rm -f  *.out
	clear

run: $(EXE)
	./$(EXE)

$(EXE): $(TESTBENCH) $(SRC)
	$(COMPILER) $(EXE) $(TESTBENCH) $(SRC)

display: $(TBOUTPUT)
	$(VIEWER) $(TBOUTPUT) &
