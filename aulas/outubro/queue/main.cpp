#include <iostream>

#include "Queue.h"
using namespace std;
int main() {
    Queue<int> fila;
    for (int i = 1; i <= 9; i++) {
        fila.push(i);
    }
    cout << "Tamanho da fila: " << fila.size() << endl;
    while (!fila.empty()) {
        cout << fila.front() << " ";
        fila.pop();
    }
}