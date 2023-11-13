#include <iostream>
#include <string>
#include <sstream>
#include "bst.h"
using namespace std;

int main() {
    BST t;
    string skeys;
    int k;
    
    cout << "Digite as chaves separadas por espacos: ";
    getline(cin, skeys);
    stringstream ss { skeys };
    
    while(ss >> k) t.add(k);

    cout << "Menor chave: " << t.minimum() << endl;
    cout << "Maior chave: " << t.maximum() << endl;
    return 0;
}
