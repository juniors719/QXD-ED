#include <iostream>
#include <string>
using namespace std;

struct Aluno
{
    string nome;
    int matricula;
    double notas[3];
    double media;
};

double calcMedia(Aluno aluno) {
    return ((aluno.notas[0] + aluno.notas[1] + aluno.notas[2])/3);
}

int main() {
    Aluno alunos[5];
    for (size_t i = 0; i < 5; i++)
    {
        cout << "Digite o nome do " << i+1 << "º aluno: " << endl;
        getline(cin, alunos[i].nome);
        cout << "Digite a matricula do " << i+1 << "º aluno: " << endl;
        cin >> alunos[i].matricula;
        cout << "Digite as 3 notas  do " << i+1 << "º aluno separadas por espaço: " << endl;
        cin >> alunos[i].notas[0] >> alunos[i].notas[1] >> alunos[i].notas[2];
        alunos[i].media = calcMedia(alunos[i]);
        cin.ignore();
    }

    cout << "----ALUNOS APROVADOS----" << endl;
    for (size_t i = 0; i < 5; i++)
    {
        if (alunos[i].media >= 7) {
            cout << "Nome: " << alunos[i].nome << endl;
            cout << "Matrícula: " << alunos[i].matricula << endl;
            cout << "Média: " << alunos[i].media << endl;
            cout << "----------------------------" << endl;
        }
    }
    
    
}