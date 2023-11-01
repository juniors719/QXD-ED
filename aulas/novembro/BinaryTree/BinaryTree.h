#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

template <typename Type>
class BinaryTree {
   private:
    Node<Type> *m_root;  // ponteiro para a raiz da árvore

   public:
    /**
     * @brief Construct a new Binary Tree object
     *
     */
    BinaryTree() = default;

    BinaryTree(const Type &data, BinaryTree<Type> &leftTree,
               BinaryTree<Type> &rightTree) {
        m_root = new Node<Type>(data, leftTree.m_root, rightTree.m_root);
    }

    BinaryTree(const BinaryTree<Type> &other) {}

    /**
     * @brief Destroy the Binary Tree object
     *
     */
    ~BinaryTree() { delete m_root; }

    /**
     * @brief Função que imprime recursivamente os elementos da árvore.
     * Primeiro imprime a raiz, depois a subárvore esquerda e depois a subárvore
     * direita.
     *
     * @param node Nó raiz
     */
    void preOrdem(Node<Type> *node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preOrdem(node->left);
            preOrdem(node->right);
        }
    }

    /**
     * @brief Função que imprime recursivamente os elementos da árvore.
     * Primeiro imprime a subárvore esquerda, depois a subárvore direita e
     * depois a raiz.
     *
     * @param node Nó raiz
     */
    void posOrdem(Node<Type> *node) {
        if (node != nullptr) {
            posOrdem(node->left);
            posOrdem(node->right);
            std::cout << node->data << " ";
        }
    }

    /**
     * @brief Função que imprime recursivamente os elementos da árvore.
     * Primeiro imprime a subárvore esquerda, depois a raiz e depois a subárvore
     * direita.
     *
     * @param node
     */
    void ordemSimetrica(Node<Type> *node) {
        if (node != nullptr) {
            ordemSimetrica(node->left);
            std::cout << node->data << " ";
            ordemSimetrica(node->right);
        }
    }
};

#endif  // BINARYTREE_H