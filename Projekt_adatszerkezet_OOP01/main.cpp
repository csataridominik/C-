// your solution comes here
#include "Shop.hpp"
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "woodpecker.hpp"

#include <iostream>
#include <fstream>
#include <iterator>
#include <random>

std::string reader(const char* filename) {
  std::string* text = new std::string();
  std::string line;
  std::ifstream file;
  file.open(filename);
  while (getline(file,line))
  {
    (*text) += (line + "\n");
  }
  file.close();
  return (*text);
}

TEST("small test", 1) {
  {
    Shop s = Shop(std::string("../input2.txt"));
    while(s.next());

    s.result("../result.txt");
    CHECK_EQ(reader("../result.txt"), reader("../reference.txt"));
  }
}

WOODPECKER_TEST_MAIN(-1, -1)
