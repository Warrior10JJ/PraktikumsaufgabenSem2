

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
    this->destinations->emplace_back(destX, destY);
}

const std::vector<std::pair<float, float>>& Route::getDestinations() const {
    return *destinations;
}

float Route::getHeight() const {
    return height;
}

void Route::setHeight(const float pHeight) {
    this->height = pHeight;
}

void Route::setDist(const std::function<float(float, float, float, float, float)> &pDist) {
    this->dist = pDist;
}

float Route::distance() const {
    if (destinations->empty()) { //falls destinations leer kein flug
        return 0;
    }
    float gesdistance = 0 ;
    float current_x = 0;
    float current_y = 0;

    for (const auto& target : *destinations) { //for schleife ruft alle ziele nacheienander auf
        float next_x = target.first;
        float next_y = target.second;


        gesdistance += dist(current_x, current_y, next_x, next_y, height);//dist für gesamtdistanz


        current_x = next_x; // actuelle pos aktualisieren
        current_y = next_y;
    }
    //zurueck zzu 0/0/0
    gesdistance = gesdistance+dist(current_x, current_y, 0, 0, height);

    return gesdistance;
}

Route Route::shortestRoute() {
    Route besteRoute(*this); //Kopie der route
    std::sort(destinations->begin(), destinations->end());
    float mindistance = this->distance();
    std::vector<std::pair<float, float>> bestfolge = *destinations;// speicherung der aktuell besten routenrheinfolge

    while (std::next_permutation(destinations->begin(), destinations->end())){
        float currlenght = this->distance();
        if (currlenght < mindistance) {
            mindistance = currlenght;
            bestfolge = *destinations;
        }
    }

    *(besteRoute.destinations) = bestfolge;

    return besteRoute;

}
