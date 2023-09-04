#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){

    string saida = "";
    string leitura, token;
    getline(cin, leitura);
    istringstream iss (leitura);
    while (getline(iss, token, ' ')) {
        if (saida == "") {
            saida += token;
            continue;
        }
        if (saida[saida.size() - 1] == token[0]) {
            token.erase(token.begin());
            saida += token;
        } else {
            saida += " " + token;
        }
    }
    cout << saida << endl;

    return 0;
}