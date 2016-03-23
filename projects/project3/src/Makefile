LD = $(shell which g++) 
CXX = $(shell which g++)
override CXXFLAGS += -­Wall -ansi -g
# CPPFLAGS = -Wall -ansi -g

EXE = Project3.out 
OBJS = main.o Song.o Library.o TitleCompare.o

DEPS = $(addprefix .,$(OBJS:.o=.d))

$(EXE): $(DEPS) $(OBJS) 
	$(LD) $(LDFLAGS) $(LDLIBS) $(OBJS) ­o $@ 

.%.d: %.cpp 
	@$(RM) $@; \ 
	$(CXX) ­MM ­MF $@ ­MT "$(<:.cpp=.o) $@" ­c $(CPPFLAGS) $<

$(OBJS): %.o: %.cpp 
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) ­c $< ­o $@ 
	­-include $(DEPS)

.PHONY: clean 
clean: 
	$(RM) $(OBJS) $(DEPS) $(EXE) 

.PHONY: run 
run: $(EXE) 
	./$(EXE) $(LIBRARY_FILE)



# all: main.o TicTacNode.o TicTacToe.o TicTacTrie.o
# 	g++ $(CPPFLAGS) TicTacNode.o TicTacToe.o TicTacTrie.o main.o -o Driver.out

# main.o: main.cpp
# 	g++ $(CPPFLAGS) -c main.cpp

# TicTacNode.o: TicTacNode.cpp TicTacNode.h
# 	g++ $(CPPFLAGS) -c TicTacNode.cpp TicTacNode.h

# TicTacToe.o: TicTacToe.cpp TicTacToe.h
# 	g++ $(CPPFLAGS) -c TicTacToe.cpp TicTacToe.h

# TicTacTrie.o: TicTacTrie.cpp TicTacTrie.h
# 	g++ $(CPPFLAGS) -c TicTacTrie.cpp TicTacTrie.h

# # to test for memory leaks
# val:
# 	valgrind ./Driver.out $(FILE)

# # -f removes any error messages if the file is not present
# clean:
# 	rm -rf *~ *.h.gch *# *.out *.o
# 	clear
# 	ls

# # compile an executable
# run:
# 	./Driver.out $(FILE)

# yo:
# 	make clean
# 	make
# 	clear