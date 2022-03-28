/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"

// Return an optional list of directions from root to a node of a given key.
// If key not contained in this tree, returns nullptr
HTree::possible_path_t  HTree::path_to(key_t key) const
{
  auto path = new path_t; //path is a pointer to empty list path_t on the heap
  possible_path_t pptr(path); //pptr is a unique pointer version of path
  if (get_key() == key) {return pptr;}

  const auto left_res = path_to(get_child(Direction::LEFT)->get_key());
  if (true);{
    path->push_back(Direction::LEFT);
  }
  const auto right_res = path_to(get_child(Direction::RIGHT)->get_key());





  return nullptr;
}

HTree::tree_ptr_t  HTree::get_child(Direction dir) const
  {
    if (dir==Direction::LEFT){
      return left_;
    }
    if (dir==Direction::RIGHT){
      return right_;
    }
  }