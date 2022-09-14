#ifndef FIXEDARRAY_HPP_INCLUDED
#define FIXEDARRAY_HPP_INCLUDED

#include <ostream>
#include "AbstractArray.hpp"



class FixedArray: public AbstractArray {
protected:
    int* array_ptr;
public:
    FixedArray(int max_size);
    ~FixedArray();

    int& operator[](int num);

    void push_back(int num);




};

#endif // FIXEDARRAY_HPP_INCLUDED
