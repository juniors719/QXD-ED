#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include <sstream>
#include <stack>

#include "Node.h"

template <typename Type>
class BinaryTree {
   private:
    Node<Type>* m_root{};  // ponteiro para a raiz

   public:
    // Construtor vazio
    BinaryTree() = default;

    // Construtor que cria uma arvore a
    // partir de outras duas
    BinaryTree(const Type& val, BinaryTree<Type>& tleft, BinaryTree<Type>& tright) {
        m_root = new Node<Type>(val, tleft.m_root, tright.m_root);
        tleft.m_root = tright.m_root = nullptr;
    }

    // Construtor que cria uma arvore a partir de uma serializacao
    BinaryTree(const std::string& serial) {
        std::stringstream ss(serial);
        m_root = deserialize(ss);
    }

    // Funcao que retorna true se e somente se
    // a arvore estiver vazia
    bool empty() const { return m_root == nullptr; }

    // Funcao publica que imprime as chaves em
    // pre-ordem
    void preOrder() const { preOrder(m_root); }

    void iterativePreOrdem() const {
        std::stack<Node<Type>*> pilha;
        Node<Type>* node = m_root;
        while (node != nullptr || !pilha.empty()) {
            if (node != nullptr) {
                std::cout << node->data << " ";
                pilha.push(node);
                node = node->left;
            } else {
                node = pilha.top();
                pilha.pop();
                node = node->right;
            }
        }
    }

    // pos-ordem
    void postOrder() const { postOrder(m_root); }

    void iterativePostOrder() const {
        std::stack<Node<Type>*> pilha;
        Node<Type>* node = m_root;
        Node<Type>* last = nullptr;
        while (node != nullptr || !pilha.empty()) {
            if (node != nullptr) {
                pilha.push(node);
                node = node->left;
            } else {
                Node<Type>* top = pilha.top();
                if (top->right != nullptr && top->right != last) {
                    node = top->right;
                } else {
                    std::cout << top->data << " ";
                    last = top;
                    pilha.pop();
                }
            }
        }
    }

    // ordem simetrica
    void inOrder() const { inOrder(m_root); }

    void iterativeInOrder() const {
        std::stack<Node<Type>*> pilha;
        Node<Type>* node = m_root;
        while (node != nullptr || !pilha.empty()) {
            if (node != nullptr) {
                pilha.push(node);
                node = node->left;
            } else {
                node = pilha.top();
                pilha.pop();
                std::cout << node->data << " ";
                node = node->right;
            }
        }
    }

    // Funcao publica que retorna se um certo valor
    // esta na arvore
    bool contains(const Type& val) const { return contains(m_root, val); }

    // Função pública que limpa a árvore
    // Deixa a árvore vazia
    void clear() { m_root = clear(m_root); }

    ~BinaryTree() { clear(); }

    // Função que calcula a quantidade de nós na árvore
    unsigned size() const { return size(m_root); }

    // Construtor de cópia e operador de atribuição desabilitados
    BinaryTree(const BinaryTree<Type>&) = delete;
    BinaryTree<Type>& operator=(const BinaryTree<Type>&) = delete;

    // Função que retorna uma string com a serialização da árvore
    std::string serial() const {
        std::stringstream ss;
        serialize(m_root, ss);
        return ss.str();
    }

   private:
    // Função recursiva que recebe a raiz de uma árvore e uma stringstream, e
    // percorre a árvore em pre-ordem, retornando a serialização da árvore na
    // stringstream
    void serialize(Node<Type>* node, std::stringstream& ss) const {
        if (node == nullptr) {  // caso base
            ss << "# ";
        } else {  // caso geral
            ss << node->data << " ";
            serialize(node->left, ss);
            serialize(node->right, ss);
        }
    }

    // Função recursiva que recebe uma stringstream contendo o serial de uma
    // árvore. Ela consome o primeiro valor contido nessa stringstream, cria um
    // nó e faz o mesmo procedimento para as sub-árvores esquerda e direita do
    // nó.
    Node<Type>* deserialize(std::stringstream& ss) {
        std::string val;
        ss >> val;
        if (val == "#") {
            return nullptr;
        } else {
            Type data;
            std::stringstream(val) >> data;
            Node<Type>* node = new Node<Type>(data, nullptr, nullptr);
            node->left = deserialize(ss);
            node->right = deserialize(ss);
            return node;
        }
    }

    // funcao recursiva que percorre a arvore
    // em pre-ordem
    void preOrder(Node<Type>* node) const {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    // funcao recursiva que percorre a arvore
    // em pos-ordem
    void postOrder(Node<Type>* node) const {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->data << " ";
        }
    }
    // funcao recursiva que percorre a arvore
    // em ordem simetrica
    void inOrder(Node<Type>* node) const {
        if (node != nullptr) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    // Funcao recursiva que recebe a raiz de uma
    // arvore e um certo valor val e retorna true
    // se e somente se a arvore contem val
    // como uma de suas chaves
    bool contains(Node<Type>* node, const Type& val) const {
        if (node == nullptr) return false;
        return (node->data == val) || contains(node->left, val) ||
               contains(node->right, val);
    }

    // Funcao recursiva que recebe
    // a raiz de uma arvore e
    // deleta todos os seus nos
    // Retorna a arvore vazia
    Node<Type>* clear(Node<Type>* node) {
        if (node == nullptr) {  // caso base
            return nullptr;
        } else {  // caso geral
            node->left = clear(node->left);
            node->right = clear(node->right);
            delete node;
            return nullptr;
        }
    }

    // Função recursiva que recebe a raiz de uma árvore e retorna o número de
    // nós na árvore
    unsigned size(Node<Type>* node) const {
        if (node == nullptr) return 0;
        return 1 + size(node->left) + size(node->right);
    }
};

#endif  // BINARY_TREE_H