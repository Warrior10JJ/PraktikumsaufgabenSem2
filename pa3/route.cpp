#include "route.h"

//constructor
Route::Route(float pHeight, const std::function<float(float, float, float, float, float)> &pDist) {
    this->height = pHeight;
    this->dist = pDist;
    this->destinations = new std::vector<std::pair<float, float>>();
}

//copyconstructor
Route::Route(const Route &route) {
    this->height = route.height;
    this->dist = route.dist;

    if (route.destinations != nullptr) {
        this->destinations = new std::vector(*route.destinations);
    } else {
        this->destinations = new std::vector<std::pair<float, float>>();
    }

}
//deconstructor
Route::~Route() {
    if (this->destinations != nullptr) {//sit desinaitons da?
        delete this->destinations;
        this->destinations = nullptr;
    }
}


//methoden
void Route::add(const float destX, const float destY) const {
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
    double gesdistance = 0 ;
    float current_x = 0;
    float current_y = 0;

    for (const auto& target : *destinations) { //for schleife ruft alle ziele nacheienander auf
        float next_x = target.first;
        float next_y = target.second;


        gesdistance = gesdistance + dist(current_x, current_y, next_x, next_y, height);//dist für gesamtdistanz


        current_x = next_x; // actuelle pos aktualisieren
        current_y = next_y;
    }
    //zurueck zzu 0/0/0
    gesdistance = gesdistance+dist(current_x, current_y, 0, 0, height);

    return static_cast<float> (gesdistance);
}

Route Route::shortestRoute() const {
    Route copyroute(*this); //routencopy
    std::vector<std::pair<float, float>> copydestinations = *destinations;//arbeitscopy von destinations
    std::sort(copydestinations.begin(), copydestinations.end()); //copy sortieren


    std::vector<std::pair<float, float>> bestfolge = copydestinations;// speicherung der aktuell besten routenrheinfolge

    *copyroute.destinations = copydestinations; //routencop die sortierten destinations geben
    float mindistance = this->distance(); //momentan mindestdistanz
    while (std::next_permutation(copydestinations.begin(), copydestinations.end())){  //jede permutation durchgehen
        *copyroute.destinations = copydestinations;
        float currlenght = copyroute.distance();

        if (currlenght < mindistance) {         //austauschen
            mindistance = currlenght;
            bestfolge = copydestinations;
        }
    }

    *copyroute.destinations = bestfolge;//die beste rheinfolge in die copyroute setzen
    return copyroute;
}
