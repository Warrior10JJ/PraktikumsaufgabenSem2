#include "ufo.h"
#include <cmath>

//constructor mit speedup
Ufo::Ufo(const std::string &pId) : id(pId){
    sim = new Ufosim();
    sim->setSpeedup(4);
}
//deconstruktor
Ufo::~Ufo() {
    delete sim;
}

const std::string & Ufo::getId() const {
return id;
}


std::vector<float> Ufo::getPosition() const {
return {this->sim->getX(), this->sim->getY(),this->sim->getZ()};
}

float Ufo::getFtime() const {
    return this->sim->getFtime();
}

std::vector<float> Ufo::wayPoint(const float x1,const float y1,const float x2,const float y2,const float h,const float phi) {
    //h ist gegenkathete
    float phirad = phi * (M_PI/ 180.0f);//rechnet phi in radial um
    float hypotenuse = h/sin(phirad); //länge e
    float abe = sqrt((hypotenuse*hypotenuse)-(h*h)); //a,b,entfernung entferung mit phytaghoras
    float dx  = x2 - x1; //entfernung ad in x
    float dy  = y2 - y1; //entfernung ad in y

    float ade = sqrt(dx * dx + dy * dy); //a,d entfernung mit phytagoras

    // b liegt auf gerade ad, also factor abe auf jeweils x und y
    float bx = x1 + (dx / ade) * abe;  //faktor abe auf die entfernung con a zu d unter x
    float by = y1 + (dy / ade) * abe;  //faktor abe auf die entfernung con a zu d unter y

    return {bx, by};
}



