#ifndef NODE_H
#define NODE_H

template <typename Type>
struct Node {
    Type value;
    Node *left;
    Node *right;

    Node(Type value, Node<Type> *left, Node<Type> *right) {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    ~Node() {
        delete left;
        delete right;
    }
};

#endif  // NODE_H