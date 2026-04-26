#ifndef PRAKTIKUM_BALLISTIC_H
#define PRAKTIKUM_BALLISTIC_H
#include "ufo.h"


class Ballistic :public Ufo {
private:
    float takeOffAngle;
    float landingAngle;

public:
    //construktor
    Ballistic(const std::string& pId,const float takeOffAngle,const float landingAngle);

    //destruktor
    ~Ballistic();

//methodes
    float getTakeOffAngle() const;
    float getLandingAngle() const;
    void flyToDest(const float x,const float y,const float height,const int speed) override;
    std::vector<float> firstWaypoint(const float x,const float y,const float height) const;
    std::vector<float> secondWaypoint(const float x,const float y,const float height) const;

};














#endif //PRAKTIKUM_BALLISTIC_H
