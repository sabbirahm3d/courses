DEP = jk_flipflop.v vending_machine_fsm.v
TESTBENCH = tb_fsm.v
TESTBENCH_JK = jk_tb.v
SIMULATOR = gtkwave

# COMPILER = iverilog
# for GL, use ncverilog
COMPILER = ncverilog

# flags that work on other compilers besides ncverilog
COFLAGS = -v -o

# compiler output
EXE = proj2.out

# simulator output
SIM = fsm.vcd

# compile testbench to verify the FSM with both 0 and 1 inputs
compile: $(TESTBENCH) $(DEP)
	$(COMPILER) $(DEP) $(TESTBENCH)

# compile testbench to verify the JK flip flop module
jk: $(TESTBENCH_JK) $(DEP)
	$(COMPILER) $(DEP) $(TESTBENCH_JK)

# compiles dependencies for the executible (when compiled with the -o option)
$(EXE): $(TESTBENCH) $(DEP)
	$(COMPILER) $(EXE) $(TESTBENCH) $(DEP)

# simulates a timing diagram of the testbench
simulate:
	$(SIMULATOR) $(SIM)

# clean directory of executables and logs
.PHONY: clean
clean:
	rm -f  *.out *.log *.vcd
	clear

# run compiled executible
.PHONY: run
run:
	./*.out
