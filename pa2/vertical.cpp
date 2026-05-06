#include "vertical.h"
#include <cmath>




using namespace std; // std:: ersetzt


// constructor ID, Typ
Vertical::Vertical(const string& pId) : Ufo(pId){
}

//destructor
Vertical::~Vertical() {
}







//methoden

void Vertical::flyToDest(const float x,const float y,const float height,const int speed){ // zu kooridnaten mit gegebener geschwindigkeit

    int speed2 = speed;  //static_cast<int>(std::round(speed)); //rounded float to int

    //Aufstieg
    sim->flyTo(sim->getX(), sim->getY(), height, speed2, 0);
    //FLug
    sim->flyTo(x, y, height, speed2, 0);
    //landung
    sim->flyTo(x, y, 0.0, speed2, 0);
}







//ende methoden