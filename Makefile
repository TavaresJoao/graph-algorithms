# specify the shell, in case the SHELL variable is not set or is not
# inherited from the environment
SHELL = /bin/bash

# set suffix list, to prevent confusion between different make programs
# line 7 clears an implied suffix list, and line 8 sets a new one
.SUFFIXES:
.SUFFIXES: .cpp .h .o

# project set up and directories
CXX	= g++
INCLDIR	= include/
BINDIR	= bin/
OBJDIR	= obj/
SRCDIR	= src/

# final executable name
_BIN	= main.out
BIN	= $(addprefix $(BINDIR), $(_BIN))

# files; here all object files will be stored in $(OBJDIR), with the
# same base names as corresponding c files from SRCDIR
SRC	= $(wildcard src/*.cpp)
_OBJS	= $(patsubst src/%.cpp, %.o, $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(_OBJS))

# compilation flags
CPPFLAGS = -Wall -pedantic -g -I$(INCLDIR)
OFLAGS =

# compile binary and object files
.PHONY: all
all: $(BIN)

$(BIN): $(BINDIR) $(OBJS)
	$(CXX) $(OFLAGS) $(OBJS) -o $(BIN)

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJS): $(OBJDIR) $(SRC)
	$(CXX) $(CPPFLAGS) -c src/graph.cpp -o obj/graph.o
	$(CXX) $(CPPFLAGS) -c src/main.cpp -o obj/main.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

# clean entire project directory
.PHONY: clean
clean:
	- rm -rf $(BINDIR) $(OBJDIR)


# check code quality
.PHONY: cppcheck memcheck
cppcheck:
	cppcheck --enable=all --language=cpp --inconclusive \
	--suppress=missingInclude $(SRC) -i $(INCLDIR)

memcheck: all
	valgrind -v --show-leak-kinds=all --leak-check=full --track-origins=yes \
	./$(BIN)

# debugging make
print-% :
	@echo $* = $($*)
