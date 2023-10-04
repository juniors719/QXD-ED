#include <iostream>

#include "matrix.h"
using namespace std;
int main() {
    Matrix m(2, 2);
    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 2; c++) {
            m.setValue(l, c, l + c);
        }
    }
    Matrix m2(2, 2);
    for (int l = 0; l < 2; l++) {
        for (int c = 0; c < 2; c++) {
            m2.setValue(l, c, l * c);
        }
    }
    m.imprimeMatrix();
    m2.imprimeMatrix();
    if (m.comparaMatrix(m2)) {
        cout << "São iguais" << endl;
    } else {
        cout << "São diferentes" << endl;
    }
    m.imprimeMatrix();
    m2.imprimeMatrix();

    // junior otário,
    return 0;
}