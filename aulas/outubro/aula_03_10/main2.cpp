#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vet{1, 2, 3, 4, 5, 6};
    // Jeitos de imprimir um vector usando iterador
    // jeito 1: usando iterador e while ----------------
    auto it = vet.begin();
    while (it != vet.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    // jeito 2: usando iterador e um for ----------------
    for (auto it = vet.begin(); it != vet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // jeito 3: usando um for each ----------------
    for (int e : vet) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}