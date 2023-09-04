







#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool isVewel(char letter) {
    string vewels = "aeiou";
    if (vewels.find(tolower(letter)) != string::npos) return true;
    return false;
}

int main() {
    string frase, palavra;
    string saida = "";
    getline(cin, frase);
    istringstream ss (frase);
    while (getline(ss, palavra, ' ')) {
        string palavraSaida = "";
        for (int i = 0; i < palavra.size() - 1; i++) {
            if (isVewel(palavra[i]) && !isVewel(palavra[i+1])){
                string silabarepetida = palavra.substr(0, i+1);
                for (int j = 0; j < 3; j++) palavraSaida += silabarepetida;
                palavraSaida += palavra.substr(i+1, palavra.size());
                break;
            }
        }
        if(palavraSaida == "") palavraSaida += palavra;
        saida += palavraSaida + " ";
    }
    saida.pop_back();
    cout << saida << endl;
}