#include <iostream>
using namespace std;

struct Aluno
{
    string nome;
    string matricula;
    string endereco;
};


int main() {
    Aluno p {"Pedro", "123456780", "Rua Capixaba, 123"};
    cout << p.nome << endl;

    Aluno *ptr {&p};
    cout << ptr->nome << endl;
    cout << ptr->matricula << endl;
    cout << ptr->endereco << endl;
}