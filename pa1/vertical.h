#ifndef VERTICAL_H
#define VERTICAL_H

#include <string>
#include <vector>
#include "ufosim.h"

class Vertical {
    private:
    std::string id;
    Ufosim sim;
    
    public:
    Vertical(const std::string& pId);
    std::vector<float> getPosition() const;
    static std::string getType();
    const std::string& getId() const;
    float getFtime() const;
    
    void flyToDest(float x, float y, float height, float speed);
   
    static std::vector<float> wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi);
};


#endif