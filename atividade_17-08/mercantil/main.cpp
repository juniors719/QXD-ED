#include <iostream>

int main() {
    int n; std::cin >> n;
    float precoRealProdutos[50], chutesPrimeiroJogador[50];
    char chutesSegundoJogador[50];
    int scorePrimeiroJogador = 0, scoreSegundoJogador = 0;
    for(int i = 0; i < n; i++) std::cin >> precoRealProdutos[i];
    for(int i = 0; i < n; i++) std::cin >> chutesPrimeiroJogador[i];
    for(int i = 0; i < n; i++){
        std::cin.ignore();
        std::cin >> chutesSegundoJogador[i];
    }
    for(int i = 0; i < n; i++){
        if(chutesPrimeiroJogador[i] == precoRealProdutos[i]) {
            scorePrimeiroJogador++;
            continue;
        }
        else if(chutesPrimeiroJogador[i] > precoRealProdutos[i] && chutesSegundoJogador[i] == 'm') scoreSegundoJogador++;
        else if(chutesPrimeiroJogador[i] < precoRealProdutos[i] && chutesSegundoJogador[i] == 'M') scoreSegundoJogador++;
        else scorePrimeiroJogador++;
    }
    if(scorePrimeiroJogador == scoreSegundoJogador) std::cout << "empate\n";
    else if(scorePrimeiroJogador > scoreSegundoJogador) std::cout << "primeiro\n";
    else std::cout << "segundo\n";
}