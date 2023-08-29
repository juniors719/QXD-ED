#include <iostream>
using namespace std;

int main(){
    int quantProdutos;
    int scorePrimeiro = 0, scoreSegundo = 0;
    cin >> quantProdutos;
    float produtos[50];
    float primeiroJog[50];
    char segundoJog[50];
    for (int i = 0; i < quantProdutos; i++) {
        cin >> produtos[i];
    }
    for (int i = 0; i < quantProdutos; i++) {
        cin >> primeiroJog[i];
    }
    for (int i = 0; i < quantProdutos; i++) {
        cin >> segundoJog[i];
        if (produtos[i] == primeiroJog[i]) {
            scorePrimeiro++;
        } else {
            if ((produtos[i] < primeiroJog[i]) && segundoJog[i] == 'm') {
                scoreSegundo++;
            } else if ((produtos[i] > primeiroJog[i]) && segundoJog[i] == 'M') {
                scoreSegundo++;
            } else {
                scorePrimeiro++;
            }
        }
    }

    if (scorePrimeiro == scoreSegundo) cout << "empate" << endl;
    else if (scorePrimeiro > scoreSegundo) cout << "primeiro" << endl;
    else cout << "segundo" << endl;
    
}