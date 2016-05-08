DEP = jk_flipflop.v vending_machine_fsm.v
TESTBENCH0 = tb_dimes.v
TESTBENCH1 = tb_quarters.v
TESTBENCH2 = tb_both.v
TESTBENCH3 = jk_tb.v
COMPILER = ncverilog

# flags that work on other compilers besides ncverilog
COFLAGS = -v -o

# compiler output
EXE = proj2.out


# compile testbench to verify the FSM with both 0 and 1 inputs
both: $(TESTBENCH0) $(DEP)
	$(COMPILER) $(DEP) $(TESTBENCH2)

# compile testbench to verify the FSM with only 0 inputs
dimes: $(TESTBENCH0) $(DEP)
	$(COMPILER) $(DEP) $(TESTBENCH0)

# compile testbench to verify the FSM with only 1 inputs
quarters: $(TESTBENCH0) $(DEP)
	$(COMPILER) $(DEP) $(TESTBENCH1)

# compile testbench to verify the JK flip flop module
jk: $(TESTBENCH0) $(DEP)
	$(COMPILER) $(DEP) $(TESTBENCH3)

# compiles dependencies for the executible (when compiled with the -o option)
$(EXE): $(TESTBENCH) $(DEP)
	$(COMPILER) $(EXE) $(TESTBENCH) $(DEP)

# clean directory of executibles
.PHONY: clean
clean:
	rm -f  *.out *.log
	clear

# run compiled executible
.PHONY: run
run:
	./*.out
