EXE = lab7
OBJS = IntArray.o lab7.o
CPPFLAGS = -ansi -Wall

# The variable CXX is the default C++ compiler, in this case it's g++
$(EXE): $(OBJS)
	$(CXX) $(OBJS) -o $(EXE)

.PHONY : clean
clean:
	-rm -f lab7.o $(EXE)