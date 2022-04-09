/*
 * A pair of simple classes tu perform stream I/O on individual bits.
 */
#include <iostream>
#include <vector>


// BitInput: Read a single bit at a time from an input stream.
// Before reading any bits, ensure your input stream still has valid inputs.
class BitInput {
  
 public:
  // Construct with an input stream
  BitInput(std::istream& is)
   : is_(is), buff_(0), count_(0) {}

  BitInput(const BitInput&) = delete;
  BitInput(BitInput&&) = delete;
  BitInput& operator=(const BitInput&) = delete;
  BitInput& operator=(BitInput&&) = delete;

  // Read a single bit (or trailing zero)
  // Allowed to crash or throw an exception if called past end-of-file.
  bool input_bit();
  
  private:
    std::istream& is_;
    uint8_t buff_;
    uint8_t count_;
    
};

// BitOutput: Write a single bit at a time to an output stream
// Make sure all bits are written out by the time the destructor is done.
class BitOutput {
 public:
  // Construct with an input stream
  BitOutput(std::ostream& os) 
  : os_(os), buff_(0), count_(0) {}

  // Flushes out any remaining output bits and trailing zeros, if any:
  ~BitOutput();

  BitOutput(const BitOutput&) = delete;
  BitOutput(BitOutput&&) = delete;
  BitOutput& operator=(const BitOutput&) = delete;
  BitOutput& operator=(BitOutput&&) = delete;

  // Output a single bit (buffered)
  void output_bit(bool bit);
  private:
    std::ostream& os_;
    uint8_t buff_;
    uint8_t count_;
    
};

