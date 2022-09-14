#include <iostream>
#include "Ember.hpp"
#include "woodpecker.hpp"

TEST("Szülők teszt", 1) {
    {
        Ember *jozsi = new Ember("Józsi");
        Ember *feri = new Ember("Feri");
        Ember *eva = new Ember("Éva");
        feri->setSzulok(jozsi, eva);

        CHECK_EQ(feri->getAnya()->getNev() + "," + feri->getApa()->getNev(), "Éva,Józsi");
    }
}



TEST("Gyerekek teszt", 1) {
    {
        Ember *jozsi = new Ember("Józsi");
        Ember *mari = new Ember("Mari");
        Ember *bela = new Ember("Béla");
        bela->setSzulok(jozsi, mari);

        Ember *feri = new Ember("Feri");
        Ember *gabor = new Ember("Gábor");
        Ember *eva = new Ember("Éva");
        feri->setSzulok(jozsi, eva);
        gabor->setSzulok(jozsi, eva);

        std::string gyerekek = "";
        for(Ember *e: jozsi->getGyerekek()){
            gyerekek += e->getNev() + ",";
        }

        CHECK_EQ(gyerekek, "Béla,Feri,Gábor,");
    }
}



TEST("Rokonság teszt 1", 1) {
    {
        Ember *bela = new Ember("Béla");
        Ember *istvan = new Ember("István");

        CHECK_EQ(istvan->rokon(bela), false);
    }
}

TEST("Rokonság teszt 2", 1) {
    {
        Ember *jozsi = new Ember("Józsi");
        Ember *mari = new Ember("Mari");
        Ember *bela = new Ember("Béla");
        bela->setSzulok(jozsi, mari);

        CHECK_EQ(jozsi->rokon(bela), true);
    }
}

WOODPECKER_TEST_MAIN()