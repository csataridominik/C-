//
// Created by balin on 9/22/2021.
//

#ifndef INC_03_HAZI_REF_PSTACK_H
#define INC_03_HAZI_REF_PSTACK_H
#include "pstack_exceptions.h"

template <typename T>

class Pstack {
private:
    struct Node {
        T* data;
        struct Node* pNext;
        // ez egy láncolt lista egy eleme (lásd órai anyag)
    };
    Node* pHead; // Ez pedig a teteje
    int capacity;
    int currCapacity;
public:

    // Lehet felső korlát nélkül is létrehozni
    Pstack(){
        struct Node* pNext = NULL;
        pHead = NULL;
        currCapacity=0;
    }

    // Vagy felso korláttal
    Pstack(int capacity_) {
        if(capacity_<=0) {
            exit(0);
        }

        pHead = NULL;
        capacity= capacity_;
        currCapacity=0;
    }

    // A push berak egy elemere mutató pointert a verem tetejere. Ha nem sikerul méretkorlát miatt, akkor OverFlowException-t dob
    void push(T *new_item) {

        if(currCapacity == capacity){

            throw OverFlowException();
        }
        else {
            Node* temp = new Node;
            temp->data = new_item;
            //std::cout<<*new_item<<"   -   "<<*temp->data<<std::endl;
            temp->pNext = pHead;
            pHead = temp;

        }
        currCapacity +=1;

    }

    // Az isEmpty megmondja, hogy üres-e a verem
    bool isEmpty() const {
        return pHead ==NULL;
    }

    // A pop visszaadja a legfelső elemre mutató pointert és törli a láncolt lista legfelső elemét veremből. Ha üres a lista UnderFlowException-t dob.
    T* pop() {
        if(isEmpty()){
            throw UnderFlowException();
        }

        T* CurrTop=pHead->data;
        Node * temp = pHead;
        pHead = pHead->pNext;

        currCapacity -=1;
        delete temp;

        return CurrTop;
    }

    // A reverse() megfordítja a verem sorrendjét
    void reverse() {
        if(isEmpty()){
            throw UnderFlowException();
        }
        Node* temp= pHead;
        Node *prev = NULL, *next = NULL;

        while(temp != NULL) {
            next = temp->pNext;
            temp->pNext = prev;

            prev = temp;
            temp =next;

        }
        pHead = prev;
     }
};

#endif //INC_03_HAZI_REF_PSTACK_H
