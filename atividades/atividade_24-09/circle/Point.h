#ifndef PONTO_ED_2023
#define PONTO_ED_2023

/************************************
 * Declaracao da classe
 *************************************/
class Point {
   private:
    double m_x, m_y;

   public:
    // Construtor sem argumentos
    Point();

    // Construtor com dois argumentos
    Point(double X, double Y);

    // Setters
    void setX(double x);
    void setY(double y);

    // Getters
    double getX();
    double getY();

    // Calcula a distancia entre dois pontos
    double distance(Point p);

    // Imprime o ponto na tela
    void print();
};

#endif