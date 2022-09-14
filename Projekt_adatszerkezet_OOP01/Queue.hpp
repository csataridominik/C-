//
// Created by hajda2 on 2021. 09. 30..
//

#ifndef HF1_QUEUE_HPP
//#include "Shop.hpp"
#define HF1_QUEUE_HPP

template <class T>
class Queue {
public:
  Queue();
  virtual ~Queue();
  virtual void in(T new_item);
  virtual T out();
  virtual T first() const;
  virtual bool isEmpty() const;
  virtual void print() const;


  //friend class Shop;


protected:
    struct Node {
    T value;
    Node *pNext;
    Node *pPrev;


    Node() : value(), pNext(nullptr), pPrev(nullptr) {}
    Node(T _value) : value(_value), pNext(nullptr), pPrev(nullptr) {}
    Node(T _value, Node *_pNext) : value(_value), pNext(_pNext) {}
  };

  Node *head, *tail;
    int count=0;
};

#endif //HF1_QUEUE_HPP
