//
// Created by morak on 2021. 11. 17..
//

#ifndef SOLUTION_DUAL_SORT_H
#define SOLUTION_DUAL_SORT_H


#include <cmath>
#include <math.h>
#include <iostream>
#include <vector>

/**
 * dual_sort fv a  megadott tartomanyon talalhato elemeket
 * rendezi novekvo sorrendbe.
 *
 * @param data rendezendo vektor
 * @param N rendezendo vektor merete
 */



/**
 *
 * @file heap.hpp
 * @author tekda
 * Max-kupac adatszerkezet iterátorokkal
 * Prioritásos sor csomagolóosztály, kupaccal
 *
 */


template <class I> bool validateHeap(I first, I last);

template <class T> class Heap {

    std::vector<T> v;

    void liftUp(std::size_t index) {
        if (index >= v.size()) {
            throw std::exception();
        }

        std::size_t parent = getParent(index);

        while (index != 0 && v[parent] < v[index]) {
            std::swap(v[parent], v[index]);
            index = parent;
            parent = getParent(index);
        }
    }

    void liftDown(std::size_t index) {
        if (index >= v.size()) {
            throw std::exception();
        }

        size_t left_child = leftChild(index), right_child = rightChild(index);

        while ((right_child < v.size() && v[index] < v[right_child]) ||
        (left_child < v.size() && v[index] < v[left_child])) {
            if (right_child < v.size() && v[left_child] < v[right_child]) {
                std::swap(v[right_child], v[index]);
                index = right_child;
            } else {
                std::swap(v[left_child], v[index]);
                index = left_child;
            }
            left_child = leftChild(index);
            right_child = rightChild(index);
        }
    }

    std::size_t getParent(std::size_t index) { return (index - 1) / 2; }

    std::size_t leftChild(std::size_t index) { return 2 * index + 1; }

    std::size_t rightChild(std::size_t index) { return 2 * index + 2; }

public:
    Heap() {}
    Heap(const std::vector<T> &v_) : v(v_) {
        for (int i = static_cast<int>(v.size() / 2) - 1; i >= 0; --i)
            liftDown(i);
    }

    bool empty() const { return v.empty(); }

    size_t size() const { return v.size(); }


    void push(T item) {
        v.push_back(item);
        liftUp(v.size() - 1);
    }


    const T &top() const {
        if (empty()) {
            throw std::exception();
        }
        return v[0];
    }


    void pop() {
        if (!empty()) {
            std::swap(v[0], v[v.size() - 1]);
            v.pop_back();

            if (!empty()) {
                liftDown(0);
            }
        } else {
            throw std::exception();
        }
    }


    void validate(bool print = false) const {
        if (print) {
            for (unsigned int i = 0; i < v.size(); ++i)
                std::cout << v[i] << " ";
            std::cout << std::endl;
        }
        std::cout << "A vektor"
        << (validateHeap(v.begin(), v.end()) ? " " : " NEM ")
        << "teljesiti a kupac-tulajdonsagot!" << std::endl;
    }

    bool check() const { return validateHeap(v.begin(), v.end()); }
};

template <class I> bool validateHeap(I first, I last) {
    if (last > first) {
        for (int i = 0; i < (last - first) / 2; ++i) {
            if ((first + 2 * i + 1) < last && *(first + i) < *(first + 2 * i + 1))
                return false;
            if ((first + 2 * i + 2) < last && *(first + i) < *(first + 2 * i + 2))
                return false;
        }
        return true;
    } else
        throw std::exception();
}


template <class T>
void heapSort(std::vector<T> &v) {
    Heap<T> heap(v);

    for (std::size_t i = 0; i < v.size(); ++i) {
        v[v.size() - i - 1] = heap.top();
        heap.pop();
    }
}

void swapInt(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int divide(int *a, int down, int up) {

    int pivot = a[down];
    int left = down;
    int right = up;

    while (left < right) {
        while (a[left] <= pivot && left < up) {

            left = left + 1;
        }
        while (a[right] >= pivot && right > down) {

            right = right - 1;
        }
        if (left < right) {
            swapInt(a[left], a[right]);
        }
    }
    a[down] = a[right];
    a[right] = pivot;
    return right;
}


//Bool-lal tér vissza, ha eléri a depth-et rekurzióban igazzal tér vissza, átvált heapre.
bool quickSort(int *A, int down, int up, int depth) {

    if(depth < 0){
        return true;
    }

    bool b1,b2;

    if (down < up) {

        depth =depth-1;

        int q = divide(A, down, up);
        b1=quickSort(A, down, q - 1,depth);
        b2=quickSort(A, q + 1, up,depth);

    }
    if(b1 || b2){
        return true;
    } else {
        return false;
    }
}

void dual_sort(std::vector<int> &data, int N) {
    int depth;
    depth= 2* int(log2(N));
    if(quickSort(&data[0],0,N-1,depth) ) {
        heapSort(data);
    }

}

#endif //SOLUTION_DUAL_SORT_H
