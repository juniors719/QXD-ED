/**
 * @file main.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief Programa para registrar presenças do Almoço com Código.
 * @version 0.1
 * @date 14-09-2023
 *
 *
 */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Registro {
    int indice;
    int matricula;
    int presencas;
};

/**
 * @brief função para encontrar a matrícula no arquivo
 *
 * @param registros
 * @param matricula
 * @return int
 */
int encontrarMatricula(const vector<Registro>& registros, int matricula) {
    for (size_t i = 0; i < registros.size(); ++i) {
        if (registros[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief função para atualizar o arquivo
 *
 * @param registros
 * @param nomeArquivo
 */
void atualizarArquivo(const vector<Registro>& registros,
                      const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);

    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return;
    }

    arquivo << "id | matricula | qtd" << endl;

    for (const Registro& registro : registros) {
        arquivo << setw(3) << registro.indice << " | " << setw(7)
                << registro.matricula << " | " << setw(3) << registro.presencas
                << endl;
    }

    arquivo.close();
}

int main() {
    string nomeArquivoGeral = "presencas_geral.txt";
    vector<Registro> registros;  // Vetor de registros

    ifstream arquivoGeral(nomeArquivoGeral);

    if (arquivoGeral) {
        string linha;
        while (getline(arquivoGeral, linha)) {
            Registro registro;
            if (sscanf(linha.c_str(), "%d | %d | %d", &registro.indice,
                       &registro.matricula, &registro.presencas) == 3) {
                registros.push_back(registro);
            }
        }
        arquivoGeral.close();
    }

    string dataPresenca;
    cout << "Digite a data da presença (no formato DD-MM-YYYY): ";
    cin >> dataPresenca;
    string nomeArquivoData = "presencas_" + dataPresenca + ".txt";
    vector<Registro> registrosDiarios;

    ifstream arquivoData(nomeArquivoData);

    if (arquivoData) {
        string linha;
        while (getline(arquivoData, linha)) {
            Registro registro;
            if (sscanf(linha.c_str(), "%d | %d | %d", &registro.indice,
                       &registro.matricula, &registro.presencas) == 3) {
                registrosDiarios.push_back(registro);
            }
        }
        arquivoData.close();
    }

    int matricula;
    while (true) {
        cout << "Digite o número de matrícula + Enter: ";
        cin >> matricula;

        if (matricula == 0) {
            break;
        }

        int indiceExistente = encontrarMatricula(registrosDiarios, matricula);

        if (indiceExistente != -1) {
            // Matrícula já existe na data da presença
            cout << "Matrícula já registrada na data de hoje" << endl;
        } else {
            // Matrícula não existe, criar novo registro diário
            Registro novoRegistroDiario;
            novoRegistroDiario.indice = registrosDiarios.size() + 1;
            novoRegistroDiario.matricula = matricula;
            novoRegistroDiario.presencas = 1;
            registrosDiarios.push_back(novoRegistroDiario);
        }

        int indiceGeral = encontrarMatricula(registros, matricula);

        if (indiceGeral != -1) {
            // Matrícula já existe no registro geral, atualizar presenças
            registros[indiceGeral].presencas++;
        } else {
            // Matrícula não existe no registro geral, criar novo registro geral
            Registro novoRegistroGeral;
            novoRegistroGeral.indice = registros.size() + 1;
            novoRegistroGeral.matricula = matricula;
            novoRegistroGeral.presencas = 1;
            registros.push_back(novoRegistroGeral);
        }
    }

    atualizarArquivo(registros, nomeArquivoGeral);
    atualizarArquivo(registrosDiarios, nomeArquivoData);

    cout << "Registros atualizados com sucesso." << endl;

    return 0;
}
