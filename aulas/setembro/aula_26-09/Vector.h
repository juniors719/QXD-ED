/**
 * @file vector.h
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief Classe que implementa uma lista
 * @version 0.1
 * @date 26-09-2023
 *
 *
 */

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
   private:
    unsigned int m_size{};      // número de elementos atual
    unsigned int m_capacity{};  // capacidade atual da lista
    T* m_vet{};                 // ponteiro para array

   public:
    // construtor default
    Vector() = default;

    // construtor que recebe a capacidade
    Vector(unsigned int capacity) : m_size{0}, m_capacity{capacity} {
        m_vet = new T[m_capacity];
    }

    // construtor de cópia
    Vector(const Vector& v) {
        m_size = v.m_size;
        m_capacity = v.m_capacity;
        m_vet = new T[m_capacity];
        for (unsigned int i = 0; i < v.m_size; i++) {
            m_vet[i] = v.m_vet[i];
        }
    }

    /**
     * @brief Função que recebe um valor newCapacity
     * que será a nova capacidade.
     * Se m_capacity >= newCapacity, a função não faz nada.
     * Caso contrário, a função aumenta a capacidade do
     * Vector para um valor maior ou igual a newCapacity.
     *
     * @param newCapacity
     */
    void resize(unsigned int newCapacity) {
        if (m_capacity < newCapacity) {
            m_capacity = newCapacity;
            T* aux = new T[m_capacity];
            for (unsigned int i = 0; i < m_size; i++) {
                aux[i] = m_vet[i];
            }
            delete[] m_vet;
            m_vet = aux;
        }
    }

    /**
     * @brief Função que insere um elemento no final
     * da lista. Se a lista ficar cheia, ele primeiro
     * aumenta a capacidade da lista e somente depois
     * insere no final.
     *
     * @param value
     */
    void push_back(int value) {
        if (m_size == m_capacity) {  // aumenta se precisar
            resize(2 * (m_capacity + 1));
        }
        m_vet[m_size++] = value;  // insere e incrementa size
    }

    /**
     * @brief Função que recebe um índice i e retorna
     * o elemento que está no índice i.
     * Se o índice não existir na lista, essa função
     * vai lançar uma exceção.
     *
     * @param index
     * @return int
     */
    T& at(unsigned int index) {
        if (index < m_size) {
            return m_vet[index];
        } else {
            throw std::out_of_range("erro no índice");
        }
    }

    T& at(unsigned int index) const {
        if (index < m_size) {
            return m_vet[index];
        } else {
            throw std::out_of_range("erro no índice");
        }
    }

    /**
     * @brief Função que retorna o size atual
     *
     * @return int
     */
    unsigned int size() const { return m_size; }

    /**
     * @brief Função que retorna a capacidade atual
     *
     * @return int
     */
    unsigned int capacity() const { return m_capacity; }

    /**
     * @brief Sobrecarga do operador de indexação.
     * Recebe um índice e retorna o elemento
     * do índice i.
     * Se o índice não estiver dentro do intervalo,
     * o comportamento dessa função é indeterminado.
     *
     * @param index
     * @return int&
     */
    T& operator[](int index) { return m_vet[index]; }

    const T& operator[](int index) const { return m_vet[index]; }

    // Destrutor
    ~Vector() {
        delete[] m_vet;
        std::cout << "vector destruído" << std::endl;
    }

    /**
     * @brief Construct a new operator= object
     * Sobrecarga do operador de atribuição
     * @param v
     */
    Vector<T>& operator=(const Vector& v) {
        if (this != &v) {
            delete[] m_vet;
            m_size = v.m_size;
            m_capacity = v.m_capacity;
            m_vet = new T[m_capacity];
            for (unsigned int i = 0; i < v.m_size; i++) {
                m_vet[i] = v.m_vet[i];
            }
        }
        return *this;
    }

    bool operator==(const Vector& v) const {
        if (m_size != v.m_size) {
            return false;
        }
        for (unsigned int i = 0; i < m_size; i++) {
            if (m_vet[i] != v.m_vet[i]) {
                return false;
            }
        }
        return true;
    }
};

#endif  // VECTOR_H