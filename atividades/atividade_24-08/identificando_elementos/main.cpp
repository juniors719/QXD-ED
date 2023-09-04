#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 * @brief 
 * verifica se é número, hífen ou ponto
 * @param caractere 
 * @return true -> se for numérico, hífen ou ponto
 * @return false -> caso contrário
 */
bool isNumeric(int caractere) {
    if((caractere >= 48 && caractere <= 57) || caractere == 45 || caractere == 46) return true;
    return false;
}

/**
 * @brief 
 * 
 * returns:
 * 0 -> string
 * 1 -> float
 * 2 -> int
 * 
 * @param token 
 * @return int 
 */

int type(string token) {
    int saida = 2; // padrão retornar int
    for (int i = 0; i < token.size(); i++) {
        char caractere = token[i];
        if(isNumeric(caractere)) {
            if(caractere == '.') saida = 1;
        }else return 0;
    }
    return saida;
}

int main() {
    string leitura, token;
    bool first = true;
    getline(cin, leitura);
    istringstream iss(leitura);
    while (getline(iss, token, ' ')) {
        if (!first) cout << " ";
        switch (type(token)) {
            case 0: cout << "str";
                break;
            case 1: cout << "float";
                break;
            case 2: cout << "int";
                break;
            default: break;
        }
        if(first) first = false;
    }
    cout << endl;
    return 0;   
}
