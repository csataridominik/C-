//
// Created by hajda2 on 2021. 09. 30..
//
#ifndef HF1_CUSTOMER_HPP
#define HF1_CUSTOMER_HPP
#include <fstream>
#include <iostream>


struct Customer {
  const unsigned long id;
  unsigned short priority;
  const unsigned short all_product_num;
  unsigned short current_product_num;

  Customer() : id(0), priority(0), all_product_num(0), current_product_num(0){}
  Customer(unsigned long i, unsigned short p, unsigned short pn)
  : id(i), priority(p), all_product_num(pn), current_product_num(pn){}

  double operator*(const double &k) const { return k*(double)this->priority; }
  friend std::ostream &operator<<(std::ostream &o, const Customer &c) {return o << std::to_string(c.id);}
};

#endif //HF1_CUSTOMER_HPP
