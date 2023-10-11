/**
 * @file main.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief
 * @version 0.1
 * @date 07-10-2023
 *
 *
 */

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Abordagem I
// marcando os elementos que morrem
void josephus(int nPlayers, int espada) {
    // cria o vetor e inicializa
    bool* players = new bool[nPlayers];
    for (int i = 0; i < nPlayers; i++) {
        players[i] = true;
    }

    for (int i = 0; i < nPlayers; i++) {
        // imprime o vetor
        cout << "[";
        for (int j = 0; j < nPlayers; j++) {
            if (players[j]) {
                cout << " " << j + 1;
            }
            if (j + 1 == espada) cout << ">";
        }
        cout << " ]\n";
        if (i == nPlayers - 1) break;

        // encontra o próximo vivo
        int next = espada % nPlayers;
        while (!players[next]) {
            next = (next + 1) % nPlayers;
        }
        // mata
        players[next] = false;
        // encontra o próximo vivo para ser a espada
        espada = ((next + 1) % nPlayers) + 1;
        while (!players[espada - 1]) {
            espada = (espada % nPlayers) + 1;
        }
    }

    delete[] players;
}

// Abordagem II
// removendo os elementos que morrem
void josephusII(int nPlayers, int espada) {
    // inicializa o vetor
    vector<int> players;
    for (int i = 1; i <= nPlayers; i++) {
        players.push_back(i);
    }

    while (players.size() >= 1) {
        // imprime o vetor
        cout << "[";
        for (unsigned int i = 0; i < players.size(); i++) {
            cout << " " << players[i];
            if (i + 1 == espada) cout << ">";
        }
        cout << " ]\n";
        if (players.size() == 1) break;

        players.erase(players.begin() + espada % players.size());
        espada = (espada % players.size()) + 1;
    }
}

int main() {
    int nPlayers, espada;
    cin >> nPlayers >> espada;
    josephus(nPlayers, espada);
    // josephusII(nPlayers, espada);
}