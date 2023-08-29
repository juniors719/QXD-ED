#include <iostream>
using namespace std;

int main(){

    int square[3][3];
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            cin >> square[l][c];
        }
    }

    int somaReferencia = -1;

    // testar a soma das linhas
    for (int l = 0; l < 3; l++) {
        int somaLinha = 0;
        for (int c = 0; c < 3; c++) {
            somaLinha += square[l][c];
        }
        if (somaReferencia == -1) {
            somaReferencia = somaLinha;
            continue;
        }
        if (somaLinha != somaReferencia) {
            cout << "nao" << endl;
            return 0;
        }
    }

    // testar a soma das colunas
    for (int c = 0; c < 3; c++) {
        int somaColuna = 0;
        for (int l = 0; l < 3; l++) {
            somaColuna += square[l][c];
        }
        if (somaColuna != somaReferencia) {
            cout << "nao" << endl;
            return 0;
        }
    }

    // testar a soma das diagonais
    int somaDiagonaPrincipal = 0;
    int somaDiagonaSecundaria = 0;
    for (int l = 0; l < 3; l++) {
        somaDiagonaPrincipal += square[l][l];
        somaDiagonaSecundaria += square[l][2-l];
    }
    if (somaDiagonaPrincipal != somaReferencia || somaDiagonaSecundaria != somaReferencia) {
        cout << "nao" << endl;
        return 0;
    }

    cout << "sim" << endl;

    return 0;
}