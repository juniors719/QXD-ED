#include <iostream>

#include "List.h"
using namespace std;

int main() {
    List lst;
    for (int i = 0; i < 10; i++) {
        lst.push_back(i);
    }

    // lst.clear();

    for (auto& e : lst) {
        cout << e << " ";
    }
}