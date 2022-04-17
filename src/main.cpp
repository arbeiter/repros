#include "project/World.hpp"
#include <iostream> 
#include <tuple>
#include <vector> 
#include <algorithm>
using namespace std;

#include <iostream>
#include <cstdlib>
void test_1();
void test_2();
void test_3(); 
/*
template<typename T> class superChunk {
  std::vector<std::vector<std::vector<T*>>> chunks;
};
*/

int main() {
  Project::World hello;
  std::vector<std::tuple<int, int>> states;
  states.push_back({1,2});
  states.push_back({2,2});
  states.push_back({11,2});
  for(auto current: states) {
    //std::cout << get<0>(current) << std::endl;
  }
  // TODO: Move to library, Delete element at specific position in vector of tuples using a lambda
  // states.erase(std::remove_if(states.begin(), states.end(), [](std::tuple<int, int> x) { return get<0>(x) < 10; }), states.end());
  // Erase from a vector of tuples at position
  // states.erase(states.begin() + 1);
  for(auto current: states) {
    // std::cout << get<0>(current) << std::endl;
  }
  hello.greet();
  //test_1();
  //test_2();
  std::cout << "ELLO";
  test_3();
  return EXIT_SUCCESS;
}

struct C {
  int x;
  int y;
  int z;
};

void test_1() {
  int numbers[5];
  int *p;
  p = numbers;
  *p = 10;
  p++;
  *p = 20;
  cout << numbers[0] << endl;
  cout << numbers[1] << endl;
  *(numbers+5)=110;
  cout << numbers[5] << endl;
  // Array of 
}

class X {
  int y;
  public:
  X(int x) {
    y = x;
  }

  void print() {
    cout << y;
  }
};

void test_2() {
  // 1d array
  int *p = new int[5];
  p[0] = 1;
  p[1] = 3;
  cout << p << std::endl;
  cout << *p << std::endl;
  cout << *(p + 1) << std::endl;

  // 2d array
  int **two_d = new int*[4];
  for(int i = 0; i < 4; i++) {
    two_d[i] = new int[10];
    for(int j = 0; j < 10; j++) {
      two_d[i][j] = 10 + i;
    }
  }
  std::cout << two_d[0][1] << std::endl;
  std::cout << two_d[1][1] << std::endl;
  std::cout << two_d[2][1] << std::endl;
  std::cout << two_d[3][1] << std::endl;

  // 1d array of objects
  X **ants; 
  ants = new X*[10];
  for(int i = 0; i < 10; i++) {
    ants[i] = new X(i);
    //ants[i]->print();
  }

  X ***ptr_to_two_d;
  ptr_to_two_d = new X**[10];
  for(int i = 0; i < 10; i++) {
    ptr_to_two_d[i] = new X*[10];
    for(int j = 0; j < 10; j++) {
      ptr_to_two_d[i][j] = new X(i+j);
      //ptr_to_two_d[i][j]->print();
    }
    std::cout << std::endl;
  }
  X ****ptr_to_three_d;
  ptr_to_three_d = new X***[10];
  for(int i = 0; i < 10; i++) {
    ptr_to_three_d[i] = new X**[10];
    for(int j = 0; j < 10; j++) {
      ptr_to_three_d[i][j] = new X*[10];
      for(int k = 0; k < 10; k++) {
        ptr_to_three_d[i][j][k] = new X(i+j+k);
        ptr_to_three_d[i][j][k]->print();
      }
    }
    std::cout << std::endl;
  }
  /*
  struct C *array[10];
  for(int i = 0; i < 10; i++) {
    array[i] = malloc(sizeof(struct C));
  }
  struct C *(*p)[] = &array;
  for(int i = 0; i < 10; i++) {
    std::cout<< (*p)[i]->x << std::endl;
    std::cout<< (*p)[i]->y << std::endl;
    std::cout<< (*p)[i]->z << std::endl;
  }
  */
}

void test_3() {
  /*
  std::cout << 142;
  std::vector<X *> v;
  for(int i = 0; i < 10; i++) 
    v.push_back(new X(10));

  std::vector<std::vector<X *>> yo;
  for(int x = 0; x < 10; x++)
    for(int y = 0; y < 10; y++)
      yo[x][y] = new X(10);
      */

  /* BAD!!! Copies the same data into all */
  /*
  std::vector<std::vector<std::vector<X *>>> y;
  std::vector<X *> z(5, new X(1));
  // z[0] -> print();
  // std::cout << z[0] << std::endl;
  // std::cout << z[1] << std::endl;
  std::vector<std::vector<X *>> a(5, z);
  int rows = 10;
  int cols = 10;
  int breadths = 10;

  */
  std::cout << 162;
  typedef vector<X *> v1d;
  typedef vector<v1d> v2d;
  typedef vector<v2d> v3d;
  int rows = 10;
  int cols = 10;
  int breadths = 10;
  v3d superChunk(rows, v2d(cols, v1d(breadths, new X(1))));
  std::cout << 166;
  // Add z  wall
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      superChunk[i][j].push_back(new X(111));
    }
  }

  std::cout << "YOO " << std::endl;
  superChunk[9][9][10]->print();

/*
  std::vector<std::vector<std::vector<X *>>> v;
  for(int i = 0; i < 10; i++) 
    for(int j = 0; j < 10; j++)
      for(int k = 0; k < 10; k++)
        v.push_back(new X(10));
  */
  // vector<vector<vector<int> > > vec (5,vector<vector<int> >(3,vector <int>(2,4)));
}
