#ifndef PRAKTIKUM_BALLISTIC_H
#define PRAKTIKUM_BALLISTIC_H
#include "ufo.h"


class Ballistic :public Ufo {
private:
    float takeOffAngle;
    float landingAngle;

public:
    //construktor
    Ballistic(std::string& pId, float takeOffAngle, float landingAngle);

    //destruktor
    ~Ballistic() override;

//methodes
    float getTakeOffAngle();
    float getLandingAngle();
    void flyToDest(float x, float y, float height, int speed) override;
    std::vector<float> firstWaypoint(float x, float y, float height) const ;
    std::vector<float> secondWaypoint(float x, float y, float height) const;

};














#endif //PRAKTIKUM_BALLISTIC_H
