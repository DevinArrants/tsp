/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once

#include <vector>
#include <istream>
#include <ostream>

// Representation of an ordering of cities
class Cities {
 public:
  // A pair of integral coordinates for each city
  using coord_t = std::pair<int, int>;

  // An ordering of the cities in cities_t. Each value represents a unique index
  // into the current city ordering.
  using permutation_t = std::vector<unsigned int>;
  
  using city_list_t = std::vector<coord_t>;
  
  ~Cities() = default;
  
  // Given a permutation, return a new Cities object where the order of the
  // cities reflects the original order of this class after reordering with
  // the given ordering. So for example, the ordering { 1, 0 } simply swaps
  // the first two elements (coordinates) in the new Cities object.
  Cities reorder(const permutation_t& ordering) const;

  // For a given permutation of the cities in this object,
  // compute how long (distance) it would take to traverse all the cities in the
  // order of the permutation, and then returning to the first city.
  // The distance between any two cities is computed as the Euclidean
  // distance on a plane between their coordinates.
  double total_path_distance(const permutation_t& ordering) const;
  
  std::vector<coord_t> get_list() const {return city_list_;};

  void add_coord(coord_t coord){city_list_.push_back(coord);};

 private:
  city_list_t city_list_;
};
std::istream& operator>> (std::istream& is, Cities& city); 
std::ostream& operator<< (std::ostream& out, Cities& city);

Cities::permutation_t random_permutation(unsigned len);
