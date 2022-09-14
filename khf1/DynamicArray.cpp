#include "DynamicArray.hpp"
#include <iostream>

DynamicArray::DynamicArray(int max_size):
AbstractArray(max_size) {
    if(max_size< 0){
         exit(0);
    }
    else {
        array_ptr = new int[max_size];
    }
}

DynamicArray::~DynamicArray(){
    delete [] array_ptr;
}

int& DynamicArray:: operator[] (int num) {
    return array_ptr[num];
    //auto i =mem_size();
}

void DynamicArray::push_back(int num) {
    if(act_size == max_size-1) {
        max_size *= 2;
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

