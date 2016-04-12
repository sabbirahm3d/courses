LD = $(shell which g++)
CXX = $(shell which g++)
override CXXFLAGS += -Wall
-include $(DEPS)

EXE = Project3.out
OBJS = main.o Song.o Library.o TitleCompare.o ArtistCompare.o AlbumCompare.o \
GenreCompare.o YearCompare.o Tree.o TreeIterator.o
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
	./$(EXE) $(LIBRARY_FILE)

.PHONY: val
val: $(EXE)
	valgrind ./$(EXE) $(LIBRARY_FILE)

.PHONY: debug
debug:
	make clean
	make CPPFLAGS=-DDEBUG

.PHONY: yo
yo:
	make clean
	make