#ifndef PONTO_H
#define PONTO_H

#include <cmath>

class Ponto {
   private:
    double x;
    double y;

   public:
    Ponto(double x = 1, double y = 1) {
        setX(x);
        setY(y);
    }
    Ponto(const Ponto& p) {
        x = p.x;
        y = p.y;
    }
    Ponto operator=(const Ponto& p) {
        x = p.x;
        y = p.y;
        return p;
    }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    double getX() { return x; }
    double getY() { return y; }
    double calcDist(const Ponto& p);
};
double Ponto::calcDist(const Ponto& p) {
    return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
}

#endif