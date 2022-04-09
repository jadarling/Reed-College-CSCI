#include<iostream>
#include "bitio.hh"



bool 
BitInput::input_bit(){
    uint8_t mask = 1;
    if (count_ == 0){
        buff_ = is_.get();}
    uint8_t tmp = buff_ >> count_;
    count_ += 1;
    if (count_ == 8){
        count_ = 0;
    }
    return tmp & mask;
};


void 
BitOutput::output_bit(bool bit){
    uint8_t mask = bit >> count_;
    buff_ = buff_ | mask;
    count_ += 1;
    if (count_ == 8){
        os_.put(buff_);
        buff_ = 0;
        count_ = 0;
    }
};

BitOutput::~BitOutput(){ 
    if (count_ != 0){  
        os_.put(buff_);
    };
};