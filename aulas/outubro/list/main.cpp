#include <iostream>

#include "List.h"
using namespace std;

int main() {
    List lst;
    for (int i = 0; i < 10; i++) {
        lst.push_back(i);
    }
    while (!lst.empty()) {
        cout << lst.back() << " ";
        lst.pop_back();
    }
}