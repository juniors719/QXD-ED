#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void ler_vector(vector<int>& vet) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int value;

    while (ss >> value) {
        vet.push_back(value);
    }
}

int cal_soma(const vector<int>& vet, int n) {
    if (n < vet.size()) {
        return vet[n] + cal_soma(vet, n + 1);
    }
    return 0;
}

int cal_mult(const vector<int>& vet, int n) {
    if (n < vet.size()) {
        return vet[n] * cal_mult(vet, n + 1);
    }
    return 1;
}

int menor_valor(const vector<int>& vet, int n, int min_e) {
    if (n < vet.size()) {
        return menor_valor(vet, n + 1, min(vet[n], min_e));
    }
    return min_e;
}

void inverte(const vector<int>& vet, int n) {
    if (n >= 0) {
        cout << vet[n] << " ";
        inverte(vet, n - 1);
    } else {
        return;
    }
}

int main() {
    vector<int> vet;

    ler_vector(vet);

    cout << "vet : [";
    for (int i = 0; i < vet.size(); ++i) {
        cout << " " << vet[i];
    }
    cout << " ]" << endl;

    cout << "rvet: [ ";
    inverte(vet, vet.size() - 1);
    cout << " ]" << endl;

    cout << "sum: " << cal_soma(vet, 0) << endl;
    cout << "mult: " << cal_mult(vet, 0) << endl;
    cout << "min: " << menor_valor(vet, 0, vet[0]) << endl;

    cout << "inv: "
         << " [ ";
    inverte(vet, vet.size() - 1);
    cout << " ]";

    return 0;
}