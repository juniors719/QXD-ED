/**
 * @file Queue.h
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief Implementação das funções da fila que usa duas pilhas
 * @version 0.1
 * @date 13-11-2023
 *
 *
 */

#include "Queue.h"

Node::Node(const int& val, Node* next) {
    value = val;
    this->next = next;
}

Node::~Node() { delete next; }

Stack::Stack() = default;

Stack::Stack(const std::initializer_list<int> list) {
    for (const int& elem : list) {
        push(elem);
    }
}

void Stack::push(const int& val) {
    Node* new_node = new Node(val, m_top);
    m_top = new_node;
    m_size++;
}

void Stack::pop() {
    if (m_top == nullptr) return;
    Node* temp = m_top;
    m_top = m_top->next;
    temp->next = nullptr;
    delete temp;
    m_size--;
}

bool Stack::empty() const { return m_top == nullptr; }

int& Stack::top() {
    if (empty()) throw std::out_of_range("Empty stack");
    return m_top->value;
}

const int& Stack::top() const {
    if (empty()) throw std::out_of_range("Empty stack");
    return m_top->value;
}

unsigned Stack::size() const { return m_size; }

Stack::~Stack() { delete m_top; }

void Queue::transfere() {
    while (!deposito.empty()) {
        prateleira.push(deposito.top());
        deposito.pop();
    }
}

Queue::Queue() {
    m_size = 0;
}

Queue::~Queue() = default;

void Queue::push(const int& val) {
    deposito.push(val);
    m_size++;
}

void Queue::pop() {
    if (m_size == 0)
        throw std::out_of_range("Fila vazia");
    if (prateleira.empty())
        transfere();
    prateleira.pop();
    m_size--;
}

int& Queue::front() {
    if (m_size == 0)
        throw std::out_of_range("Fila vazia");
    if (prateleira.empty())
        transfere();
    return prateleira.top();
}

unsigned Queue::size() const { return m_size; }