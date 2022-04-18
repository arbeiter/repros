#include "project/World.hpp"
#include <iostream> 
#include <tuple>
#include <vector> 
#include <algorithm>
using namespace std;

#include <iostream>
#include <cstdlib>
void init(); 
/*
template<typename T> class superChunk {
  std::vector<std::vector<std::vector<T*>>> chunks;
};
*/
enum class texture_type {
  blotch = 0, grass = 1, air = 3
};

class Cube {
  texture_type tt;
  public:
    Cube(texture_type ttype) {
      tt = ttype;
    }

    void shout() {
      std::cout << "GRASS" << std::endl;
    }
};
typedef std::vector<Cube *> v1d;
typedef std::vector<v1d> v2d;
typedef std::vector<v2d> v3d;

class SuperChunk {
  int rows = 10;
  int cols = 10;
  int breadths = 10;
  v3d superChunk;
  v1d chunk;

  public:
  SuperChunk() {
    superChunk = v3d(rows, v2d(cols, v1d(breadths, new Cube(texture_type::air))));
    
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
        for(int k = 0; k < breadths; k++) {
          superChunk[i][j][k] = new Cube(texture_type::air);
          // superChunk[i][j][k] -> shout(); THIS WORKS
        }
      }
    }

    /*
    chunk = v1d(new Cube(texture_type::air));
    for(int i = 0; i < rows; i++) {
      chunk[i] = new Cube(texture_type::air);
    }
    */
  }

  ~SuperChunk() {}

  Cube* get(int x, int y, int z) {
    return superChunk[0][0][0];
  }

  void addWall() {
    breadths+=1;
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
        superChunk[i][j].push_back(new Cube(texture_type::air));
      }
    }
  }
};

class TerrainGen {
  // SCX, SCY, SCZ
  // CX, CY, CZ
  /* Constructor
   = new SuperChunk();
  */
  SuperChunk sc;
  public:
  TerrainGen() {
    sc = SuperChunk();
  }

  ~TerrainGen() {
  }

  texture_type getTextureFromHeight(int h) {
    if(h < 20) {
      return texture_type::blotch;
    }
    if(h < 40 && h >= 20) {
      return texture_type::grass;
    }
    return texture_type::air;
  }

  void fillChunk(int x, int y, int z) {
      texture_type type = getTextureFromHeight(y);
      int chunk_x = x / 10;
      int chunk_y = y / 10;
      int chunk_z = z / 10;

      Cube *chunk = sc.get(chunk_x, chunk_y, chunk_z);
      chunk->shout();
      int in_x = x % 10;
      int in_y = y % 10;
      int in_z = z % 10;
      //Position voxelPos = { in_x, in_y, in_z };
      //chunk->setVoxel(voxelPos, type);
  }

  void billChunk(int x) {
  }

  void seedData() {
    fillChunk(0, 0, 0);
  }
};

int main() {
  TerrainGen x = TerrainGen();
  x.seedData();
  return EXIT_SUCCESS;
}
