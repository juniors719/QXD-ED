








#include <iostream>
#include <sstream>
using namespace std;

bool isNumeric(char c) {
    if ((c >= '0' && c <= '9') || c == '-' || c == '.') {
        return true;
    }
    return false;
}

int identificaElemento(string elemento) {
    int saida = 0;
    for (int i = 0; i < elemento.size(); i++) {
        if (isNumeric(elemento[i]) || elemento[i] == '-') {
            if (elemento[i] == '.') {
                saida = 1;
            }
        } else {
            saida = 2;
        }
    }
    return saida;
}

int main() {
    string frase, token;
    string saida = "";
    getline(cin, frase);
    istringstream ss (frase);
    while (getline(ss, token, ' ')) {
        switch (identificaElemento(token)) {
        case 0:
            saida += "int";
            break;
        case 1:
            saida += "float";
            break;
        case 2:
            saida += "str";
            break;
        default:
            break;
        }
        saida += " ";
    }
    saida.pop_back();
    cout << saida << endl;
}
