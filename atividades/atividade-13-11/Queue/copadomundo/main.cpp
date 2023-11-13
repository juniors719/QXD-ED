/**
 * @file main.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief
 * @version 0.1
 * @date 13-11-2023
 *
 *
 */

#include "Queue.h"

/**
 * @brief Função que inicializa a fila com os times
 *
 * @param pool fila a ser inicializada
 */
void initializeQueue(Queue<char>& pool) {
    for (char c = 'A'; c <= 'P'; c++) {
        pool.push(c);
    }
}

int main() {
    Queue<char> pool;
    initializeQueue(pool);
    while (pool.size() > 1) {
        char time1 = pool.front();
        pool.pop();
        char time2 = pool.front();
        pool.pop();
        int gols1, gols2;
        std::cin >> gols1 >> gols2;
        if (gols1 > gols2)
            pool.push(time1);
        else
            pool.push(time2);
    }
    std::cout << pool.front() << std::endl;
}