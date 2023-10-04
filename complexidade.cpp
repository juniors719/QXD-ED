#include <iostream>
using namespace std;

int f(int l[], int n) {
    int s = 0;
    for (int i = 0; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            if (l[i] > l[j]) {
                s = s + 1;
            }
        }
    }
    return s;
}

int main() {}