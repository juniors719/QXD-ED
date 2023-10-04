#include <iostream>

#include "Vector.h"
using namespace std;
int main() {
    Vector<float> vec;

    for (int i = 1; i < 10; i++) {
        vec.push_back(i * 0.5);
    }

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}