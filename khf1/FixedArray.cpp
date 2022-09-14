#include <iostream>
#include "FixedArray.hpp"

FixedArray::FixedArray(int max_size):
    AbstractArray(max_size) {
            if(max_size>0) {
                array_ptr = new int[max_size];
            }
    }

FixedArray::~FixedArray() {
    delete [] array_ptr;
}


int& FixedArray:: operator[] (int num) {
    return array_ptr[num];
}


void FixedArray::push_back(int num) {
    if(act_size > max_size){
        exit(0);
    }
    else{
        array_ptr[act_size] = num;
        act_size++;
    }


}

