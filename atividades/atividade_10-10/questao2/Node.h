// NAO MEXA NESTE ARQUIVO DE CABECALHO, ELE JA ESTA FINALIZADO E PRONTO PARA SER
// USADO PELO MOODLE
#ifndef NODE_H
#define NODE_H

/**
 * @brief Classe que implementa a logica de um Node da lista
 */
class Node {
    // Classe amiga da classe Node
    friend class ForwardList;

   private:
    int data;    // valor a ser armazenado
    Node* next;  // ponteiro para o proximo node

   public:
    // Construtor
    Node(const int& val, Node* nextPtr) {
        data = val;
        next = nextPtr;
    }
};

#endif