#ifndef NODE_H
#define NODE_H

template <typename Type>
struct Node {
    Type data;          // valor guardado
    Node<Type>* left;   // pointer to left subtree
    Node<Type>* right;  // pointer to right subtree

    // Construtor
    Node(const Type& d, Node<Type>* l, Node<Type>* r)
        : data(d), left(l), right(r) {}
};

#endif