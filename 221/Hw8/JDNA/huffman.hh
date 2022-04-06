/*
 * Huffman: a class to encode and decode symbols based on adaptive Huffman coding
 * https://en.wikipedia.org/wiki/Huffman_coding
 */

#pragma once

#include <climits>
#include <vector>

#include "htree.hh"
#include "hforest.hh"

class Huffman {
 public:
  // Maximum number of symbols we need to encode (a symbol fits in a char) + EOF
  static const int ALPHABET_SIZE = (1 << CHAR_BIT) + 1;  // (2 ** 8) + 1
  static const int HEOF = ALPHABET_SIZE - 1;  // Special symbol to denote end of file

  using bits_t = std::vector<bool>;


  Huffman() {
    for (auto i=0; i < HEOF; i++){
      freqs_.push_back(0);}
    freqs_.push_back(1);
  };


  ~Huffman();
  Huffman(const Huffman&) = delete;
  Huffman(Huffman&&) = delete;
  Huffman& operator=(const Huffman&) = delete;
  Huffman& operator=(Huffman&&) = delete;

  //Build Huff
  HForest
  buildHuff(HForest forest);

  //Build Forest method
  static HForest 
  buildForest(std::vector<int>);

  //Merge trees method
  HForest
  mergeTrees(HForest forest, HForest::tree_t t1, HForest::tree_t t2);
  
  // Encode a symbol into a sequence of bits, then update frequency table.
  bits_t 
  encode(int symbol);

  // Decode a single bit into a symbol. If no symbol can be unmabiguously decoded
  // without additional bits, returns a negative value.
  // Subsequent calls with more bits should eventually resolve to either
  // a character symbol or HEOF.
  // Finally, updates the frequency table with this additional symbol.
  int 
  decode(bool bit);
  private:
  std::vector<int> freqs_;
};
