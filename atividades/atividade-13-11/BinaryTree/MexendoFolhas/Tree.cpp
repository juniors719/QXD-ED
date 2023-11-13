#include "Tree.h"

#include <iostream>
#include <sstream>
#include <string>

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l = nullptr, Node *r = nullptr) {
        this->key = k;
        this->left = l;
        this->right = r;
    }
};

// Construtor
Tree::Tree(std::string serial) {
    _root = nullptr;
    std::stringstream ss(serial);
    _serializeTree(ss, &_root);
}

void Tree::_serializeTree(std::stringstream &ss, Node **node) {
    std::string value;
    ss >> value;
    if (value == "#")  // filho == nullptr
        return;
    int key = std::stoi(value);
    *node = new Node(key);
    _serializeTree(ss, &((*node)->left));
    _serializeTree(ss, &((*node)->right));
}

Tree::~Tree() {
    _root = _clear(_root);
}

Node *Tree::_clear(Node *node) {
    if (node != nullptr) {  // caso geral: vamos liberar essa arvore
        node->left = _clear(node->left);
        node->right = _clear(node->right);
        delete node;
    }
    return nullptr;
}

void Tree::preorder() {
    _preorder(_root);
}

void Tree::_preorder(Node *node) {
    if (node != nullptr) {  // Caso Geral
        std::cout << node->key << " ";
        _preorder(node->left);
        _preorder(node->right);
    }
}

void Tree::inorder() {
    _inorder(_root);
}

void Tree::_inorder(Node *node) {
    if (node != nullptr) {  // Caso Geral
        _inorder(node->left);
        std::cout << node->key << " ";
        _inorder(node->right);
    }
}

void Tree::bshow() {
    _bshow(_root, "");
}

void Tree::_bshow(Node *node, std::string heranca) {
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

int Tree::count_leaves() {
    return _count_leaves(_root);  // chamada da funcao recursiva privada
}

int Tree::_count_leaves(Node *node) {
    if (node == nullptr)  // Caso base: arvore vazia
        return 0;
    if (node->left == nullptr && node->right == nullptr)  // Caso base: no folha
        return 1;
    return _count_leaves(node->left) + _count_leaves(node->right);  // Caso geral
}

void Tree::delete_leaves() {
    _delete_leaves(_root);  // chamada da funcao recursiva privada
}

Node *Tree::_delete_leaves(Node *node) {
    if (node == nullptr)  // Caso base: arvore vazia
        return nullptr;
    if (node->left == nullptr && node->right == nullptr) {  // Caso base: no folha
        delete node;
        return nullptr;
    }
    node->left = _delete_leaves(node->left);    // Caso geral: no nao folha
    node->right = _delete_leaves(node->right);  // Caso geral: no nao folha
    return node;
}

void Tree::delete_leaves_with_value(int key) {
    _delete_leaves_with_value(key, _root);  // chamada da funcao recursiva privada
}

Node *Tree::_delete_leaves_with_value(int key, Node *node) {
    if (node == nullptr)  // Caso base: arvore vazia
        return nullptr;
    if (node->left == nullptr && node->right == nullptr) {  // Caso base: no folha
        if (node->key == key) {
            delete node;
            return nullptr;
        }
        return node;
    }
    node->left = _delete_leaves_with_value(key, node->left);    // Caso geral: no nao folha
    node->right = _delete_leaves_with_value(key, node->right);  // Caso geral: no nao folha
    return node;
}