#include <iostream>

int main(){
    int campoBatalha[3][3], quantSoldadosEmPosicao = 0;
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) std::cin >> campoBatalha[l][c];
    }
    for (int c = 0; c < 3; c++) {
        for (int l = 1; l < 3; l++){
            if (campoBatalha[l][c] < campoBatalha[l-1][c]) quantSoldadosEmPosicao++;
        }
    }
    std::cout << quantSoldadosEmPosicao << "\n";
}