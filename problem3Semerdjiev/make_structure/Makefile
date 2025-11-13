CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -O2 -Iinclude
CXXFLAGS = -Wall -Wextra -O2 -Iinclude -Itests

OBJDIR = build
BINDIR = bin

# C objects
OBJS = $(OBJDIR)/main.o $(OBJDIR)/counter.o $(OBJDIR)/print.o $(OBJDIR)/factorial.o

# Test sources and objects
TEST_SRCS = tests/test_factorial.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
TEST_BIN  = $(BINDIR)/tests

$(BINDIR)/program: $(OBJS) # these are all the o files
	$(CC) $(CFLAGS) $(OBJS) -o $(BINDIR)/program

$(OBJDIR)/main.o: src/main.c include/library.h
	$(CC) $(CFLAGS) -c src/main.c -o $(OBJDIR)/main.o

$(OBJDIR)/counter.o: src/counter.c include/library.h
	$(CC) $(CFLAGS) -c src/counter.c -o $(OBJDIR)/counter.o

$(OBJDIR)/print.o: src/print.c include/library.h
	$(CC) $(CFLAGS) -c src/print.c -o $(OBJDIR)/print.o

$(OBJDIR)/factorial.o: src/factorial.c include/library.h
	$(CC) $(CFLAGS) -c src/factorial.c -o $(OBJDIR)/factorial.o

# Compile C++ test files
# $< is the first prerequisite which is usually the first source file or h file
# $@ is the target
tests/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link test binary with your C objects
$(TEST_BIN): $(OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(TEST_OBJS) -o $(TEST_BIN)

.PHONY: test clean

test: $(TEST_BIN)
	$(TEST_BIN)

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/program $(TEST_OBJS) $(TEST_BIN)