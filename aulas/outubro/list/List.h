#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

#include "Node.h"

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
    /**
     * @brief Construtor default: cria uma lista vazia
     *
     */
    List() {
        m_head = new Node(0, nullptr, nullptr);
        m_head->next = m_head;
        m_head->prev = m_head;
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
     * @brief Função que remove o último elemento da lista
     *
     */
    void pop_back() {
        // Se a lista estiver vazia, não faz nada
        if (m_size == 0) return;
        // cria um ponteiro para o último nó
        Node* lastNode = m_head->prev;
        // o prev do m_head aponta para o penúltimo nó
        m_head->prev = lastNode->prev;
        // o next do penúltimo nó aponta para o m_head
        lastNode->prev->next = m_head;
        delete lastNode;
        m_size--;
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
        while (m_size > 0) pop_back();
    }

    bool empty() const { return m_size == 0; }
};

#endif  // LIST_H