/**
 * @file exercicio1.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief Esse programa troca o valor de duas variáveis
 * @version 0.1
 * @date 29-08-2023
 * 
 * 
 */

#include <iostream>
using namespace std;

void troca(int *p1, int *p2) {
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

int main() {
    int a, b; cin >> a >> b;
    troca(&a, &b);
    cout << "Valor de a: " << a << endl << "Valor de b: " << b << endl;
    return 0;
}