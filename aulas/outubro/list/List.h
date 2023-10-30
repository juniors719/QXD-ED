#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <iostream>
#include <stdexcept>

#include "Node.h"

/**
 * @brief Classe que implementa um iterador para a lista
 *
 */
class iterator_list {
    friend class List;

   private:
    Node* m_ptr;

   public:
    /**
     * @brief Construct a new iterator list object
     *
     * @param ptr
     */
    iterator_list(Node* ptr) : m_ptr(ptr) {}

    /**
     * @brief Sobrecarga do operador de pré-incremento
     * Ex.: ++it
     *
     * @return iterator_list&
     */
    iterator_list& operator++() {
        m_ptr = m_ptr->next;
        return *this;
    }

    /**
     * @brief Sobrecarga do operador de pós-incremento
     * Ex.: it++
     *
     * @return iterator_list&
     */
    iterator_list operator++(int) {
        iterator_list tmp = *this;
        m_ptr = m_ptr->next;
        return tmp;
    }

    /**
     * @brief Sobrecarga do operador de pré-decremento
     *
     * @return iterator_list&
     */
    iterator_list& operator--() {
        m_ptr = m_ptr->prev;
        return *this;
    }

    /**
     * @brief Sobrecarga do operador de pós-decremento
     *
     * @return iterator_list&
     */
    iterator_list operator--(int) {
        iterator_list tmp = *this;
        m_ptr = m_ptr->prev;
        return tmp;
    }

    /**
     * @brief Sobrecarga do operador de desreferência
     *
     * @return int&
     */
    int& operator*() { return m_ptr->data; }

    /**
     * @brief Sobrecarga do operador de igualdade
     *
     * @param other Outro iterador a ser comparado
     * @return true
     * @return false
     */
    bool operator==(const iterator_list& other) const {
        return m_ptr == other.m_ptr;
    }

    /**
     * @brief Sobrecarga do operador de diferença
     *
     * @param other
     * @return true
     * @return false
     */
    bool operator!=(const iterator_list& other) const {
        return m_ptr != other.m_ptr;
    }
};

/**
 * @brief Classe que implementa a lógica de uma lista duplamente encadeada
 * circular com nó sentinela
 *
 */
class List {
   private:
    Node* m_head;     // Ponteiro para o nó sentinela
    unsigned m_size;  // Número de elementos na lista

   public:
    using iterator = iterator_list;

    /**
     * @brief Construct a new List object, recebendo uma lista inicializadora
     *
     * https://en.cppreference.com/w/cpp/utility/initializer_list
     *
     * @param lst Lista inicializadora
     */
    List(const std::initializer_list<int> lst) : List() {
        for (const int& e : lst) {
            push_back(e);
        }
    }

    /**
     * @brief Construtor default: cria uma lista vazia
     *
     */
    List() {
        m_head = new Node(0, nullptr, nullptr);
        m_head->next = m_head;
        m_head->prev = m_head;
        m_size = 0;
    }

    /**
     * @brief Função que insere um valor no final da lista
     *
     * @param data Valor a ser inserido
     */
    void push_back(const int& data) {
        // Cria um novo nó, com o next apontando para o m_head, e o prec
        // apontando para m_head->prev
        Node* newNode = new Node(data, m_head->prev, m_head);
        // o next do último nó aponta para o novo nó
        m_head->prev->next = newNode;
        // o prev do m_head aponta para o novo nó
        m_head->prev = newNode;
        m_size++;
    }

    /**
     * @brief Função que insere um valor antes do iterador position.
     * Retorna um iterador para o novo elemento.
     *
     * @param position Iterador para o elemento que será o próximo do novo
     * elemento
     * @param val Valor a ser inserido
     * @return iterator
     */
    iterator insert(iterator position, const int& val) {
        Node* newNode = new Node(val, position.m_ptr->prev, position.m_ptr);
        position.m_ptr->prev->next = newNode;
        position.m_ptr->prev = newNode;
        m_size++;
        return iterator(newNode);
    }

    /**
     * @brief Função que remove o último elemento da lista
     *
     */
    void pop_back() {
        if (m_size == 0) throw std::runtime_error("Lista vazia");
        m_size--;
        Node* last = m_head->prev;
        m_head->prev = last->prev;
        last->prev->next = m_head;
        delete last;
    }

    /**
     * @brief Função que remove o elemento apontado pelo iterador position.
     * Retorna um iterador para o elemento seguinte ao removido.
     * Se a função apaga o último elemento, retorna o iterador end().
     *
     * @param position
     * @return iterator
     */
    iterator erase(iterator position) {
        iterator next(position.m_ptr->next);
        position.m_ptr->prev->next = next.m_ptr;
        next.m_ptr->prev = position.m_ptr->prev;
        delete position.m_ptr;
        m_size--;
        return next;
    }

    /**
     * @brief Função que retorna uma referência para o último elemento da lista
     *
     * @return * int&
     */
    int& back() {
        if (m_size == 0) throw std::runtime_error("Lista vazia");
        return m_head->prev->data;
    }

    /**
     * @brief Função const que retorna uma referência const para o último
     * elemento da lista
     *
     * @return * int&
     */
    const int& back() const {
        if (m_size == 0) throw std::runtime_error("Lista vazia");
        return m_head->prev->data;
    }

    /**
     * @brief Destroy the List object
     *
     */
    ~List() {
        clear();
        delete m_head;
    }

    /**
     * @brief Função que limpa a lista
     *
     */
    void clear() {
        while (!empty()) pop_back();
    }

    /**
     * @brief Função que verifica se uma lista está vazia
     *
     * @return true
     * @return false
     */
    bool empty() const { return m_size == 0; }

    /**
     * @brief Função que retorna uma iterador para o primeiro elemento da lista
     *
     * @return iterator_list
     */
    iterator begin() { return iterator(m_head->next); }

    /**
     * @brief Função que retorna um iterador para após o ultimo elemento
     *
     * @return iterator
     */
    iterator end() { return iterator(m_head); }
};

#endif  // LIST_H