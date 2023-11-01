#ifndef NODE_H
#define NODE_H

template <typename Type>
struct Node {
    Type data;          // dado armazenado no nó
    Node<Type> *left;   // ponteiro para a subárvore esquerda
    Node<Type> *right;  // ponteiro para a subárvore direita

    /**
     * @brief Construct a new Node object
     *
     * @param data Dado a ser armazenado no nó
     * @param left filho esquerdo
     * @param right filho direito
     */
    Node(const Type &data, Node<Type> *left, Node<Type> *right)
        : data(data), left(left), right(right) {}

    /**
     * @brief Destroy the Node object
     *
     */
    ~Node() {
        delete left;
        delete right;
    }
};

#endif  // NODE_H