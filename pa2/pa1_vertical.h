#ifndef PA1_VERTICAL_H
#define PA1_VERTICAL_H

#include <string>
#include <vector>
#include "ufo.h"



class Vertical :public Ufo {

public:
    // constructor
    Vertical(const std::string& pId) ;
   
    // destructor
    ~Vertical() override;


    // methode
    void flyToDest(float x, float y, float height,int speed) override;
    static std::vector<float> wayPoint(float x1,float y1,float x2,float y2,float h,float phi);
};







#endif