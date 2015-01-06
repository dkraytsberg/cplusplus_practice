#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char **argv){
  int width = atoi(argv[1]), height = atoi(argv[2]);
  std::ifstream myfile;

  int **grid = new int*[width];

  for(int i = 0; i < width; i++)
    grid[i] = new int[height];

  myfile.open(argv[3]);
  myfile >> grid[0][0];
  myfile >> grid[0][1];

  std::cout << grid[0][0] << std::endl;
  std::cout << grid[0][1] << std::endl;



}
