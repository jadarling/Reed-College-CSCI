
CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17
OPTFLAGS=-O3

%.o.cc:	%.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

highest: highest.o
	$(CXX) -o highest highest.o

source.wc : source.txt
	wc source.txt > source.wc

%.wc: %.txt
	wc $< > $@ 

clean: 
	rm -f *.wc
	
