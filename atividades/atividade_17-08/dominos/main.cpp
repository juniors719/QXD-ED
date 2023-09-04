#include <iostream>

bool isOrdened(int vetor[], int len){
    for(int i = 1; i < len; i++) {
        if(vetor[i] < vetor[i-1]) return false;
    }
    return true;
}

int main(){
    int n; std::cin >> n;
    int vetor[n];
    for (int i = 0; i < n; i++) std::cin >> vetor[i];
    if(isOrdened(vetor, n)) std::cout << "ok" << std::endl;
    else std::cout << "precisa de ajuste" << std::endl;
}

