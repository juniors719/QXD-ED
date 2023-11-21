#include <chrono>
#include <cstdlib>
#include <iostream>

#include "AlgoritmosDeOrdenação.h"

using namespace std;

int main() {
    int n = 500000;
    int *v1 = new int[n];
    int *v2 = new int[n];
    int *v3 = new int[n];
    for (int i = 0; i < n; i++) {
        v1[i] = v2[i] = v3[i] = rand() % 2000;
    }

    auto start = chrono::system_clock::now();
    insertionSort(v1, n);
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Insertion Sort: " << duration.count() << " microseconds" << endl;

    start = chrono::system_clock::now();
    selectionSort(v2, n);
    end = chrono::system_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Selection Sort: " << duration.count() << " microseconds" << endl;

    start = chrono::system_clock::now();
    quickSort(v3, 0, n - 1);
    end = chrono::system_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Quick Sort: " << duration.count() << " microseconds" << endl;
}