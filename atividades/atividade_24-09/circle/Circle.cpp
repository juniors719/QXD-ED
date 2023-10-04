/**
 * @file Circle.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief Implementacao da classe Circle
 * @version 0.1
 * @date 24-09-2023
 *
 *
 *
 */

#include "Circle.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

/****************************************
 * Implementacao das funcoes-membro
 ****************************************/

/**
 * @brief Construtor sem argumentos:
 *
 */
Circle::Circle() {
    m_center.setX(0.0);
    m_center.setY(0.0);
    m_radius = 1.0;
}

/**
 * @brief Construtor com dois argumentos
 *
 * @param p
 * @param radius
 */
Circle::Circle(Point p, double radius) {
    m_center = p;
    m_radius = radius;
}

// destructor

/**
 * @brief Destroy the Circle:: Circle object
 *
 */
// Circle::~Circle() { std::cout << "circulo liberado" << std::endl; }

// setters

/**
 * @brief define o raio do circulo
 *
 * @param radius
 */
void Circle::setRadius(double radius) { m_radius = radius; }

/**
 * @brief define o centro do circulo
 *
 * @param p
 */
void Circle::setCenter(Point p) { m_center = p; }

// getters

/**
 * @brief devolve o centro do circulo
 * @return Point
 */
Point* Circle::getCenter() { return &m_center; }

/**
 * @brief devolve o raio do circulo
 *
 * @return double
 */
double Circle::getRadius() { return m_radius; }

/**
 * @brief devolve a area do circulo
 *
 * @return double
 */
double Circle::area() { return M_PI * m_radius * m_radius; }

/**
 * @brief devolve true se o ponto p estiver contido no circulo;
 *
 * @param p
 * @return true
 * @return false
 */
bool Circle::contains(Point p) {
    double dist = m_center.distance(p);
    return dist <= m_radius;
}
