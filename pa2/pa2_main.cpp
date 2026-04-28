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
    int zahl = 0;
    std::cin >> zahl;
    std::cout << zahl << std::endl;

    return 0;
}
