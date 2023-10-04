#include <iostream>

#include "ponto.h"
using namespace std;
int main() {
    Ponto p1(1.2, 3.4);
    Ponto p2(5.6, 7.8);
    Ponto p3(p1);
    cout << p1;
}