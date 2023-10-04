#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>

#include "ponto.h"

class Circle {
   private:
    double radius;
    Ponto center;

   public:
    // construtor
    Circle(double radius, Ponto& center) {
        this->radius = radius;
        this->center = center;
    }

    // getters and setters
    void setCenterX(double x) { center.setX(x); }
    void setCenterY(double y) { center.setY(y); }
    void setCenter(const Ponto& p) { this->center = p; }
    void setRadius(double radius) { this->radius = radius; }
    double getRadius() { return radius; }
    Ponto getCenter() { return center; }
    double area() { return pow((3.14 * radius), 2); }
    bool contains(const Ponto& p) { return center.calcDist(p) <= radius; }
};

#endif