#include "vertical.h"
#include <cmath>

Vertical::Vertical(const std::string& pId) : id(pId) {
    Ufosim::setSpeedup(4);
}

std::vector<float> Vertical::getPosition() const {
    std::vector<float> pos(3);
    
    pos[0] = sim.getX();
    pos[1] = sim.getY();
    pos[2] = sim.getZ();
    
    return pos;
}

void Vertical::flyToDest(float x, float y, float height, float speed) {
    
    float startX = sim.getX();
    float startY = sim.getY();
    
    //1. hochfliegen
    sim.flyTo(startX, startY, height, speed, 0);
    
    //2. horizontale Bewegung
    sim. flyTo(x, y, height, speed, 0);
    
    //3. landen
    sim. flyTo(x, y, 0.0f, speed, 0);
    
}

std::vector<float> Vertical::wayPoint(float x1, float y1, float x2, float y2, float h, float phi) {
    
    float rad = phi * (M_PI / 180.0f);
    
    float dx = x2 - x1;
    float dy = y2 - y1;
    
    float distance = std::sqrt(dx * dx + dy * dy);
    
    float offset = h / std::tan(rad);
    
    float normX = dx / distance;
    float normY = dy / distance;
    
    float bx = x1 + normX * offset;
    float by = x2 + normY * offset;
    
    return {bx, by};
}