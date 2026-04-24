#include "vertical.h"
#include <cmath>
#include <numbers>


using namespace std; // std:: ersetzt

const string Vertical::type = "vertical";//Type als static variable
// constructor ID, Typ
Vertical::Vertical(const string& pId) : id(pId), sim(nullptr) {
    Ufosim::setSpeedup(4);
    sim = new Ufosim();
}

//destructor
Vertical::~Vertical() {
    delete sim;
}

//getter 

string Vertical::getType()  {
    return type;
}

const string& Vertical::getId() const {
    return id;
}

vector<float> Vertical::getPosition() const {
    float x = sim->getX();
    float y = sim->getY();
    float z = sim->getZ();
    return vector<float>{x, y, z};
}

float Vertical::getFtime() const { 
    return sim->getFtime(); 
}

//endgetter


//methoden

void Vertical::flyToDest(const float x, const float y, const float height, const float speed) { // zu kooridnaten mit gegebener geschwindigkeit
    //Aufstieg
    sim->flyTo(sim->getX(), sim->getY(), height, speed, 0);
    //FLug
    sim->flyTo(x, y, height, speed, 0);
    //landung
    sim->flyTo(x, y, 0.0, speed, 0);
}

vector<float> Vertical::wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi) { // berechnet koordinaten
    //A = x1,y1,0 D= x2,y2,0
   
    float phirad = phi * (M_PI/ 180.0f);//rechnet phi in radial um
    float hypotenuse = h/sin(phirad); //länge e
    float abe = sqrt((hypotenuse*hypotenuse)-(h*h)); //a,b,entfernung
    float dx  = x2 - x1; //entfernung ad in x
    float dy  = y2 - y1; //entfernung ad in y
    
    float ade = sqrt(dx * dx + dy * dy); //a,d entfernung

    // b liegt auf gerade ad, also factor abe auf jeweils x und y
    float bx = x1 + (dx / ade) * abe;  //faktor abe auf die entfernung con a zu d unter x
    float by = y1 + (dy / ade) * abe;  //faktor abe auf die entfernung con a zu d unter y

    return {bx, by};
}





//ende methoden