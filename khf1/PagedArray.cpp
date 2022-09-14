#include "PagedArray.hpp"
#include <iostream>


PagedArray::PagedArray(int max_size):
AbstractArray(max_size) {
    if(max_size< 0){
        exit(0);
    }
    else {
        array_ptr = new int[max_size];
        initialSize = max_size;
    }
}

PagedArray::~PagedArray(){
    delete [] array_ptr;
}

int& PagedArray:: operator[] (int num) {
    return array_ptr[num];
}

void PagedArray::push_back(int num) {
    if(act_size == max_size-1) {
        max_size += initialSize;
        int* temp = new int[max_size];
        for (int i = 0; i < act_size; i++) {
            temp[i] = array_ptr[i];
        }

        delete [] array_ptr;
        array_ptr = temp;
    }
    array_ptr[act_size] = num;
    act_size++;
}