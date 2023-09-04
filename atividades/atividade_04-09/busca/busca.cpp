/**
 * @file busca.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief
 * @version 0.1
 * @date 04-09-2023
 *
 *
 */

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Aluno {
    int matricula;
    string nome;
    float media;
};

Aluno *search(Aluno *alunos, int nAlunos, int matricula) {
    for (int i = 0; i < nAlunos; i++) {
        if (alunos[i].matricula == matricula) return &alunos[i];
    }
    return NULL;
}

int main() {
    int n;
    cin >> n;
    Aluno *alunos = new Aluno[n];
    for (int i = 0; i < n; i++) {
        cin >> alunos[i].matricula;
        cin.ignore();
        getline(cin, alunos[i].nome);
        cin >> alunos[i].media;
        cin.ignore();
    }
    int matriculaBuscada;
    cin >> matriculaBuscada;
    Aluno *alunobuscado = search(alunos, n, matriculaBuscada);
    if (alunobuscado == NULL) {
        cout << "NAO ENCONTRADA" << endl;
        return 0;
    }
    cout << fixed << setprecision(1) << alunobuscado->nome << endl
         << alunobuscado->media << endl;
    return 0;
}