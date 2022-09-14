//
// Created by hajda2 on 2021. 09. 30..
//
#include "Queue.hpp"
#include "listexception.hpp"
#include "Customer.hpp"
#include <iostream>

template <class T>
Queue<T>::Queue() {
        count =0;

}

template <class T>
Queue<T>::~Queue() {
    while(!isEmpty()) {
        out();
    }
}

template <class T>
void Queue<T>::in(T new_item) {
    Node* temp = new Node(new_item);

    if(this->isEmpty()) {
        head = temp;
        tail = temp;
    }
    else {
        temp->pPrev = tail;
        tail->pNext = temp;
        tail = temp;
    }

    ++count;
}




template <class T>
T Queue<T>::out() {
    if(isEmpty()){
          throw UnderFlowException();
    }

    T firstInLine = head->value;
    if(this->head->pPrev== nullptr) {
    }
    Node* temp = head;
    head = temp->pNext;

    delete temp;
    --count;

    return firstInLine;

}

template <class T>
T Queue<T>::first() const {
    return head->value;
}

template <class T>
bool Queue<T>::isEmpty() const {
    return count ==0;
}

template <class T>
void Queue<T>::print() const {
    Node * temp = head;

    while(temp != tail) {
        T c = temp->value;
        std::cout<<c;
        std::cout<<std::endl;
        temp =temp->pNext;
    }
}