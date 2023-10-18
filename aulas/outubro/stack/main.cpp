#include <iostream>
using namespace std;
#include <sstream>

#include "Stack.h"

struct Pessoa {
    int idade;
    string nome;
};

int main() {
    /* Stack<Pessoa> pilha{Pessoa{21, "João"}, Pessoa{20, "Maria"}};
    pilha.push(Pessoa{23, "Carla"});
    pilha.push(Pessoa{23, "Sebastião"});
    while (!pilha.empty()) {
        cout << pilha.top().nome << endl;
        pilha.pop();
    } */

    string line, word;
    getline(cin, line);
    istringstream iss(line);
    while (iss >> word) {
        Stack<char> pilha = Stack<char>();
        for (char c : word) {
            pilha.push(c);
        }
        while (!pilha.empty()) {
            cout << pilha.top();
            pilha.pop();
        }
        cout << " ";
    }
    cout << endl;
}
