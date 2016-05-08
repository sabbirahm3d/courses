DEP = jk_flipflop.v vending_machine_fsm.v
TESTBENCH = main.v
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

compile: $(TESTBENCH) $(DEP)
	$(COMPILER) $(DEP) $(TESTBENCH) -o $(EXE)

$(EXE): $(TESTBENCH) $(DEP)
	$(COMPILER) $(EXE) $(TESTBENCH) $(DEP)

display: $(TBOUTPUT)
	$(VIEWER) $(TBOUTPUT) &

.PHONY: clean
clean:
	rm -f  *.out
	clear

.PHONY: run
run:
	./$(EXE)
