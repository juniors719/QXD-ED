#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>

class Node {
    friend class ForwardList;
    friend class iterator_list;
    int data;    // valor guardado no nó
    Node* next;  // ponteiro para o próximo nó

    /**
     * @brief Construct a new Node object
     *
     * @param data
     * @param next
     */
    Node(const int& data, Node* next) {
        this->data = data;
        this->next = next;
    }

    /**
     * @brief Destroy the Node object
     *
     */
    ~Node() { std::cout << "Node " << data << " destruído" << std::endl; }
};

/**
 * @brief Classe que implementa a logica de um ForwardIterator
 *
 */
class iterator_list {
   private:
    friend class ForwardList;
    Node* m_ptr;  // ponteiro para o nó atual

   public:
    /**
     * @brief Construct a new iterator object
     *
     * @param ptr ponteiro para o nó atual
     */
    iterator_list(Node* ptr) { m_ptr = ptr; }

    /**
     * @brief Sobrecarga do operador de pré-incremento.
     * Faz o iterador apontar para o proximo elemento da lista.
     *
     * @return iterator& retorna uma referencia para o iterador
     */
    iterator_list& operator++() {
        m_ptr = m_ptr->next;
        *this;
    }

    /**
     * @brief Sobrecarga do operador de pós-incremento.
     * Faz o iterador apontar para o proximo elemento da lista.
     *
     * @return iterator retorna uma copia do iterador
     */
    iterator_list operator++(int) {
        iterator_list temp = *this;
        m_ptr = m_ptr->next;
        return temp;
    }

    /**
     * @brief Sobrecarga do operador de desreferenciação.
     *
     * @return int& retorna uma referencia para o dado do nó atual.
     */
    int& operator*() { return m_ptr->data; }

    /**
     * @brief Sobrecarga do operador de igualdade.
     *
     * @param other iterador a ser comparado
     * @return true se os iteradores apontam para o mesmo nó
     * @return false caso contrário
     */
    bool operator==(const iterator_list& other) { return m_ptr == other.m_ptr; }

    /**
     * @brief Sobrecarga do operador de desigualdade.
     *
     * @param other iterador a ser comparado
     * @return true se os iteradores apontam para nós diferentes
     * @return false caso contrário
     */
    bool operator!=(const iterator_list& other) { return m_ptr != other.m_ptr; }
};

/**
 * @brief Classe que implementa uma lista encadeada simples
 *
 */
class ForwardList {
   private:
    Node* m_head{};         // ponteiro para o nó sentinela
    Node* m_tail{};         // ponteiro para o último nó da lista
    unsigned int m_size{};  // numero de elementos atualmente na lista

   public:
    /**
     * @brief Construct a new Forward List object
     *
     */
    ForwardList() { m_tail = m_head = new Node(0, nullptr); }

    /**
     * @brief Construct a new Forward List object
     *
     * @param other
     */
    ForwardList(const ForwardList& other) {
        m_tail = m_head = new Node(0, nullptr);
        Node* aux = other.m_head->next;
        while (aux != nullptr) {
            m_tail->next = new Node(aux->data, nullptr);
            aux = aux->next;
            m_tail = m_tail->next;
        }
        m_size = other.m_size;
    }

    /**
     * @brief Função que imprime a lista
     *
     */
    void print() {
        Node* aux = m_head->next;
        while (aux != nullptr) {
            std::cout << aux->data << " ";
            aux = aux->next;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Função que retorna o tamanho da lista
     *
     * @return unsigned int
     */
    unsigned int size() const { return m_size; }

    /**
     * @brief função que insere no início da lista
     *
     * @param data valor a ser inserido
     */
    void push_front(const int& data) {
        Node* new_node = new Node(data, m_head->next);
        m_head->next = new_node;
        if (m_size == 0) m_tail = new_node;
        m_size++;
    }

    /**
     * @brief função que insere no final da lista
     *
     * @param data
     */
    void push_back(const int& data) {
        Node* new_node = new Node(data, nullptr);
        m_tail->next = new_node;
        m_tail = new_node;
        m_size++;
    }

    /**
     * @brief função que remove o primeiro elemento da lista
     *
     */
    void pop_front() {
        if (m_size == 0) return;
        Node* aux = m_head->next;
        m_head->next = aux->next;
        if (m_tail == aux) m_tail = m_head;
        delete aux;
        m_size--;
    }

    /**
     * @brief Função que remove todos os elementos da lista
     *
     */
    void clear() {
        while (m_head->next != nullptr) {
            Node* aux2 = m_head->next;
            m_head->next = aux2->next;
            delete aux2;
        }
        m_tail = m_head;
        m_size = 0;
    }

    /**
     * @brief Destroy the Forward List object
     *
     */
    ~ForwardList() {
        while (m_head->next != nullptr) {
            Node* aux2 = m_head->next;
            m_head->next = aux2->next;
            delete aux2;
        }
        m_tail = m_head;
        m_size = 0;
        delete m_head;
    }

    /**
     * @brief Função que retorna um iterador para o primeiro elemento da lista
     *
     * @return iterator_list iterador para o primeiro elemento da lista
     */
    iterator_list begin() { return iterator_list(m_head->next); }

    /**
     * @brief Função que retorna um iterador para o elemento após o último
     *
     * @return iterator_list iterador para o elemento após o último
     */
    iterator_list end() { return iterator_list(nullptr); }

    /**
     * @brief Função que retorna um iterador para o nó sentinela
     *
     * @return iterator_list iterador para o nó sentinela
     */
    iterator_list before_begin() { return iterator_list(m_head); }

    // FUNÇÃO O(N²) -> NÃO FAÇA ISSO
    /**
     * @brief Sobrecarga do operador de indexação.
     * Recebe um índice e retorna uma referência para
     * o dado naquela posição.
     * Essa função não checa se o índice é válido.
     * Ela confia no usuário para passar um índice válido.
     *
     * @param index índice do elemento a ser retornado
     * @return int&
     */
    // int& operator[](unsigned int index) {
    //     Node* aux = m_head->next;
    //     for (unsigned int i = 0; i < index; i++) {
    //         aux = aux->next;
    //     }
    //     return aux->data;
    // }
};

#endif  // FORWARD_LIST_H