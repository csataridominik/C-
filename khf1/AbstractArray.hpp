#ifndef ABSTRACTARRAY_HPP_INCLUDED
#define ABSTRACTARRAY_HPP_INCLUDED

class AbstractArray {
public:
	AbstractArray();
	AbstractArray(int max_size);
	virtual ~AbstractArray();

	virtual int& operator[](int i) = 0;

	int size() const;
    int mem_size() const;
	virtual void push_back(int var) = 0;

protected:
	int act_size;
	int max_size;

};

#endif // ABSTRACTARRAY_HPP_INCLUDED
