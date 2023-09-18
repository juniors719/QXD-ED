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

void somaVetores(int* vetor, int* vetorNovo, int n, int i = 0) {
    if (i == n - 1) {
        return;
    }
    vetorNovo[i] = vetor[i] + vetor[i + 1];
    somaVetores(vetor, vetorNovo, n, i + 1);
}

void imprimeVetor(int* vetor, int ini, int len) {
    if (ini == 0) cout << "[";
    if (ini > 0) cout << ", ";
    if (ini == len - 1) {
        cout << vetor[len - 1] << "]\n";
        return;
    }
    cout << vetor[ini];
    imprimeVetor(vetor, ini + 1, len);
}

void imprimeTriangulo(int* vetor, int n) {
    // caso base:
    if (n == 1) {
        cout << "[" << vetor[0] << "]" << endl;
        return;
    }

    int* novoVetor = new int[n - 1];

    somaVetores(vetor, novoVetor, n);

    imprimeTriangulo(novoVetor, n - 1);  // chamada recursiva

    imprimeVetor(vetor, 0, n);

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