#include <iostream>
using namespace std;
#include "ForwardList.h"

int main() {
    ForwardList lista;
    for (int i = 1; i <= 10; i++) {
        lista.push_front(i);
    }

    /* caminhar pela lista imprimindo na tela
    o valor dos elementos */
    for (auto it = lista.begin(); it != lista.end(); it++) cout << *it << " ";
    cout << endl;
}