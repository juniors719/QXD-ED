/**
 * @file operacoes.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief
 * @version 0.1
 * @date 13-09-2023
 *
 *
 */

#include <iostream>
#include <sstream>  //cabeçalho que contém o tipo de dado stringstream
#include <string>
#include <vector>  //cabeçalho que contém a estrutura de dados vector
using namespace std;

/**
 * @brief imprimir o vetor
 *
 * @param vetor
 * @param ini
 * @param len
 */
void imprimeVetor(vector<int> vetor, int ini, int len) {
    if (ini == 0) cout << "[";
    if (ini == len - 1) {
        cout << " " << vetor[len - 1] << " ]\n";
        return;
    }
    cout << " " << vetor[ini];
    imprimeVetor(vetor, ini + 1, len);
}

/**
 * @brief imprime o vetor na ordem inversa
 *
 * @param vetor
 * @param len
 */
void imprimeVetorInvertido(vector<int> vetor, int len) {
    if (len == vetor.size()) cout << "[";
    if (len == 1) {
        cout << " " << vetor[0] << " ]\n";
        return;
    }
    cout << " " << vetor[len - 1];
    imprimeVetorInvertido(vetor, (len - 1));
}

/**
 * @brief inverte o vetor passado por referência
 *
 * @param vetor
 * @param ini
 * @param fim
 */
void inverteVetor(vector<int> &vetor, int ini, int fim) {
    if (ini < fim) {
        int aux = vetor[ini];
        vetor[ini] = vetor[fim];
        vetor[fim] = aux;
        inverteVetor(vetor, ini + 1, fim - 1);
    }
}

/**
 * @brief soma todos os elementos do vetor
 *
 * @param vetor
 * @param len
 * @return int
 */
int sum(vector<int> vetor, int len) {
    if (len == 0) {
        return 0;
    }
    return vetor[len - 1] + sum(vetor, len - 1);
}

/**
 * @brief multiplica todos os elementos do vetor
 *
 * @param vetor
 * @param len
 * @return int
 */
int mult(vector<int> vetor, int len) {
    if (len == 0) {
        return 1;
    }
    return vetor[len - 1] * mult(vetor, len - 1);
}

/**
 * @brief retorna o menor valor do vetor
 *
 * @param vetor
 * @param len
 * @return int
 */
int min(vector<int> vetor, int len) {
    if (len == 1) return vetor[0];
    int minElem = min(vetor, len - 1);
    return (vetor[len - 1] < minElem) ? vetor[len - 1] : minElem;
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    while (ss >> value) {
        vet.push_back(value);
    }
    int len = vet.size();
    cout << "vet : ";
    imprimeVetor(vet, 0, len);
    cout << "rvet: ";
    imprimeVetorInvertido(vet, len);
    cout << "sum : " << sum(vet, len) << endl;
    cout << "mult: " << mult(vet, len) << endl;
    cout << "min : " << min(vet, len) << endl;
    cout << "inv : ";
    inverteVetor(vet, 0, len - 1);
    imprimeVetor(vet, 0, len);
}