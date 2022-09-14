#include "Shop.hpp"
#include "KPriorityQueue.cpp"
#include "listexception.hpp"
#include <iostream>
#include <fstream>
//#include <pair>

//template<class T>
Shop::Shop(std::string filename) {

    std::ifstream inn;
    inn.open(filename.substr());
    if(!inn) {
        std::cout << "Nincs elerheto dokumentum." << std::endl;
        exit(1);
    }

    unsigned int numberOfCashiers ;
    inn>> numberOfCashiers;

    if(numberOfCashiers<=0 || numberOfCashiers> 100){
        throw NotValidInput();
    }

    long double x;
    unsigned short length;

    for(unsigned int i=0; i<numberOfCashiers; ++i){
        inn>>x;
        inn>>length;
        if(x<1 || x>=2 ) {
            throw NotValidInput();
        }

        if(length<=0 || length>100 ) {
            throw NotValidInput();
        }

        KPriorityQueue<Customer> a=  KPriorityQueue<Customer>(x,length);
        cash_registers.push_back(a);


    }

    int numberOfCustomors;
    inn>>numberOfCustomors;
    if(numberOfCustomors <0 || numberOfCustomors>1000000) {
            throw NotValidInput();
    }

    for(int j=0; j< numberOfCustomors; ++j) {
        //unsigned tipusok nem lehetnek negatívak, így azok beolvasásánál nema dhatóak emg értéknek, nincs exception

        unsigned long id_;
        unsigned short priority_;
        unsigned short all_product_num_;
        inn>>id_;
        inn>>priority_;
        inn>>all_product_num_;

        if(priority_>1000 || all_product_num_<=0 || all_product_num_>30){
            throw NotValidInput();
        }


        Customer c= Customer(id_,priority_,all_product_num_);
        global_queue.in(c);
/*
        if((int)id_ != j+1) {
            throw NotValidInput();
        }
*/

    }

inn.close();
}

bool Shop::next(){

    if(!global_queue.isEmpty()) {
        for(unsigned int i=0; i<cash_registers.size(); ++i) {
            bool fillUp = true;

                while( fillUp){


                std::pair<int,int> highestScore;

                highestScore.first = 99*30; //max varakozas
                highestScore.second =-1;  // ha már a következő for ciklusba be megy, nullával tér vissza, így tail-nek betudja helyezni az új elemet


                for(unsigned int j=0; j<cash_registers.size(); ++j){
                    //minimum keresés
                    if(cash_registers[j].curr != cash_registers[j].max_size()) {
                        int x = cash_registers[j].time_to_finish(global_queue.first());

                        if( x < highestScore.first) {
                            highestScore.first = x;
                            highestScore.second = j;
                        }

                    }
                }

                if(-1 < highestScore.second) {
                    cash_registers[highestScore.second].in(global_queue.out());
                }
//minden üres helyet feltölt, ha az összes pénztár tele, kilép a while-ból
for( unsigned int asd =0; asd<cash_registers.size(); ++asd){
    if(cash_registers[asd].curr == cash_registers[asd].length) {
        fillUp =false;
        break;
    }
}


            }

        }
    }
    //WHILE() END--

    //akik a pénztárnál első helyen állnak, leolvasnak egy terméket.
    // ha a termékszámuk ==0, kiveszzük őket és a result sorba tűzzük
for(unsigned int k=0; k<cash_registers.size(); ++k){
    if(cash_registers[k].isEmpty()) {
        continue;
    }

    cash_registers[k].head->value.current_product_num-=1;

    if(cash_registers[k].head->value.current_product_num == 0) {
        auto *temp = cash_registers[k].head->pNext;

        //növeli a sorban végzett max termék számával a mögötte álló emberek prioritását
        for(int i=0; i<cash_registers[k].curr-1; ++i) {
            temp->value.priority += cash_registers[k].head->value.all_product_num;
            if(temp->value.priority >1000 ){
                temp->value.priority = 1000;
            }
            temp = temp->pNext;
        }
        resultQueue.push_back(cash_registers[k].out().id);

    }


}
    //Ha minden pénztár üres, visszatérünk
    for(unsigned int end=0; end<cash_registers.size(); ++end){
        if(!cash_registers[end].isEmpty() ) {
            return true;
        }
    }

      return false;

}

void Shop::result(std::string filename) const {
    std::ofstream outt;
    outt.open (filename.substr());

    for (auto it = resultQueue.begin(); it != resultQueue.end(); ++it){
        outt<< *it<<"\n";
    }

    outt.close();
}
