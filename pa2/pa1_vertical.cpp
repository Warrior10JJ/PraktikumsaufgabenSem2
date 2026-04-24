#include "pa1_vertical.h"
#include <cmath>




using namespace std; // std:: ersetzt


// constructor ID, Typ
Vertical::Vertical(const string& pId) : Ufo() {
}

//destructor
Vertical::~Vertical() {
    delete sim;
}







//methoden

void Vertical::flyToDest(const float x, const float y, const float height, const float speed) { // zu kooridnaten mit gegebener geschwindigkeit
    //Aufstieg
    sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
    //FLug
    sim->flyTo(x, y, height, speed, 0);
    //landung
    sim->flyTo(x, y, 0.0, speed, 0);
}







//ende methoden