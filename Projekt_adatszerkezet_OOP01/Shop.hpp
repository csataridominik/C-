//
// Created by hajda2 on 2021. 09. 30..
//
#ifndef HF1_SHOP_HPP
#define HF1_SHOP_HPP

#include <vector>
#include <string>
#include "KPriorityQueue.hpp"
#include "Customer.hpp"
#include "Queue.hpp"
#include <list>

//template<class T>
class Shop {
  std::vector<KPriorityQueue<Customer>> cash_registers;
  Queue<Customer> global_queue;
  std::list<unsigned long> resultQueue;


public:
  Shop() = delete;
  Shop(std::string filename);

  // Azt adja vissza, hogy van-e még vásárló a boltban
  bool next();
  void result(std::string filename) const;
};

#endif //HF1_SHOP_HPP
