CXX=clang++
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17
OPTFLAGS=-O3
SRC= tree.cc tree.hh
OBJ=$(SRC:.cc=.o)
all: test_tree

test_tree: tree.o test_tree.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o.cc:	%.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<
