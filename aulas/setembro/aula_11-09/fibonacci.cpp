/**
 * @file fibonacci.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief
 * @version 0.1
 * @date 11-09-2023
 *
 *
 */

#include <iostream>
using namespace std;

long fibonacci(long n) {
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() { cout << fibonacci(3) << endl; }