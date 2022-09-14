#include "AbstractArray.hpp"
#include <iostream>

AbstractArray::AbstractArray(int max_size) :
		act_size(0), max_size(max_size) {

}

AbstractArray::~AbstractArray() {

}

int AbstractArray::size() const {
	return act_size;
}

int AbstractArray::mem_size() const {
  return max_size;
}
