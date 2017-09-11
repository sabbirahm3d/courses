LD = $(shell which g++)
CXX = $(shell which g++)
override CXXFLAGS += -Wall
-include $(DEPS)

EXE = Project5.out
OBJS = Project5.o PerfectHash.o BackupHash.o HashGen.o
DEPS = $(addprefix .,$(OBJS:.o=.d))

$(EXE): $(DEPS) $(OBJS)
	$(LD) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $@

.%.d: %.cpp
	@$(RM) $@; \
	$(CXX) -MM -MF $@ -MT "$(<:.cpp=.o) $@" -c $(CPPFLAGS) $<

$(OBJS): %.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OBJS) $(DEPS) $(EXE)
	clear

.PHONY: run
run: $(EXE)
	./$(EXE) $(FILE)

.PHONY: val
val: $(EXE)
	valgrind ./$(EXE) $(FILE)

.PHONY: debug
debug:
	make clean
	make CPPFLAGS=-DDEBUG