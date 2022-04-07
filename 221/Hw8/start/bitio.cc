#include<iostream>
#include "bitio.hh"

bool 
BitInput::input_bit(){
	uint8_t i; //reads a whole byte
	uint8_t mask = 128; //so that only most significant (leftmost) bit is read, 128 is 10000000 in binary
	std::cin >> i; //read char to i
	assert(this->is.std::ios::good()); //check istream is good
	i = i & mask; //bitwise and
	i = i >> 7; //shift over so that 1 will be either 0 or 1
	if (i==0){
		return false;
	}
	else{
		return true;
	}
}

void 
BitOutput::output_bit(bool bit){
	//!!need to buffer and flush, but I don't understand that
	std::cout << bit;
	this->os.flush();
}
