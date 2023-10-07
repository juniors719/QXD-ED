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
#include <stdexcept>
#include <vector>

using namespace std;

/**
 * @brief função que remove as pessoas que sairam da fila
 *
 * @param queue             // fila
 * @param quantPeopleLeft   // quantidade de pessoas que sairam da fila
 * @param idPeople          // vetor com os ids das pessoas que sairam da fila
 */
void fila(vector<int>& queue, unsigned int quantPeopleLeft,
          const vector<int>& idPeople) {
    for (unsigned int i = 0; i < quantPeopleLeft; i++) {
        int index = -1;
        for (unsigned int j = 0; j < queue.size(); j++) {
            if (queue[j] == idPeople[i]) {
                index = j;
                break;
            }
        }
        if (index == -1) return;
        queue.erase(queue.begin() + index);
    }
}

void show(vector<int>& queue) {
    for (int value : queue) cout << value << " ";
    cout << endl;
}

int main() {
    unsigned int quantPeople, quantPeopleLeft;
    vector<int> peopleLeft;
    vector<int> queue;
    cin >> quantPeople;
    for (unsigned int i = 0; i < quantPeople; i++) {
        int id;
        cin >> id;
        queue.push_back(id);
    }
    cin >> quantPeopleLeft;
    for (unsigned int i = 0; i < quantPeopleLeft; i++) {
        int id;
        cin >> id;
        peopleLeft.push_back(id);
    }
    fila(queue, quantPeopleLeft, peopleLeft);
    show(queue);
    return 0;
}