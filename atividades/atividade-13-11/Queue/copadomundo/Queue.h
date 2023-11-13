#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

/**
 * @brief struct que representa um nó de uma lista encadeada
 *
 * @tparam Type
 */
template <typename Type>
struct Node {
    Type value;
    Node* next;

    Node(const Type& val, Node* nextPtr) {
        value = val;
        next = nextPtr;
    }

    ~Node() {
        delete next;  // deleta recursivamente todos os nós após este
    }
};

/**
 * @brief Classe que implementa uma fila do tipo FIFO (first-in first-out)
 *
 * @tparam Type tipo genérico
 */
template <typename Type>
class Queue {
   private:
    Node<Type>* m_first{};  // ponteiro para o primeiro nó da fila
    Node<Type>* m_last{};   // ponteiro para o último nó da fila
    unsigned int m_size{};  // numero de elementos atualmente na fila

   public:
    /**
     * @brief Construtor default: cria fila vazia
     *
     */
    Queue() = default;  // first e last apontam para nullptr e size = 0

    /**
     * @brief Função que insere um elemento no final da fila
     *
     * @param elem elemento a ser inserido
     */
    void push(const Type& elem) {
        if (m_first == nullptr) {
            m_first = m_last = new Node<Type>(elem, nullptr);
        } else {
            m_last->next = new Node<Type>(elem, nullptr);
            m_last = m_last->next;
        }
        m_size++;
    }

    /**
     * @brief Função que remove o primeiro elemento da fila. Se a fila estiver
     * vazia, a função não faz nada.
     *
     */
    void pop() {
        if (m_first != nullptr) {
            Node<Type>* aux = m_first;
            m_first = m_first->next;
            aux->next = nullptr;
            delete aux;
            m_size--;
            if (m_size == 0) m_last = nullptr;
        }
    }

    /**
     * @brief Função que retorna o primeiro elemento da fila. Se a fila estiver
     * vazia, a função lança uma exceção do tipo std::runtime_error
     *
     * @return const - Type primeiro elemento da fila
     */
    Type& front() {
        if (m_size == 0) throw std::runtime_error("Fila vazia");
        return m_first->value;
    }
    const Type front() const {
        if (m_size == 0) throw std::runtime_error("Fila vazia");
        return m_first->value;
    }

    /**
     * @brief Função que retorna o último elemento da fila. Se a fila estiver
     * vazia, a função lança uma exceção do tipo std::runtime_error
     *
     * @return Type&
     */
    Type& back() {
        if (m_size == 0) throw std::runtime_error("Fila vazia");
        return m_last->value;
    }
    const Type back() const {
        if (m_size == 0) throw std::runtime_error("Fila vazia");
        return m_last->value;
    }

    /**
     * @brief Destroy the Queue object
     *
     */
    ~Queue() {
        delete m_first;  // deleta recursivamente todos os nós da fila
    }

    /**
     * @brief Função que retorna o número de elementos atualmente na fila
     *
     * @return unsigned int
     */
    unsigned int size() const { return m_size; }

    /**
     * @brief Função que retorna true se a fila estiver vazia e false caso
     * contrário
     *
     * @return true -> fila vazia.
     * @return false -> fila não vazia.
     */
    bool empty() const { return m_size == 0; }

    /**
     * @brief Troca duas filas
     *
     * @param other fila a ser trocada com a fila atual
     */
    void swap(Queue& other) {
        std::swap(m_first, other.m_first);  // troca os ponteiros first
        std::swap(m_last, other.m_last);    // troca os ponteiros last
        std::swap(m_size, other.m_size);    // troca os tamanhos
    }

    // PARA CASA:
    // Implemente os operadores de atribuição (=) e o construtor de cópia
};

#endif