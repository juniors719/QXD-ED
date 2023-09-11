/**
 * @file conta_caractere.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief
 * @version 0.1
 * @date 09-09-2023
 *
 *
 */
#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n'
// caracteres). Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c) {
    if (n == 0) return 0;
    if (str[n - 1] == c)
        return 1 + contaCaracteres(str, n - 1, c);
    else
        return contaCaracteres(str, n - 1, c);
}

int main() {
    string frase;
    char c;
    getline(cin, frase);
    cin >> c;
    cout << contaCaracteres(frase, frase.size(), c) << endl;
}