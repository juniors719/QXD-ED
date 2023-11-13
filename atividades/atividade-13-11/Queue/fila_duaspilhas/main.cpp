/**
 * @file main.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief
 * @version 0.1
 * @date 13-11-2023
 *
 *
 */

#include <iostream>

#include "Queue.h"

// Comandos:
// 1 x - Enfileirar o elemento x no final da fila.
// 2 - Retirar da fila o elemento na frente da fila
// 3 - Imprimir o elemento na frente da fila

int main() {
    int n;  // quantidade de consultas
    std::cin >> n;
    Queue fila;
    while (n--) {
        int op;
        std::cin >> op;  // lê a operação
        switch (op) {
            case 1:
                int x;
                std::cin >> x;
                fila.push(x);
                break;

            case 2:
                fila.pop();
                break;

            case 3:
                std::cout << fila.front() << '\n';
                break;

            default:
                std::cout << "Operação inválida\n";
                break;
        }
    }
}