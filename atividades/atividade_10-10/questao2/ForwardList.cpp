/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * Voce deve implementar as funcoes que faltam ao final deste arquivo
 ************************************************************************/
#include "ForwardList.h"

#include <iostream>

#include "Node.h"

// *********************************************************
// Implementacao das funcoes-membro da classe ForwardList
// *********************************************************

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList &lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while (lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->data, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const { return m_head->next == nullptr; }

int ForwardList::size() const { return m_size; }

void ForwardList::clear() {
    while (m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

void ForwardList::print() const {
    Node *temp = m_head->next;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << '\n';
}

void ForwardList::concat(ForwardList &lst) {
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while (lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->data, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
    m_size += lst.m_size;
    lst.clear();
}

void ForwardList::remove(const int &val) {
    Node *temp = m_head;
    while (temp->next != nullptr) {     // enquanto nao chegar no fim da lista
        if (temp->next->data == val) {  // se o proximo elemento for o valor
            Node *aux = temp->next;
            temp->next = aux->next;
            delete aux;
            m_size--;
        } else {
            temp = temp->next;  // senão, move o temp para o proximo elemento
        }
    }
}

ForwardList *ForwardList::clone() {
    ForwardList *clone = new ForwardList();
    Node *cloneLast = clone->m_head;
    Node *thisCurrent = m_head->next;
    while (thisCurrent != nullptr) {
        cloneLast->next = new Node(thisCurrent->data, nullptr);
        thisCurrent = thisCurrent->next;
        cloneLast = cloneLast->next;
    }
    clone->m_size = m_size;
    return clone;
}

void ForwardList::appendVector(const std::vector<int> &vec) {
    Node *thisLast = m_head;
    while (thisLast->next != nullptr) {
        thisLast = thisLast->next;
    }
    for (auto &i : vec) {
        thisLast->next = new Node(i, nullptr);
        thisLast = thisLast->next;
    }
    m_size += vec.size();
}

void ForwardList::swap(ForwardList &lst) {
    Node *aux = m_head;
    m_head = lst.m_head;
    lst.m_head = aux;
    unsigned auxSize = m_size;
    m_size = lst.m_size;
    lst.m_size = auxSize;
}

bool ForwardList::operator==(const ForwardList &lst) const {
    if (m_size != lst.m_size)
        return false;  // se o tamanho for diferente, retorna false
    Node *thisCurrent = m_head->next;
    Node *lstCurrent = lst.m_head->next;
    while (thisCurrent != nullptr) {
        if (thisCurrent->data != lstCurrent->data)
            return false;  // se algum elemento for diferente, retorna false
        thisCurrent = thisCurrent->next;
        lstCurrent = lstCurrent->next;
    }
    return true;  // se chegou aqui, é porque todos os elementos são iguais
}

bool ForwardList::operator!=(const ForwardList &lst) const {
    return !(*this == lst);
}

void ForwardList::reverse() {
    Node *prev = nullptr;          // ponteiro para o elemento anterior
    Node *current = m_head->next;  // ponteiro para o elemento atual
    Node *next = nullptr;          // ponteiro para o proximo elemento
    while (current != nullptr) {   // enquanto nao chegar no fim da lista
        next = current->next;      // guarda o proximo elemento
        current->next = prev;      // inverte o ponteiro do elemento atual
        prev = current;            // move o ponteiro do elemento anterior
        current = next;            // move o ponteiro do elemento atual
    }
    m_head->next = prev;
}