#include <iostream>
#include <vector>
#include <string>
#include "vertical.h"
#include "ballistic.h"
#include "ufo.h"

int main() {
    //2 neue Objekte auf dem heap
    Ufo* vert = new Vertical("V-011");
    Ufo* ball = new Ballistic("B-12", 30,40);

    //vector
    std::vector<Ufo*> ufos = { vert, ball };
    //konsoleneingabe#
    while (1) {
        int zahl = 0;
        std::cout << "0 = Vertical, 1 = Ballistic (Standart = Vertical) / 2 = Exit Sim" << std::endl;
        std::cin >> zahl;
        //bsp für vektornutzung ufos[zahl]->flyToDest(10,10,3,7);
        if (zahl == 2) {
            std::cout << "Wird Abgebrochen ..." << std::endl;
            break;
        }


        if (zahl != 0 && zahl != 1) {
            zahl = 0;
        }
        if (zahl == 0) {
            std::cout << "Zahl " << zahl << " wurde Gewaehlt, Vertical gestartet" << std::endl;
            vert->flyToDest(10,10,3,7);
        }else {
            std::cout << "Zahl " << zahl << " wurde Gewaehlt, Ballistic gestartet" << std::endl;
            ball->flyToDest(10,10,3,7);
        }
    }


    return 0;
}
