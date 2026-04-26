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

    virtual void flyToDest(const float x,const float y,const float height,const int speed)=0 ;

    static std::vector<float> wayPoint(const float x1,const float y1,const float x2,const float y2,const float h,const float phi);
};
#endif //PRAKTIKUM_UFO_H
