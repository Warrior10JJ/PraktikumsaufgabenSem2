//
// Created by JJ_of on 21.04.2026.
//

#ifndef PRAKTIKUM_UFO_H
#define PRAKTIKUM_UFO_H
#include <string>
#include <vector>

#include "ufosim.h"


class Ufo {
    private:
        std::string id;
    protected:
        Ufosim* sim;

    public:
    // constructor+ virtueller destruktor
    Ufo(const std::string& pId);
    virtual ~Ufo() = default;

    //getter
    const std::string& getId() const;
    std::vector<float> getPosition() const;
    float getFtime() const;

    virtual void flyToDest(float x, float y, float height, int speed)=0 ;

    static std::vector<float> wayPoint(float x1, float y1, float x2, float y2, float h, float phi);
};
#endif //PRAKTIKUM_UFO_H
