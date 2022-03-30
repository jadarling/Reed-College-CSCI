#include "hforest.hh"
#include <vector>

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