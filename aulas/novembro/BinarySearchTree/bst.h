#ifndef BST_H
#define BST_H
#include <stdexcept>

#include "node.h"
using namespace std;

class BST {
   public:
    BST();
    ~BST();
    void add(int key);       // Adicionar chave
    void remove(int key);    // Remover chave
    bool contains(int key);  // A arvore contem esta chave?
    int minimum();           // Devolve chave minima
    int maximum();           // Devolve chave maxima
    int successor(int k);    // Devolve chave sucessora de k
    int predecessor(int k);  // Devolve chave antecessora de k
   private:
    Node *root;
    Node *add(Node *node, int key);
    Node *search(Node *node, int key);
    Node *clear(Node *node);
    Node *minimum(Node *node);
    Node *maximum(Node *node);
    Node *ancestral_sucessor(Node *x, Node *raiz);
    Node *ancestral_predecessor(Node *x, Node *raiz);
    Node *sucessor(Node *x, Node *raiz);
    Node *predecessor(Node *x, Node *raiz);
    Node *remove(int k, Node *node);
    Node *removeRoot(Node *node);
};

// ******************************************************
// Implementacao da funcoes-membro da classe BST
// *******************************************************

// Construtor
BST::BST() {
    root = nullptr;
}

// Destrutor
BST::~BST() {
    root = clear(root);
}

// Esta funcao recebe um ponteiro para um node e libera
// os nos da arvore enraizada nesse node. A funcao devolve
// nullptr apos apagar a arvore enraizada em node
Node *BST::clear(Node *node) {
    if (node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
    }
    return nullptr;
}

Node *BST::add(Node *node, int key) {
    if (node == nullptr) {
        return new Node(key, nullptr, nullptr);
    }
    if (key < node->key) {
        node->left = add(node->left, key);
    } else {
        node->right = add(node->right, key);
    }
    return node;
}

Node *BST::search(Node *node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return search(node->left, key);
    }
    return search(node->right, key);
}

bool BST::contains(int key) {
    // return search(root, key) != nullptr;

    // versão iterativa

    Node *node = root;
    while (node != nullptr && node->key != key) {
        if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return node != nullptr;
}

#endif
