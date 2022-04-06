
#include"huffman.hh"

HForest
Huffman::buildHuff(HForest forest){
  if (forest.size() <= 1){ return forest;}
  else {
    HForest::tree_t tmp = forest.pop_top();
    return buildHuff(mergeTrees(forest, tmp, forest.pop_top()));
  };
  return forest;
};


//Build Forest method
  HForest
  Huffman::buildForest(std::vector<int> freqs){
    HForest forest;
    for (int i=0; i < freqs.size(); i++){
      forest.add_tree(HTree::tree_ptr_t(new HTree(i,freqs[i])));
      };
    return forest;
  };

  HForest
  Huffman::mergeTrees(HForest forest, HForest::tree_t t1, HForest::tree_t t2){
    int value = t1->get_value() + t2->get_value();
    forest.add_tree(HTree::tree_ptr_t(new HTree(-1, value, t1, t2)));
    return forest;
  };

// Encode a symbol into a sequence of bits, then update frequency table.
  Huffman::bits_t 
  Huffman::encode(int symbol){
    bits_t encoded;
    HForest huffman = buildForest(this->freqs_);
    huffman = buildHuff(huffman);
    HForest::tree_t huffTree = huffman.pop_top();
    HTree::possible_path_t path = huffTree->path_to(symbol);
    if (!path) {return encoded;}
    for (HTree::Direction direction : *path){
      switch(direction){
        case HTree::Direction::RIGHT:
          encoded.push_back(true);
        case HTree::Direction::LEFT:
          encoded.push_back(false);
      };
    };
    this->freqs_[symbol]++;
    return encoded;
};


  // Decode a single bit into a symbol. If no symbol can be unmabiguously decoded
  // without additional bits, returns a negative value.
  // Subsequent calls with more bits should eventually resolve to either
  // a character symbol or HEOF.
  // Finally, updates the frequency table with this additional symbol.
  int 
  Huffman::decode(bool bit){
    HForest::tree_t curr = huffTree_;
    if (!huffTree_){    
      HForest huffman = buildForest(this->freqs_);
      HForest huffTree = buildHuff(huffman);
      curr = huffTree.pop_top();}
    else {curr = huffTree_;}
    
    switch(bit) {
      case true:
        curr = curr->get_child(HTree::Direction::RIGHT);
      case false:
        curr = curr->get_child(HTree::Direction::LEFT);
      }
    if (curr->get_key() == -1) { 
      huffTree_ = curr;
      return -1;
    }
    else {
      char decoded = curr->get_key();
      this->freqs_[decoded]++;
      return decoded;
    };
  };