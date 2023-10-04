#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {      // n - 1
        int minIndex = i;                  // c1
        for (int j = i + 1; j < n; j++) {  // n - i - 1
            if (arr[j] < arr[minIndex]) {  // c2
                minIndex = j;              // c3 || 0
            }
        }
        if (minIndex != i) {              // c4
            swap(arr[i], arr[minIndex]);  // c5 || 0
        }
    }
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}