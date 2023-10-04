#include <iostream>
#include "math.hpp"

int main(){
    int x{}, y{};
    std::cout << "Digite dois inteiros: ";
    std::cin >> x >> y;
    std::cout << "Soma: " << ufc::sum(x,y) << std::endl;
    std::cout << "Subtração: " <<  ufc::sub(x,y) << std::endl;
    std::cout << "Multiplicação: " <<  ufc::mult(x,y) << std::endl;
    std::cout << "Divisão: " <<  ufc::div(x,y) << std::endl;
}