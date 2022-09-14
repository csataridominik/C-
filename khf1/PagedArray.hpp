#ifndef PAGEDARRAY_HPP_INCLUDED
#define PAGEDARRAY_HPP_INCLUDED

#include "AbstractArray.hpp"

class PagedArray: public AbstractArray {
public:
    PagedArray(int max_size);
    ~PagedArray();

    int& operator[](int num);

    void push_back(int num);

protected:
    int* array_ptr;
    int initialSize;
};

#endif // PAGEDARRAY_HPP_INCLUDED
