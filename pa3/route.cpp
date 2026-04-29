

#include "route.h"
//constructor
Route::Route(float pHeight, std::function<float(float, float, float, float, float)> pDist) {
}
//copyconstructor
Route::Route(Route &route) {
}
//deconstructor
Route::~Route() {
}


//methoden
void Route::add(const float destX, const float destY) {

}

std::vector<std::pair<float, float>> * Route::getDestinations() const {
}

float Route::getHeight() const {
}

void Route::setHeight(const float pHeight) {
}

void Route::setDist(std::function<float(float, float, float, float, float)> pDist) {
}

float Route::distance() {
}

Route Route::shortestRoute() {
}
