/**
 * @file traingulo_somas.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief
 * @version 0.1
 * @date 09-09-2023
 *
 *
 */

#include <iostream>
#include <string>
using namespace std;

void imprimeTriangulo(int* vetor, int n) {
    // caso base:
    if (n == 1) {
        cout << "[" << vetor[0] << "]" << endl;
        return;
    }

    int* novoVetor = new int[n - 1];

    for (int i = 0; i < n - 1; i++) {
        novoVetor[i] = vetor[i] + vetor[i + 1];
    }

    imprimeTriangulo(novoVetor, n - 1);  // chamada recursiva

    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << vetor[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
    delete[] novoVetor;
}

int main() {
    int n;
    cin >> n;
    int* vetor = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> vetor[i];
    }
    imprimeTriangulo(vetor, n);
    delete[] vetor;
    return 0;
}