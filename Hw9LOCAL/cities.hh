/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<sstream>
#include<iterator>
#include<math.h>
#include<random>
#include<numeric>
#include<fstream>


// Representation of an ordering of cities
class Cities {
 public:
  // A pair of integral coordinates for each city
  using coord_t = std::pair<int, int>;

  using coord_list = std::vector<coord_t>;

  // An ordering of cities. Each value represents a unique index
  // into the current city ordering in some container.
  using permutation_t = std::vector<unsigned int>;


  //Cities();

  // Given a permutation, return a new Cities object where the order of the
  // cities reflects the original order of this class after reordering with
  // the given ordering. So for example, the ordering { 1, 0 } simply swaps
  // the first two elements (coordinates) in the new Cities object.
  Cities 
  reorder(const permutation_t& ordering) const;

  // For a given permutation of the cities in this object,
  // compute how long (distance) it would take to traverse all the cities in the
  // order of the permutation, and then returning to the first city.
  // The distance between any two cities is computed as the Euclidean 
  // distance on a plane between their coordinates.
  double 
  total_path_distance(const permutation_t& ordering) const;

  coord_list cities_ {0};
  permutation_t currentperm_ {0};
  int range_ = 0;

  friend std::istream &operator>> (std::istream & inS, Cities& city);

  friend std::ostream &operator<<(std::ostream & outS, Cities& city);
  
};
