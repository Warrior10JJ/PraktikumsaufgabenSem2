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
  Route(float pHeight, const std::function<float(float, float, float, float, float)> &pDist);
  //copy constructor
  Route(const Route& route);
  //moveconstructor
  Route(Route &&route) noexcept;//noexception thrown, constructor is save and can be treusted so fast
  //deconstructor
  ~Route();
  //methoden
  void add(float destX, float destY) const;
  [[nodiscard]] const std::vector<std::pair<float, float>>& getDestinations() const; // nodiscard, value muss bei funktionsaufruf genutz werden, funktion darf also nicht einfach so abgerufen werden, hat ide als good coding hinzugefügt
  [[nodiscard]] float getHeight() const;
  void setHeight(float pHeight);
  void setDist(const std::function<float(float, float, float, float, float)> &pDist);
  [[nodiscard]] float distance()const;
  Route shortestRoute() const;
};





#endif
