#include <iostream>
#include <string>
using namespace std;

struct Pessoa
{
    string nome;
    int idade;
};

void preencheArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Digite o " << i + 1 << " valor: ";
        cin >> a[i];
        cin.ignore();
    }
}

void imprimeArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Posição[" << i << "] = " << a[i] << endl;
    }
}

void preencheArrayPessoas(Pessoa *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Digite o nome da " << i + 1 << "ª pessoa: ";
        cin.ignore();
        getline(cin, a[i].nome);
        cout << "Digite a idade da " << i + 1 << "ª pessoa: ";
        cin >> a[i].idade;
        cout << "________________" << endl;
    }
}

void imprimeArrayPessoas(Pessoa *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Pessoa " << i + 1 << ": " << endl;
        cout << "Nome: " << a[i].nome << endl;
        cout << "Idade: " << a[i].idade << endl;
        cout << "________________" << endl;
    }
}

int main()
{
    // <tipo_de_dado> *ptr = new <tipo_de_dado>
    int *p = new int; // alocando um espaço de memória apontado por p;
    delete p;         // apagando o espaço de memória
    p = nullptr;      // p agora aponta para nulo

    int *ptr = new int[10]; // alocando um array de 10 inteiros;
    delete[] ptr;           // apagando o espaço de memória do vetor
    ptr = nullptr;

    /* int tamanhoArray;
    cout << "Digite o tamanho do array desejado: ";
    cin >> tamanhoArray;
    int *array = new int[tamanhoArray];
    preencheArray(array, tamanhoArray);
    imprimeArray(array, tamanhoArray); */

    int tamanhoArray;
    cout << "Digite o tamanho do array desejado: ";
    cin >> tamanhoArray;
    cin.ignore();
    Pessoa *arrayPessoas = new Pessoa[tamanhoArray];
    preencheArrayPessoas(arrayPessoas, tamanhoArray);
    imprimeArrayPessoas(arrayPessoas, tamanhoArray);
    delete[] arrayPessoas;
    arrayPessoas = nullptr;
    return 0;
}