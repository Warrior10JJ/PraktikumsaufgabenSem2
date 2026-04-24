#ifndef VERTICAL_H
#define VERTICAL_H

#include <string>
#include <vector>
#include "ufosim.h"



//Vorward declertion of ufosim
class Ufosim;

class Vertical {
private:
    static const std::string type;
    std::string id;
    Ufosim* sim;

public:
    // constructor
    Vertical(const std::string& pId);
   
    // destructor
    ~Vertical();

    // getter
    static std::string getType();
    
    const std::string& getId() const;
    
    std::vector<float> getPosition() const;
    
    float getFtime() const;
    // methode
    void flyToDest(const float x, const float y, const float height, const float speed);
    static std::vector<float> wayPoint(const float x1, const float y1, const float x2, const float y2, const float h, const float phi);
};







#endif