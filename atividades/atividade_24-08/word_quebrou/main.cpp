/**
 * @file main.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief 
 * Dado um texto, formate como for pedido (M - Toda maiúscula, m - toda minuscula, p - primeira maiúscula, i - inverter case). Observe que no primeiro maiúscula deixa como minúscula palavras de tamanho 1 como os artigos 'a', 'e', 'o'.
 * Ignore pontuação, espaço e números.
 * A entrada é composta de minúsculas, maiúsculas, números, pontuações e espaços simples.
 * @version 0.1
 * @date 24-08-2023
 * 
 * 
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/**
 * @brief Altera o case de uma string
 * 
 * @param token 
 * @param formatter 
 * @return string 
 */
string alteraCase(string token, char formatter) {
    string saida = "";
    for (int i = 0; i < token.size(); i++) {
        switch (formatter) {
        case 'm':
            saida += tolower(token[i]);
            break;
        case 'M':
            saida += toupper(token[i]);
            break;
        default:
            break;
        }
    }
    return saida;
}

/**
 * @brief Inverte o case de uma string
 * 
 * @param token 
 * @return string 
 */
string inverte(string token) {
    string saida = "";
    for (int i = 0; i < token.size(); i++) {
        if (token[i] >= 'A' && token[i] <= 'Z') {
            saida += tolower(token[i]);
        } else if (token[i] >= 'a' && token[i] <= 'z') {
            saida += toupper(token[i]);
        } else {
            saida += token[i];
        }
    }
    return saida;
}

/**
 * @brief Formata uma string de acordo com o formatter
 * 
 * @param token 
 * @param formatter 
 * @return string 
 */
string formatador(string token, char formatter) {
    switch (formatter) {
    case 'M':
        return alteraCase(token, formatter);
        break;
    case 'm': 
        return alteraCase(token, formatter);
        break;
    case 'p':
        if(token.size() > 1) {
            string saida = "";
            saida += toupper(token[0]);
            saida += alteraCase(token.substr(1, token.size()), 'm');
            return saida;
        } else return alteraCase(token, 'm');
        return token;
        break;
    case 'i':
        return inverte(token);
        break;
    default:
        return token;
        break;
    }
}

int main(){

    string frase; getline(cin, frase);
    char formatter; cin >> formatter;
    istringstream iss (frase);
    string palavra;
    string saida = "";
    while (getline(iss, palavra, ' ')) saida += formatador(palavra, formatter) + " ";
    saida.pop_back();

    cout << saida << endl;
}