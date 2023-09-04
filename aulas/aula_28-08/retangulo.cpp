#include <iostream>
#include <cmath>
using namespace std;

struct Ponto
{
    double x;
    double y;
};


struct Retangulo
{
    Ponto supEsquerdo;
    Ponto infDireito;

    double area() {
        return abs(supEsquerdo.y - infDireito.y) * abs(infDireito.x - supEsquerdo.x);
    }

    double perimetro() {
        return (2 * abs(supEsquerdo.y - infDireito.y)) + (2 * abs(infDireito.x - supEsquerdo.x));
    }

    double diagonal() {
        return sqrt(pow((infDireito.x - supEsquerdo.x), 2) + pow((infDireito. y - supEsquerdo.y), 2));
    }
};


int main(){
    Retangulo ret;
    cin >> ret.supEsquerdo.x >> ret.supEsquerdo.y;
    cin >> ret.infDireito.x >> ret.infDireito.y;
    cout << "Area: " << ret.area() << endl;
    cout << "Perímetro: " << ret.perimetro() << endl;
    cout << "Diagonal: " << ret.diagonal() << endl;
}