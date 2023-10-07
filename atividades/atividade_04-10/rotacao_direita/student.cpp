#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot) {
    int size = vet.size();
    for (int i = 0; i < nrot; i++) {
        int ultimo = vet[size - 1];
        for (int j = size - 1; j > 0; j--) {
            vet[j] = vet[j - 1];
        }
        vet[0] = ultimo;
    }
}

void show(vector<int>& vet) {
    cout << "[ ";
    for (int value : vet) cout << value << " ";
    cout << "]\n";
}

int main() {
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for (int i = 0; i < size; i++) cin >> vet[i];

    right_rotation(vet, nrot);
    show(vet);
}
