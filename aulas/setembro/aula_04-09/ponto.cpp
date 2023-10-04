#include <iostream>
using namespace std;

struct Ponto
{
    float x;
    float y;
};


void troca(Ponto *p1, Ponto *p2) {
    Ponto aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

void dobra(Ponto *p1, Ponto *p2) {
    p1->x *= p1->x;
    p1->y *= p1->y;
    p2->x *= p2->x;
    p2->y *= p2->y;
}

int main() {
    Ponto p, q;
    cout << "Digite os valores de x e y do Ponto 1: ";
    cin >> p.x >> p.y;
    cout << "Digite os valores de x e y do Ponto 1: ";
    cin >> q.x >> q.y;
    troca(&p, &q);
    cout << "Ponto 1: X = " << p.x << " | Y = " << p.y << endl;
    cout << "Ponto 2: X = " << q.x << " | Y = " << q.y << endl;
    dobra(&p, &q);
    cout << "Ponto 1: X = " << p.x << " | Y = " << p.y << endl;
    cout << "Ponto 2: X = " << q.x << " | Y = " << q.y << endl;

}

