#ifndef BOX_H
#define BOX_H
#include <iostream>
// nunca use namespace aqui

class Box {
   private:
    double height;
    double width;
    double lenght;

   public:
    // construtor default
    // Box() = default;
    Box() : Box(1.0, 1.0, 1.0) {
        std::cout << "Construtor default foi invocado." << std::endl;
    }

    // construtor
    Box(double h, double w, double l) {
        setHeight(h);
        setLenght(l);
        setWidth(w);
        std::cout << "Construtor com três argumentos foi invocado."
                  << std::endl;
    }

    // Box(double h, double w, double l) : height{h}, width{w}, lenght{l} {
    //     std::cout << "Construtor com três argumentos foi invocado."
    //               << std::endl;
    // }

    // DESTRUTOR : é chamado quando o objeto é destruído
    ~Box() { std::cout << "Caixa destruída" << std::endl; }

    // getters and setters
    void setHeight(double height) {
        if (height >= 0) this->height = height;
    }
    void setWidth(double width) {
        if (width >= 0) this->width = width;
    }
    void setLenght(double lenght) {
        if (lenght >= 0) this->lenght = lenght;
    }
    double getLenght() { return this->lenght; }
    double getWidth() { return this->width; }
    double getHeight() { return this->height; }

    // métodos
    double volume() { return height * width * lenght; }
};

#endif