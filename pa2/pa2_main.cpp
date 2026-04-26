#include <iostream>
#include <vector>
#include <string>
#include "vertical.h"
#include "ballistic.h"
#include "ufo.h"

int main() {
    // 1. Objekte mit 'new' auf dem Heap anlegen
    Ufo* vert = new Vertical("V-Unit-01");
    Ufo* ball = new Ballistic("B-Unit-99", 30.0f, 60.0f);

    //vector
    std::vector<Ufo*> ufos = { vert, ball };

    // konsoleneingabe
    int index;
    std::cout << "Welches Ufo soll fliegen? (0 für Vertical, 1 für Ballistic): ";
    std::cin >> index;

    //
    if (index >= 0 && index < static_cast<int>(ufos.size())) {
        std::cout << "Ufo " << ufos[index]->getId() << " startet den Flug..." << std::endl;

        // flug

        ufos[index]->flyToDest(100.0f, 200.0f, 50.0f, 10);

        std::cout << "Flug beendet. Aktuelle Position: ";
        std::vector<float> pos = ufos[index]->getPosition();
        std::cout << "X: " << pos[0] << " Y: " << pos[1] << " Z: " << pos[2] << std::endl;
    } else {
        std::cerr << "Ungueltiger Index!" << std::endl;
    }

    return 0;
}
