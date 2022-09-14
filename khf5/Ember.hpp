//
// Created by erdar2 on 2021. 10. 18..
//

#ifndef KISHF5_EMBER_HPP
#define KISHF5_EMBER_HPP


#include <string>
#include <vector>




class Ember {
    Ember *apa = nullptr, *anya= nullptr;
    std::vector<Ember*> leszarmazottak;
    std::string nev;

    void addGyerek(Ember *gyerek) {
        this->leszarmazottak.push_back(gyerek);
    }

public:
    //Ember() : nev("") {};
    Ember(std::string nev_): nev(nev_)  {};
/*
    void destroy(Ember* x) {



        if (x != nullptr) {

            destroy(x->anya);
            destroy(x->apa);
            delete x;
        }


    }

    ~Ember() {
      destroy(this);

    }*/

    std::vector<Ember*> getGyerekek() {
        return leszarmazottak;
    }

    Ember* getAnya(){
        return this->anya;
    }
    Ember* getApa(){
        return this->apa;
    }

    void setSzulok(Ember *apa_, Ember *anya_){

        this->apa= apa_;
        this->anya= anya_;

        this->anya->addGyerek(this);
        this->apa->addGyerek(this);

    }

    void helper(std::vector<std::string>& x, Ember *ember){

        if(ember-> anya == nullptr || ember-> apa == nullptr || x.size()>=63){
            return;
        }

        x.push_back(ember->anya->nev);
        x.push_back(ember->apa->nev);
        helper(x, ember->anya);
        helper(x, ember->apa);
    }

    bool rokon(Ember *ember) {

        std::vector<std::string> s1;
        s1.push_back(ember->nev);
        std::vector<std::string> s2;
        s2.push_back(this->nev);

        helper(s1, ember);
        helper(s2, this);

        for(unsigned int i=0; i<s1.size(); ++i) {

            for(unsigned j=0; j<s2.size(); ++j) {
                if(s1[i] == s2[j]){
                    return true;
                }
            }
        }

        return false;
    }
    std::string getNev(){
        return nev;
    };
};


#endif //KISHF5_EMBER_HPP
