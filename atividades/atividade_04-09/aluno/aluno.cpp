/**
 * @file aluno.cpp
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

void leitura(Aluno *aluno) {
    getline(cin, aluno->nome);
    cin >> aluno->matricula;
    cin.ignore();
    getline(cin, aluno->disciplina);
    cin >> aluno->nota;
}

bool verificaMedia(Aluno *aluno) {
    if (aluno->nota >= 7) return true;
    return false;
}

int main() {
    Aluno *aluno = new Aluno;
    leitura(aluno);
    if (verificaMedia(aluno))
        cout << aluno->nome << " aprovado(a) em " << aluno->disciplina << endl;
    else
        cout << aluno->nome << " reprovado(a) em " << aluno->disciplina << endl;
}