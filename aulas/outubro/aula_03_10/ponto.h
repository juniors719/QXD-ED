#ifndef PONTO_H
#define PONTO_H

#include <cmath>
#include <iostream>

class Ponto {
   private:
    double x;
    double y;

   public:
    // construtor padrão
    Ponto(double x = 1, double y = 1) {
        this->x = x;
        this->y = y;
    }

    // construtor de cópia
    Ponto(const Ponto& p) {
        x = p.x;
        y = p.y;
    }

    // operador de atribuição
    Ponto operator=(const Ponto& p) {
        x = p.x;
        y = p.y;
        return p;
    }

    // função amiga que sobrecarrega o operador ==
    // isso permite que a função acesse os membros privados da classe
    // friend bool operator==(const Ponto& p1, const Ponto& p2);

    friend std::ostream& operator<<(std::ostream& out, const Ponto& p);

    // getters e setters
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    // const indica que o método não altera o estado do objeto
    double getX() const { return x; }
    double getY() const { return y; }

    // método para calcular a distância entre dois pontos
    double calcDist(const Ponto& p);
};

// função global que sobrevarrega o operador ==
// essa função retorna true se e somente se os pontos p1 e p2 tem as mesmas
// coordenadas
/* bool operator==(const Ponto& p1, const Ponto& p2) {
    return p1.x == p2.x && p1.y == p2.y;
} */

// função global para calcular a distância entre dois pontos
double Ponto::calcDist(const Ponto& p) {
    return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
}

// função global que sobrecarrega o operador <<
// ess funçao é obrigada a ser global
std::ostream& operator<<(std::ostream& out, const Ponto& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

#endif