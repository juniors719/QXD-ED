/**
 * @file main.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief 
 * @version 0.1
 * @date 25-08-2023
 * 
 * 
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/**
 * @brief Verifica se um caractere é uma vogal
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool isVewel(char c){
    string vogais = "AEIOUaeiou";
    if (vogais.find(c) != string::npos) return true;
    else return false;
}

/**
 * @brief Separa uma silaba de uma palavra, duplica e concatena com o restante da palavra
 * 
 * @param token 
 * @return string 
 */
string separaSilaba(string token){
    string saida = "";
    for (size_t i = 0; i < token.size() - 1; i++){
        if((isVewel(token[i]) && !isVewel(token[i+1]))){
            for (size_t j = 0; j < 3; j++) saida += token.substr(0, i+1);
            saida += token.substr(i+1, token.size());
            return saida;
        }
    }
    return token;
}

int main(){
    string frase, saida = "";
    getline(cin, frase);
    istringstream ss(frase);
    while (getline(ss, frase, ' ')) {
        saida += separaSilaba(frase) + " ";
    }
    saida.pop_back();
    cout << saida << endl;
    return 0;
}