#ifndef STACK_H
#define STACK_H

#include <initializer_list>
#include <stdexcept>

template <typename Type>
struct Node {
    Type value;
    Node* next;

    /**
     * @brief Construct a new Node object
     *
     * @param val
     * @param next
     */
    Node(const Type& val, Node* next) {
        value = val;
        this->next = next;
    }

    /**
     * @brief Destroy the Node object
     *
     */
    ~Node() { delete next; }
};

template <typename Type>
class Stack {
   private:
    Node<Type>* m_top{};
    unsigned m_size{};

   public:
    /**
     * @brief Construct a new Stack object
     *
     */
    Stack() = default;

    /**
     * @brief Construct a new Stack object from a initializer list
     *
     * @param list
     */
    Stack(const std::initializer_list<Type> list) {
        for (const Type& elem : list) {
            push(elem);
        }
        /* for (auto it = list.begin(); it != list.end(); it++) {
            push(*it);
        } */
    }

    /**
     * @brief Função que insere um elemento na pilha
     *
     * @param val
     */
    void push(const Type& val) {
        Node<Type>* new_node = new Node<Type>(val, m_top);
        m_top = new_node;
        m_size++;
    }

    /**
     * @brief Remove o elemento do topo da pilha. Se a pilha estiver vazia, não
     * faz nada.
     *
     */
    void pop() {
        if (m_top == nullptr) return;
        Node<Type>* temp = m_top;  // ponteiro auxiliar para o primeiro elemento
        m_top = m_top->next;       // m_top aponta para o segundo elemento
        temp->next = nullptr;      // faz o auxiliar apontar para nullptr
        delete temp;               // deleta o primeiro elemento
        m_size--;                  // decrementa o tamanho da pilha
    }

    /**
     * @brief Função que verifica se a pilha esá vazia
     *
     * @return true se a pilha estiver vazia,
     * @return false caso contrário.
     */
    bool empty() const { return m_top == nullptr; }

    /**
     * @brief Função que retorna o valor do elemento do topo da pilha
     *
     * @return Type& - referência para o elemento do topo da pilha
     */
    Type& top() {
        if (empty()) throw std::out_of_range("Empty stack");
        return m_top->value;
    }
    const Type& top() const {
        if (empty()) throw std::out_of_range("Empty stack");
        return m_top->value;
    }

    /**
     * @brief Retorna o número atual de elementos na pilha
     *
     * @return unsigned
     */
    unsigned size() const { return m_size; }

    /**
     * @brief Destroy the Stack object
     *
     */
    ~Stack() { delete m_top; }
};

#endif