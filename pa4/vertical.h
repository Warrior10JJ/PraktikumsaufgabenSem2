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
    ~Vertical();


    // methoden
    void flyToDest(const float x,const float y,const float height,const int speed) override;

    static float distance(const float x1, const float y1, const float x2, const float y2, const float h);

};







#endif