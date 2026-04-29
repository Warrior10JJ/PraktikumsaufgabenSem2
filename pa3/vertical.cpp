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

    int speed2 = static_cast<int>(std::round(speed)); //rounded float to int

    //Aufstieg
    sim->flyTo(sim->getX(), sim->getY(), height, speed2, 0);
    //FLug
    sim->flyTo(x, y, height, speed2, 0);
    //landung
    sim->flyTo(x, y, 0.0, speed2, 0);
}

float Vertical::distance(const float x1, const float y1, const float x2, const float y2, const float h) {
float gesdistance = h*2; //gesamtdistanc erechnen, ufo started hoch und landed also ersdtmal 2 h
    float diffx = x1 - x2; // differnez x
    float diffy = y1 - y2; // differenz y
    float diffxpos = std::sqrt(diffx*diffx); //x positiv machen
    float diffypos = std::sqrt(diffy*diffy); //y positiv machen
    gesdistance = gesdistance + (diffxpos + diffypos);
    return gesdistance;
    // alternativ: return (h*2)+std::sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


//ende methoden