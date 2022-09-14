//
// Created by morak on 2021. 09. 30..
//

#ifndef KHF3_SKELETON_HOSPITALQUEUE_H
#define KHF3_SKELETON_HOSPITALQUEUE_H

#include <iostream>

#include "exceptions.h"

//Korhazi sor adatszerkezete
class HospitalQueue {
public:
    //Konstruktor
    HospitalQueue():head(nullptr), tail(nullptr), emp(true), count(0){};
    ~HospitalQueue() {
        while(!isEmpty()) {
            out();
        }
    }

    //Sor vegere elemet rak. Az elem neve a "new_name", az elem csoportja a "new_group"
    void in(std::string new_name, std::string new_group){
      //  std::cout<<new_name<<"     : IN NAME"<<std::endl;

        Node* temp = new Node;
        temp->name = new_name;
        temp->group = new_group;
        temp->pNext = nullptr;
        if(isEmpty()) {
            head = temp;
            tail = temp;

            emp= false;
        }
        else {
            tail->pNext = temp;
            tail = temp;
        }

       // std::cout<<head->name<<"     : IN HEAD"<<std::endl;

        ++count;
    }

    //Sor elejerol elemet kivesz. Visszateresi erteke a beteg neve. Ha ures a sor akkor "UnderFlowException"-t dob
    std::string out() {
        if(isEmpty()){
            throw UnderFlowException();
        }

        std::string firstInLine = head->name;

        Node* temp = head;
        head = temp->pNext;
        delete temp;
        --count;

        if(isEmpty()) {
            emp =true;
        }

        return firstInLine;

    }

    //Sor elso elemenek nevet adja vissza
    std::string first() const {
        if(isEmpty()){
            throw UnderFlowException();
        }

        return head->name;
    }

    void print() const {
        Node *print = head;
        for(int i=0; i<count; ++i) {
            std::cout<< print->name<<std::endl;
            print =print->pNext;
        }

    }

    //Sor ures-e
    bool isEmpty() const {
        return count == 0;
    }

    //Sor rendezese megadott csoport ("group") alapjan
    void order(const std::string& group) {

        Node * curr = head;
        Node * prev = head, * next = NULL;

        //while(curr != tail) {
        for(int j=0; j<count; ++j) {

            next = curr->pNext;
            if(curr->group == group) {
                curr->pNext = head;
                prev->pNext = next;
                head = curr;
                if(j == count-1) {

                    tail = prev;
                    prev->pNext = nullptr;

                }

                //std::cout<<head->pNext->pNext->pNext->pNext->pNext->name <<"   -   "<<std::endl;

                break;
            }

            prev = curr;
            curr = next;

        }

        prev=head;

        next = NULL;

        for(int i=0; i<count; ++i) {
            next = curr->pNext;

            if(curr->group != group) {
                tail->pNext= curr;
                tail = curr;

                prev->pNext = next;

            } else {
                prev = curr;
            }
            curr = next;
        }
        //delete next;
        tail->pNext = nullptr;
      //  print();
    }

private:
    struct Node {
        //A sor egy eleme, ami tartalmazza a beteg nevet es csoportjat
        std::string name;
        std::string group;
        struct Node* pNext;

    };

    //A sor eleje es vege
    Node *head, *tail;
    bool emp;
    int count;
};

#endif //KHF3_SKELETON_HOSPITALQUEUE_H
