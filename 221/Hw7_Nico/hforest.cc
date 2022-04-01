#include "hforest.hh"
#include <vector>
// HForest, in this version, uses a classless paradigm; essentially, HForest is simply a vector
// and the functions described below are used to heapify the vector itself not turn it into a heap object.
//Ideally, this code is more efficient than OOP, but lacks the organization. 
// size() and add() are built into the vector (assuming tree_ptr_t construction)


bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2) {
    return t1->get_value() < t2->get_value();
}


void add_tree(HTree::tree_ptr_t node, std::vector<HTree::tree_ptr_t> forest){ 
    forest.emplace_back(node);
}


HTree::tree_ptr_t pop_tree(std::vector<HTree::tree_ptr_t> forest){
    std::make_heap(forest.begin(),forest.end(),compare_trees);
    HTree::tree_ptr_t popper = forest.back();
    forest.pop_back();
    return popper;
}