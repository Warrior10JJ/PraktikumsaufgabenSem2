//
// Created by JJ_of on 24.04.2026.
//

#include "ballistic.h"

Ballistic::Ballistic(std::string &pId, float takeOffAngle, float landingAngle) : Ufo(pId) {
    if (0 < takeOffAngle && takeOffAngle <= 90) {
        takeOffAngle = 45;
    }
    if (0 < landingAngle && landingAngle <= 90) {
        landingAngle = 45;
    }
}

Ballistic::~Ballistic() {
}

float Ballistic::getTakeOffAngle() {
return takeOffAngle;
}

float Ballistic::getLandingAngle() {
return landingAngle;
}

void Ballistic::flyToDest(float x, float y, float height, int speed) {
}

std::vector<float> Ballistic::firstWaypoint(float x, float y, float height) const{//ersten waypoint berechnen, ufo position bis höhe
    float currentx = sim->getX();
    float currenty = sim->getY();




    return (x1,y2);
}

std::vector<float> Ballistic::secondWaypoint(float x, float y, float height) const{
}
