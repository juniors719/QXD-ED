#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    string leitura, token;
    string ultimaPalavra = "";
    bool isOrdened = true;
    getline(cin, leitura);
    istringstream iss (leitura);
    while (getline(iss, token, ' ')) {
        if (ultimaPalavra.empty()) {
            ultimaPalavra = token;
            continue;
        }
        if (ultimaPalavra > token) {
            cout << "nao" << endl;
            return 0;
        }
        ultimaPalavra = token;
    }
    cout << "sim" << endl;
    return 0;
}