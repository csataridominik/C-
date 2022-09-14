//
// Created by hajda2 on 2021. 09. 25..
//
#include "KPriorityQueue.hpp"
#include "Queue.cpp"
#include "listexception.hpp"


template <class T>
KPriorityQueue<T>::KPriorityQueue(long double k_, unsigned short length_) {

    k=k_;
    length=length_;
    curr=0;
    this->count =0;
}

template <class T>
unsigned short KPriorityQueue<T>::max_size() const {
    return length;
}

template <class T>
T KPriorityQueue<T>::out(){
    --curr;
    return Queue<T>::out();
}

template <class T>
unsigned short KPriorityQueue<T>::current_size() const {
    return curr;
}


template <class T>
KPriorityQueue<T>::~KPriorityQueue() {
    while(!this->isEmpty()) {
        out();
    }


}


template <class T>
void KPriorityQueue<T>::in(T new_item) {
            if( curr >= max_size()) {
                throw OverflowException();
            }

            if(this->isEmpty()) {
                ++curr;
                Queue<T>::in(new_item);

            } else {
                auto *temp = this->tail;

                //Végig iterál a pénztáron és emgnézi, hova tudja lerakni. Ahol a head-del helyet csserél, vagy a head.pNext-et változtatja
                //külön kezeljük. Ez előfordul curr==1-nél, vagy ha a végére ér az iterátor
                while (temp != nullptr) {
                    //Második elemet tűzzük be, vagy head elé v tail-nek
                    if(curr == 1) {
                        auto *return_ = new KPriorityQueue<Customer>::Node(new_item);
                        if(new_item.priority > this->head->value.priority * this->k &&
                           this->head->value.current_product_num == this->head->value.all_product_num){


                            return_->pNext = this->head;
                            this->head->pPrev = return_;
                            this->head = return_;

                        } else {

                            return_->pPrev = this->head;
                            this->head->pNext = return_;
                        }
                        break;

                    }

                    if(new_item.priority  > temp->value.priority* this->k && new_item.priority <= temp->pPrev->value.priority* this->k) {
                        auto *return__ = new KPriorityQueue<Customer>::Node(new_item);
                        return__->pPrev = temp->pPrev;

                        temp->pPrev = return__;


                        return__->pNext= temp;
                        break;
                    }

                    //ha elérkeztünk a head elé(curr>1) vagy a head-hez (megedgethetjük, hogy nem ellenőrizzük else-be,
                    // hogy biztos oda illik, ttf()-ben megnéztük, hogy itt van a legjobb helye)
                    if(temp->pPrev == this->head || temp->pPrev == nullptr) {

                        auto *return_ = new KPriorityQueue<Customer>::Node(new_item);
                        if(this->head->value.current_product_num == this->head->value.all_product_num
                        && new_item.priority  > this->head->value.priority * this->k) {


                            return_->pNext = this->head;
                            this->head->pPrev = return_;

                            return_->pPrev = nullptr;
                            this->head = return_;


                        } else {
                            return_->pPrev = this->head;
                            this->head->pNext =return_;
                            return_->pNext = temp;
                            temp->pPrev = return_;

                        }

                        break;
                    }

                    temp = temp->pPrev;

                }

                ++curr;
                this->count +=1;


                //tail újra kiválasztása, ha valamelyik elem tail elé eggyel, vagy tail helyére került volna
                auto *temp2 = this->head;
                for(int i =0; i<curr-1; ++i) {
                    temp2 =temp2->pNext;
                }
                if(this->tail != temp2){
                    temp2->pPrev= this->tail->pPrev;
                    temp2->pNext= nullptr;
                    this->tail = temp2;
                }

            }
}

template <class T>
void KPriorityQueue<T>::print() const {
    KPriorityQueue<T>::print();

}

template <class T>
unsigned long KPriorityQueue<T>::time_to_finish(Customer c) const {
//in()-hez hasonló módon keressük a legmegfelelőbb(min-> timeSpent) pénztárat a Customer-nek
    auto *temp = this->tail;


    int timeSpent=0;
    bool addUp = false;

    for(int j=0; j< this->curr; ++j) {
    if(temp == nullptr){
        break;
    }

    if(curr==1){
        if(this->head->value.all_product_num == this->head->value.current_product_num
        && c.priority  > this->head->value.priority* this->k){
            break;
        } else {
            timeSpent +=this->head->value.current_product_num;
            break;
        }

    }


    if(temp->pPrev == this->head) {
        if(c.priority  > this->head->value.priority* this->k &&
        c.priority  >= this->head->pNext->value.priority* this->k &&
        this->head->value.all_product_num == this->head->value.current_product_num){
            break;
        } else if(c.priority  >= this->head->pNext->value.priority* this->k) {
            timeSpent +=this->head->value.current_product_num;
            break;
        } else {

            temp = this->tail;
            for(int s=0; s<curr; ++s) {
                timeSpent +=temp->value.current_product_num;
                temp = temp->pPrev;
            }
            break;
        }

        }

        if(addUp == false && (c.priority  > temp->value.priority* this->k && c.priority  < temp->pPrev->value.priority* this->k)) {
            addUp =true;
        }

        if(addUp) {
            timeSpent +=temp->value.current_product_num;
        }


        temp = temp->pPrev;
    }

    return timeSpent;

}