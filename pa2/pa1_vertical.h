#ifndef PA1_VERTICAL_H
#define VERTICAL_H

#include <string>
#include <vector>
#include "ufo.h"



class Vertical :public Ufo {

public:
    // constructor
    Vertical(const std::string& pId);
   
    // destructor
    ~Vertical() override;


    // methode
    void flyToDest(const float x, const float y, const float height, const float speed) const;
    static std::vector<float> wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi);
};







#endif