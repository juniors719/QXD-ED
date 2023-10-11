#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot) {
    for (int i = 0; i < nrot; i++) {
        int last = vet.back();
        vet.pop_back();
        vet.insert(vet.begin(), last);
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
