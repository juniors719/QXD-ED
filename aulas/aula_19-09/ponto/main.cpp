#include <iostream>
using namespace std;
#include "ponto.h"

int main() {
    Ponto p1(1.2, 3.4);
    Ponto p2(5.6, 7.8);
    Ponto p3(p1);
    cout << p1.calcDist(p2) << endl;
    cout << p3.getX() << endl;
}