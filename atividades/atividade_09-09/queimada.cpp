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
    queimada(matriz, nLinhas, nColunas, iniX, iniY);
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
