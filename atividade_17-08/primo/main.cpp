#include <iostream>

bool ehPrimo(int n){
    for(int i = 2; i <= n / i; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int a, b; std::cin >> a >> b;
    for(int i = a; i <= b; i++) {
        if(ehPrimo(i)) std::cout << i << "\n";
    }
}
