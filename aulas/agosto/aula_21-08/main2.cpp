#include <iostream>
using namespace std;
int main(){
    int vec[] {2,6,3,5,3467,245,2,36,8678,345,23};
    int size =  sizeof(vec)/sizeof(int);

    // imprimir os elementos do vetor
    for (int i = 0; i < size; i++) {
        cout << vec[i] << ' ';
    }
    cout << endl;

    // foreach
    for (int valor : vec) {
        cout << valor << " ";
    }
    cout << endl;
    
}