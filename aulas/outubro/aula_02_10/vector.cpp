#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vet{1, 2, 3, 4, 5, 6};
    auto it = vet.begin();
    while (it != vet.end()) {
        cout << *it << " ";
        it++;
    }
}