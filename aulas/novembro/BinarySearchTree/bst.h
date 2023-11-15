#ifndef BST_H
#define BST_H
#include <iostream>
#include <stdexcept>

#include "node.h"
using namespace std;

class BST {
   public:
    BST();
    ~BST();
    void add(int key);  // Adicionar chave
    void bshow();
    void inorder();          // Percorre e imprime a arvore em ordem simetrica
    void remove(int key);    // Remover chave
    bool contains(int key);  // A arvore contem esta chave?
    int minimum();           // Devolve chave minima
    int maximum();           // Devolve chave maxima
    int sucessor(int k);     // Devolve chave sucessora de k
    int predecessor(int k);  // Devolve chave antecessora de k
   private:
    void _bshow(Node *node, std::string heranca);
    Node *root;
    void inorder(Node *node);
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

void BST::add(int key) {
    root = add(root, key);
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

int BST::minimum() {
    if (root == nullptr) {
        throw std::runtime_error("BST::minimum(): Árvore vazia");
    }
    return minimum(root)->key;
}

Node *BST::minimum(Node *node) {
    if (node->left == nullptr) {
        return node;
    }
    return minimum(node->left);
}

int BST::maximum() {
    if (root == nullptr) {
        throw std::runtime_error("BST::maximum(): Árvore vazia");
    }
    return maximum(root)->key;
}

Node *BST::maximum(Node *node) {
    if (node->right == nullptr) {
        return node;
    }
    return maximum(node->right);
}

void BST::bshow() {
    _bshow(root, "");
}

void BST::_bshow(Node *node, std::string heranca) {
    if (node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->right, heranca + "r");
    for (int i = 0; i < (int)heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if (heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if (node == nullptr) {
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if (node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->left, heranca + "l");
}

void BST::inorder() {
    inorder(root);
}

void BST::inorder(Node *node) {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->key << " ";
        inorder(node->right);
    }
}

int BST::sucessor(int k) {
    Node *temp = search(root, k);
    if (temp != nullptr) {
        Node *succ = sucessor(temp, root);
        if (succ != nullptr) {
            return succ->key;
        } else {
            throw std::runtime_error("BST::sucessor(): Não existe sucessor");
        }
    }
    throw std::runtime_error("BST::sucessor(): Chave inexistente");
}

Node *BST::sucessor(Node *x, Node *raiz) {
    if (x == nullptr || raiz == nullptr) {
        return nullptr;
    } else if (x->right != nullptr) {
        return minimum(x->right);
    } else {
        return ancestral_sucessor(x, raiz);
    }
}

Node *BST::ancestral_sucessor(Node *x, Node *raiz) {
    Node *atual = raiz;
    Node *sucessor = nullptr;
    while (atual != x) {
        if (x->key < atual->key) {
            sucessor = atual;
            atual = atual->left;
        } else {
            atual = atual->right;
        }
    }
    return sucessor;
}

void BST::remove(int key) {
    root = remove(key, root);
}

Node *BST::remove(int k, Node *node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (k < node->key) {
        node->left = remove(k, node->left);
    } else if (k > node->key) {
        node->right = remove(k, node->right);
    } else {
        if (node->left == nullptr) {
            Node *temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node *temp = node->left;
            delete node;
            return temp;
        }
        Node *temp = minimum(node->right);
        node->key = temp->key;
        node->right = remove(temp->key, node->right);
    }
    return node;
}

#endif
