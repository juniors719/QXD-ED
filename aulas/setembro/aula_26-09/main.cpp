#include <iostream>

#include "Vector.h"
using namespace std;

int main() {
    Vector<int> vec;  // cria vetor vazio
    for (int i = 3; i <= 7; i++) {
        vec.push_back(i);
    }
    for (int i = 0; i < 5; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}