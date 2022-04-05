
#include"huffman.hh"


//Build Forest method
  HForest
  build_forest(std::vector<int> freqs){
    HForest forest;
    for (int i=0; i < freqs.size(); i++){
      forest.add_tree(HTree::tree_ptr_t(new HTree(i,freqs[i])));
      };
    return forest;
  };


// Encode a symbol into a sequence of bits, then update frequency table.
  Huffman::bits_t 
  encode(int symbol){
    
  };


  // Decode a single bit into a symbol. If no symbol can be unmabiguously decoded
  // without additional bits, returns a negative value.
  // Subsequent calls with more bits should eventually resolve to either
  // a character symbol or HEOF.
  // Finally, updates the frequency table with this additional symbol.
  int 
  decode(bool bit){

  };