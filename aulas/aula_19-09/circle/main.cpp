#include <iostream>
using namespace std;
#include "circle.h"
#include "ponto.h"
int main() {
    Ponto centroCirculo(0, 0);
    Circle c1(3, centroCirculo);
    Circle c2(5, centroCirculo);
    Ponto randomPonto(3.5, 3.5);
    if (c2.contains(randomPonto)) {
        cout << "tá dentro" << endl;
    } else {
        cout << "tá fora" << endl;
    }
}