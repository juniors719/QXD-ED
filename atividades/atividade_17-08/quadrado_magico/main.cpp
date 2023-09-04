#include <iostream>

int main(){
    int quadradoMagico[3][3];
    for(int l = 0; l < 3; l++){
        for(int c = 0; c < 3; c++){
            std::cin >> quadradoMagico[l][c];
        }
    }
    // verificar as linhas
    int somaReferencia = 0;
    for(int l = 0; l < 3; l++){
        int somaLinha = 0;
        for(int c = 0; c < 3; c++){
            somaLinha += quadradoMagico[l][c];
        }
        if(l == 0) {
            somaReferencia = somaLinha;
            continue;
        }
        if(somaLinha != somaReferencia) {
            std::cout << "nao\n";
            return 0;
        }
    }
    // verificar as colunas
    for(int c = 0; c < 3; c++){
        int somaColuna = 0;
        for(int l = 0; l < 3; l++){
            somaColuna += quadradoMagico[l][c];
        }
        if(somaColuna != somaReferencia) {
            std::cout << "nao\n";
            return 0;
        }
    }
    std::cout << "sim\n";
    return 0;
}