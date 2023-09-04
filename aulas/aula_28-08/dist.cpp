#include <iostream>
#include <cmath>

using namespace std;

struct Ponto
{
    double x;
    double y;

    double distancia() {
        return sqrt(pow((this->x - 0), 2) + pow((this->y - 0), 2));
    }
} p;

int main(){
    Ponto p1;
    cin >> p1.x >> p1.y;
    cout << p1.distancia() << endl;
}