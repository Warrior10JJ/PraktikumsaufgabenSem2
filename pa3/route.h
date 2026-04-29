#ifndef PRAKTIKUM_ROUTE_H
#define PRAKTIKUM_ROUTE_H
#include <functional>
#include <vector>
#include <boost/function/function_template.hpp>


class Route {
  private:
    std::vector<std::pair<float, float>>* destinations;
    float height;
    std::function<float(float, float, float, float, float)> dist;
  public:
  //constructor
  Route(float pHeight, std::function<float(float, float, float, float, float)> pDist);
  //copy constructor
  Route(Route& route);
  //deconstructor
  ~Route();
  //methoden
  void add(const float destX, const float destY);
  const std::vector<std::pair<float, float>>& getDestinations() const;
  float getHeight() const;
  void setHeight(const float pHeight);
  void setDist(const std::function<float(float, float, float, float, float)> &pDist);
  float distance()const;
  Route shortestRoute();
};





#endif
