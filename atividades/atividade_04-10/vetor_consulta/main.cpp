/**
 * @file main.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief
 * @version 0.1
 * @date 07-10-2023
 *
 *
 */

#include <iostream>
#include <vector>
using namespace std;

void matchingStrings(vector<string> strings, vector<string> consultas,
                     vector<unsigned int> &result) {
    for (unsigned int i = 0; i < consultas.size(); i++) {
        unsigned int count = 0;
        for (unsigned int j = 0; j < strings.size(); j++) {
            if (consultas[i] == strings[j]) {
                count++;
            }
        }
        result[i] = count;
    }
}

int main() {
    unsigned int consultasLength, stringsLength;
    cin >> stringsLength;
    vector<string> vetorStrings(stringsLength);
    for (unsigned int i = 0; i < stringsLength; i++) {
        cin >> vetorStrings[i];
    }
    cin >> consultasLength;
    vector<string> vetorConsultas(consultasLength);
    for (unsigned int i = 0; i < consultasLength; i++) {
        cin >> vetorConsultas[i];
    }
    vector<unsigned int> vetorResultado(consultasLength);
    matchingStrings(vetorStrings, vetorConsultas, vetorResultado);

    for (unsigned int i = 0; i < vetorResultado.size(); i++) {
        cout << vetorResultado[i] << (i < vetorResultado.size() - 1 ? " " : "");
    }
    cout << endl;
    return 0;
}