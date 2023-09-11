/**
 * @file recursao.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief Elemento máximo de um vetor usando recursão
 * @version 0.1
 * @date 11-09-2023
 *
 *
 */

// se a instância em questão é pequena
// resolva-a diretamente (use força bruta se necessário)
// senão
// reduza-a a uma instância menor de um mesmo problema
// aplique o método à instância menor
// e volte à instância original

#include <iostream>
using namespace std;

int searchMax(int vetor[], int n) {
    if (n == 1)
        return vetor[0];
    else {
        int x = searchMax(vetor, n - 1);
        if (x > vetor[n - 1])
            return x;
        else
            return vetor[n - 1];
    }
}

// int searchMax(int vetor[], int inicio, int fim) {
//     if (inicio == fim) return vetor[inicio];

//     int meio = (inicio + fim) / 2;

//     int maxEsquerda = searchMax(vetor, inicio, meio);
//     int maxDireita = searchMax(vetor, meio + 1, fim);

//     if (maxEsquerda > maxDireita)
//         return maxEsquerda;
//     else
//         return maxDireita;
// }

int main() {
    int vetor[] = {1, 2, 3, 4};
    cout << searchMax(vetor, 4) << endl;
    return 0;
}