#ifndef ARRAY_HPP_INCLUDED
#define ARRAY_HPP_INCLUDED

#include "AbstractArray.hpp"

class DynamicArray: public AbstractArray {
public:
    DynamicArray(int max_size);
    ~DynamicArray();

    int& operator[](int num);

    void push_back(int num);

protected:
    int* array_ptr;


};

#endif // ARRAY_HPP_INCLUDED
