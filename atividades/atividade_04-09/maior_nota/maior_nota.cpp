/**
 * @file maior_nota.cpp
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
    string nome;
    int matricula;
    string disciplina;
    double nota;
};

void leitura(Aluno *alunos) {
    for (int i = 0; i < 2; i++) {
        getline(cin, alunos[i].nome);
        cin >> alunos[i].matricula;
        cin.ignore();
        getline(cin, alunos[i].disciplina);
        cin >> alunos[i].nota;
        cin.ignore();
    }
}

void maiorMedia(Aluno *aluno) {
    Aluno maiorNota;
    if (aluno[0].nota == aluno[1].nota) {
        cout << fixed << setprecision(1) << aluno[0].nome << " e "
             << aluno[1].nome << " , " << aluno[0].nota << endl;
        return;
    } else if (aluno[0].nota > aluno[1].nota) {
        maiorNota = aluno[0];
    } else {
        maiorNota = aluno[1];
    }
    cout << fixed << setprecision(1) << maiorNota.nome << " , "
         << maiorNota.nota << endl;
}

int main() {
    Aluno *alunos = new Aluno[2];
    leitura(alunos);
    maiorMedia(alunos);
}