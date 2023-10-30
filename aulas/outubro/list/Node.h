#ifndef NODE_H
#define NODE_H

#include <iostream>

/**
 * @brief Struct de um Node pertencente à uma lista duplamente encadeada
 *
 */
struct Node {
    int data;    // Dado armazenado no Node
    Node* next;  // Ponteiro para o próximo Node
    Node* prev;  // Ponteiro para o Node anterior

    /**
     * @brief Construct a new Node object
     *
     */
    Node(const int& data, Node* ptrPrev, Node* ptrNext) {
        this->data = data;
        this->next = ptrNext;
        this->prev = ptrPrev;
    }

    /**
     * @brief Destroy the Node object
     *
     */
    ~Node() { std::cout << "Node " << this << " destruído" << std::endl; }
};

#endif  // NODE_H