#include "project/World.hpp"
#include <iostream> 
#include <tuple>
#include <vector> 
#include <algorithm>
using namespace std;

#include <iostream>
#include <cstdlib>

int main() {
  Project::World hello;
  std::vector<std::tuple<int, int>> states;
  states.push_back({1,2});
  states.push_back({2,2});
  states.push_back({11,2});
  for(auto current: states) {
    std::cout << get<0>(current) << std::endl;
  }
  // TODO: Move to library, Delete element at specific position in vector of tuples using a lambda
  // states.erase(std::remove_if(states.begin(), states.end(), [](std::tuple<int, int> x) { return get<0>(x) < 10; }), states.end());
  // Erase from a vector of tuples at position
  // states.erase(states.begin() + 1);
  for(auto current: states) {
    std::cout << get<0>(current) << std::endl;
  }
  hello.greet();
  return EXIT_SUCCESS;
}
