/**
 * @file queimada.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief
 * @version 0.1
 * @date 13-09-2023
 *
 *
 */

#include <iostream>
#include <vector>

#include "Stack.h"
using namespace std;

void queimada(char **matriz, int nLinhas, int nColunas, int x, int y) {
    if (x < 0 || x >= nLinhas || y < 0 || y >= nColunas ||
        matriz[x][y] != '#') {
        return;
    }
    matriz[x][y] = 'o';
    queimada(matriz, nLinhas, nColunas, x - 1, y);
    queimada(matriz, nLinhas, nColunas, x + 1, y);
    queimada(matriz, nLinhas, nColunas, x, y - 1);
    queimada(matriz, nLinhas, nColunas, x, y + 1);
}

void queimadaStack(char **matriz, int nLinhas, int nColunas, int x, int y) {
    // verifique a primeira posição e queime-o
    // inicie a pilha com esse elemento
    // enquanto a pilha não estiver vazia faça
    // pegue topo da pilha

    // faça uma lista com todos os vizinhos de topo que podem ser queimados
    // se lista eh vazia
    //     desempilhe
    // senão
    //     escolha um dos vizinhos
    //     queime
    //     empilhe

    if (x < 0 || x >= nLinhas || y < 0 || y >= nColunas ||
        matriz[x][y] != '#') {
        return;
    }
    matriz[x][y] = 'o';
    Stack<int> pilha;
    pilha.push(x);
    pilha.push(y);
    while (!pilha.empty()) {
        int topoY = pilha.top();
        pilha.pop();
        int topoX = pilha.top();
        pilha.pop();
        if (topoX - 1 >= 0 && matriz[topoX - 1][topoY] == '#') {
            matriz[topoX - 1][topoY] = 'o';
            pilha.push(topoX - 1);
            pilha.push(topoY);
        }
        if (topoX + 1 < nLinhas && matriz[topoX + 1][topoY] == '#') {
            matriz[topoX + 1][topoY] = 'o';
            pilha.push(topoX + 1);
            pilha.push(topoY);
        }
        if (topoY - 1 >= 0 && matriz[topoX][topoY - 1] == '#') {
            matriz[topoX][topoY - 1] = 'o';
            pilha.push(topoX);
            pilha.push(topoY - 1);
        }
        if (topoY + 1 < nColunas && matriz[topoX][topoY + 1] == '#') {
            matriz[topoX][topoY + 1] = 'o';
            pilha.push(topoX);
            pilha.push(topoY + 1);
        }
    }
}

int main() {
    int nLinhas, nColunas, iniX, iniY;
    cin >> nLinhas >> nColunas >> iniX >> iniY;
    char **matriz = new char *[nLinhas];
    for (int i = 0; i < nLinhas; i++) {
        matriz[i] = new char[nColunas];  // Aloca cada linha da matriz
    }
    for (int i = 0; i < nLinhas; i++) {
        for (int j = 0; j < nColunas; j++) {
            cin >> matriz[i][j];
        }
    }
    queimadaStack(matriz, nLinhas, nColunas, iniX, iniY);
    cout << "\n";
    for (int i = 0; i < nLinhas; i++) {
        for (int j = 0; j < nColunas; j++) {
            cout << matriz[i][j];
        }
        cout << "\n";
    }
    // Liberar a memória alocada para cada linha da matriz
    for (int i = 0; i < nLinhas; i++) {
        delete[] matriz[i];
    }

    // Liberar a memória alocada para o array de ponteiros das linhas
    delete[] matriz;
}
