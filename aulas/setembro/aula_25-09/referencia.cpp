#include <iostream>
using namespace std;

// usando const, consigo passar o valor 3 e 4 para a referência
// cria uma variável temporária pra cada referência
int soma(const int& a, const int& b) { return a + b; }

int main() {
    int x{87};
    int y{1};
    int& ref1 = x;  // referência comum
    ref1 = 99;
    cout << ref1 << endl;
    const int& ref2 = x;  // referência constante
                          // o valor que ref2 referencia não é modificável
                          // ref2 = 33;  Isso não é possível
    cout << soma(3, 4) << endl;
}