//
// Created by hajda2 on 2021. 09. 25..
//
#ifndef HF1_KPRIORITYQUEUE_HPP
#define HF1_KPRIORITYQUEUE_HPP

#include "Queue.hpp"
#include "Customer.hpp"


template <class T>
class KPriorityQueue : public Queue<T> {

public:
    KPriorityQueue(long double k_, unsigned short length_);
    ~KPriorityQueue();
    void in(T new_item);
    void print() const;
    unsigned long time_to_finish(Customer value) const;
    unsigned short max_size() const;
    unsigned short current_size() const;
    T out();

    friend class Shop;


protected:
    long double k;
    unsigned short length;
    unsigned short curr;


};

#endif //HF1_KPRIORITYQUEUE_HPP
