//
// Created by JJ_of on 24.04.2026.
//

#include "ballistic.h"

Ballistic::Ballistic(const std::string &pId, float takeOffAngle, float landingAngle) : Ufo(pId) {
    if (0 < takeOffAngle && takeOffAngle <= 90) {
        this->takeOffAngle = takeOffAngle;
    }else {
        this->takeOffAngle = 45; //winkel auf 45 falls parameter überschritten
    }
    if (0 < landingAngle && landingAngle <= 90) {
        this->landingAngle = landingAngle;
    }else {
        this->landingAngle = 45;//winkel auf 45 falls parameter überschritten
    }
}


Ballistic::~Ballistic() = default;

float Ballistic::getTakeOffAngle() const {
return takeOffAngle;
}

float Ballistic::getLandingAngle() const {
return landingAngle;
}

void Ballistic::flyToDest(float x, float y, float height, int speed) {
    //Aufstieg
    std::vector<float> wp1 = firstWaypoint(x,y,height);
    sim->flyTo(wp1[0], wp1[1], height, speed, speed);
    //FLug
    std::vector<float> wp2 = secondWaypoint(x,y,height);
    sim->flyTo(wp2[0], wp2[1], height, speed, speed);
    //landung
    sim->flyTo(x,y,0, speed, 0);
}

std::vector<float> Ballistic::firstWaypoint(float x, float y, float height) const {//ersten waypoint berechnen, ufo position bis höhe
    return wayPoint(sim->getX(), sim->getY(), x, y, height, takeOffAngle);
}

std::vector<float> Ballistic::secondWaypoint(float x, float y, float height) const {
    return wayPoint(x, y, sim->getX(), sim->getY(), height, landingAngle);
}
