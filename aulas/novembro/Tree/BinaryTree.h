#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename Type>
class BinaryTree {
   private:
    Node<Type> *root;  // ponteiro para a raiz da árvore

   public:
    /**
     * @brief Construct a new Binary Tree object
     *
     */
    BinaryTree() { root = nullptr; }

    BinaryTree(const BinaryTree<Type> &other) {}

    /**
     * @brief Destroy the Binary Tree object
     *
     */
    ~BinaryTree() { delete root; }
};

#endif  // BINARYTREE_H