//
// Created by hajda2 on 2021. 09. 30..
//
#include <iostream>
#include <fstream>
#include "Shop.hpp"

std::string reader2(const char* filename) {
  std::string* text = new std::string();
  std::string line;
  std::ifstream file;
  file.open(filename);
  if(file.is_open()) {
    while (getline(file,line))
    {
      (*text) += (line + "\n");
    }
    file.close();
  }
  return (*text);
}

int mainn() {
  Shop s = Shop(std::string("../input2.txt"));
  while(s.next());
  s.result("../result.txt");
  std::cout << reader2("../result.txt");

  return 0;

}