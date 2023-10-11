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

void ForwardList::push_front(const int &val) {
    m_head->next = new Node(val, m_head->next);
    m_size++;
}

int &ForwardList::front() { return m_head->next->data; }

const int &ForwardList::front() const { return m_head->next->data; }

void ForwardList::pop_front() {
    Node *aux = m_head->next;
    m_head->next = aux->next;
    delete aux;
    m_size--;
}

int &ForwardList::back() {
    Node *aux = m_head->next;
    while (aux->next != nullptr) {
        aux = aux->next;
    }
    return aux->data;
}
const int &ForwardList::back() const {
    Node *aux = m_head->next;
    while (aux->next != nullptr) {
        aux = aux->next;
    }
    return aux->data;
}

void ForwardList::push_back(const int &val) {
    if (m_size == 0) {
        m_head->next = new Node(val, m_head->next);
        m_size++;
        return;
    }
    Node *aux = m_head->next;
    while (aux->next != nullptr) {
        aux = aux->next;
    }
    Node *novo_node = new Node(val, nullptr);
    aux->next = novo_node;
    m_size++;
}

void ForwardList::pop_back() {
    if (m_size == 0) return;
    if (m_size == 1) {
        delete m_head->next;
        m_size--;
    }
    Node *aux = m_head->next;
    while (aux->next->next != nullptr) {
        aux = aux->next;
    }
    delete aux->next;
    aux->next = nullptr;
    m_size--;
}