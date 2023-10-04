/**
 * @file busca_em_vetor_ordenado.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief Temos um vetor com n inteiros ordenados em ordem crescente e
 * gostaríamos de determinar se um dado valor está ou não no vetor
 * @version 0.1
 * @date 11-09-2023
 *
 *
 */

#include <iostream>
using namespace std;

/**
 * @brief Busca binária recursiva
 *
 * @param vet
 * @param ini
 * @param fim
 * @param buscado
 * @return int
 */
int search(int vet[], int ini, int fim, int buscado) {
    if (ini > fim) {
        return -1;
    }
    int m = (ini + fim) / 2;

    if (buscado == vet[m]) return m;
    if (buscado < vet[m])
        return search(vet, ini, m - 1, buscado);
    else
        return search(vet, m + 1, fim, buscado);
}

int main() {
    int vetor[] = {1, 3, 4, 4, 5, 8, 10, 13, 19};
    cout << search(vetor, 0, 8, 16);
}