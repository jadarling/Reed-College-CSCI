/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#include "htree.hh"

// Return an optional list of directions from root to a node of a given key.
// If key not contained in this tree, returns nullptr
HTree::possible_path_t  HTree::path_to(key_t key) const
{
  //auto path = new path_t(); //path is a pointer to empty list path_t on the heap
  //possible_path_t pptr(path); //pptr is a unique pointer version of path
  //possible_path_t pptr(new path_t());
  if (get_key() == key) {return possible_path_t (new path_t());}

  if (get_child(Direction::LEFT)){
    auto left_res = get_child(Direction::LEFT)->path_to(key);
    if (left_res != nullptr){
      left_res->push_front(Direction::LEFT);
      return left_res;
      }
  }
  if (get_child(Direction::RIGHT)){
    auto right_res = get_child(Direction::RIGHT)->path_to(key);
    if (right_res == nullptr){
        return nullptr;
      } else {
        right_res->push_front(Direction::RIGHT);
        return right_res;
    }
  }
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
    return nullptr;
  }

