/**
 * @file Queue.h
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief Cabecalho da fila que usa duas pilhas
 * @version 0.1
 * @date 13-11-2023
 *
 *
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

/**
 * @brief Implementação no node usado na stack
 *
 */
struct Node {
    int value;
    Node* next;

    /**
     * @brief Construct a new Node object
     *
     * @param val
     * @param next
     */
    Node(const int& val, Node* next);

    /**
     * @brief Destroy the Node object
     *
     */
    ~Node();
};

/**
 * @brief Implementação da stack
 *
 */
class Stack {
   private:
    Node* m_top{};
    unsigned m_size{};

   public:
    /**
     * @brief Construct a new Stack object
     *
     */
    Stack();

    /**
     * @brief Construct a new Stack object from a initializer list
     *
     * @param list
     */
    Stack(const std::initializer_list<int> list);

    /**
     * @brief Função que insere um elemento na pilha
     *
     * @param val
     */
    void push(const int& val);

    /**
     * @brief Remove o elemento do topo da pilha. Se a pilha estiver vazia, não
     * faz nada.
     *
     */
    void pop();

    /**
     * @brief Função que verifica se a pilha esá vazia
     *
     * @return true se a pilha estiver vazia,
     * @return false caso contrário.
     */
    bool empty() const;

    /**
     * @brief Função que retorna o valor do elemento do topo da pilha
     *
     * @return Referência para o elemento do topo da pilha
     */
    int& top();

    /**
     * @brief Função const que retorna o valor do elemento do topo da pilha
     *
     * @return Referência const para o elemento do topo da pilha
     */
    const int& top() const;

    /**
     * @brief Retorna o número atual de elementos na pilha
     *
     * @return Tamanho da pilha
     */
    unsigned size() const;

    /**
     * @brief Destroy the Stack object
     *
     */
    ~Stack();
};

/**
 * @brief Implementação da fila que usa duas pilhas
 *
 */
class Queue {
   private:
    Stack deposito;     // pilha de entrada
    Stack prateleira;   // pilha de saída
    unsigned m_size{};  // tamanho da fila

    /**
     * @brief Função que transfere todos os elementos do depósito para a prateleira
     *
     */
    void transfere();

   public:
    /**
     * @brief Construct a new Queue object
     *
     */
    Queue();

    ~Queue();

    /**
     * @brief Função que insere um elemento na fila
     *
     * @param val
     */
    void push(const int& val);

    /**
     * @brief Função que remove um elemento da fila.
     * Se a fila estiver vazia, lança uma exceção do tipo std::out_of_range
     * Se a praileira estiver vazia, transfere todos os elementos do depósito para a prateleira.
     * Remove o elemento do topo da prateleira.
     * Decrementa o tamanho da fila.
     *
     */
    void pop();

    /**
     * @brief Função que retorna o elemento do topo da fila.
     *
     * @return Referência para o elemento do topo da fila.
     */
    int& front();

    /**
     * @brief Função que retorna o tamanho da fila
     *
     * @return tamanho da fila
     */
    unsigned size() const;
};
#endif  // QUEUE_H