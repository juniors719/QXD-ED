/**
 * @file Vector.h
 * @author Atilio G. Luiz
 * @date 26-09-2023
 * @brief Classe que implementa uma lista linear sequencial de inteiros
 */
#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>

class Vector {
   private:
    unsigned int m_size{};      // numero de elementos atualmente na lista
    unsigned int m_capacity{};  // capacidade atual da lista: o tamanho real do
                                // vetor interno
    int* m_vet{};               // ponteiro para o vetor de inteiros

   public:
    // Construtor default: cria lista vazia e com capacidade zero
    // Complexidade: O(1)
    Vector() = default;
    // Construtor que recebe a capacidade
    // Complexidade: O(1)
    Vector(unsigned int cap);
    // Construtor de copia (copy constructor)
    // Foi preciso implementar nossa propria versao desse construtor
    // para que ele funcione da forma correta
    // Complexidade: O(1)
    Vector(const Vector& v);
    // Funcao que recebe um valor inteiro newCap
    // que sera a nova capacidade.
    // Se m_capacity >= newCap, a funcao faz nada.
    // Caso contrario, a funcao aumenta a capacidade
    // do Vector para um valor maior ou igual a newCap
    // Complexidade: O(n)
    void reserve(unsigned int newCap);
    // Funcao que insere um elemento no final
    // da lista. Se a lista ficar cheia, ele
    // primeiro aumenta a capacidade da lista
    // e somente depois insere no final.
    // Complexidade: O(n) no pior caso
    void push_back(int val);
    // Funcao que recebe um índice i e retorna
    // o elemento que esta no índice i.
    // Se o indice nao existir na lista, essa funcao
    // vai lancar uma excecao.
    // Complexidade: O(1)
    int& at(unsigned int i);
    // Versao const da funcao at()
    // Complexidade: O(1)
    const int& at(unsigned int i) const;
    // Destrutor: libera memoria alocada
    // Complexidade: O(1)
    ~Vector();
    // Funcao const que retorna o numero de elementos na lista
    // Complexidade: O(1)
    unsigned int size() const;
    // Funcao const que retorna a capacidade total da lista
    // Complexidade: O(1)
    unsigned int capacity() const;
    // Funcao const que retorna true se e somente se a lista estiver vazia
    // Complexidade: O(1)
    bool empty() const;
    // sobrecarga do operador de indexacao
    // recebe um indice i e retorna o elemento no indice i
    // Se o indice não estiver dentro do intervalo,
    // o comportamento dessa funcao é indeterminado.
    // Complexidade: O(1)
    int& operator[](unsigned int i);
    // versao const do operador[]
    // Complexidade: O(1)
    const int& operator[](unsigned int i) const;
    // Funcao que remove o ultimo elemento da lista, se a lista nao estiver
    // vazia. Se a lista estiver vazia, entao essa funcao nao faz nada. O que
    // essa funcao faz de fato eh apenas decrementar o atributo m_size.
    // Complexidade: O(1)
    void pop_back();
    // Deletei o operador de atribuicao
    Vector& operator=(const Vector& v) = delete;

    // ***********************************************************************
    // FUNCOES A SEREM IMPLEMENTADAS
    // Tarefa: implemente as funcoes abaixo.
    // Cada funcao ja vem acompanhada de uma explicacao de como deve ser
    // o seu funcionamento.
    // ***********************************************************************

    // funcao front
    // Retorna uma referencia (reference) para o primeiro elemento na lista.
    // Se nao existir primeiro elemento, o comportamento dessa funcao eh
    // indeterminado. Complexidade: O(1)
    int& front();

    // versao const da funcao front
    // Retorna uma 'const reference' para o primeiro elemento na lista.
    // Se nao existir primeiro elemento, o comportamento dessa funcao eh
    // indeterminado. Complexidade: O(1)
    const int& front() const;

    // funcao back
    // Retorna uma referencia (reference) para o ultimo elemento na lista.
    // Se nao existir ultimo elemento, o comportamento dessa funcao eh
    // indeterminado. Complexidade: O(1)
    int& back();

    // versao const da funcao back
    // Retorna uma 'const reference' para o ultimo elemento na lista.
    // Se nao existir ultimo elemento, o comportamento dessa funcao eh
    // indeterminado. Complexidade: O(1)
    const int& back() const;

    // funcao remove_all
    // Essa funcao remove todas as ocorrencias do elemento 'elem' da lista
    // Nao esqueca de decrementar o valor do atributo m_size sempre
    // que um elem for removido da lista
    // Complexidade: O(n) no pior caso
    void remove_all(int elem);

    // funcao insert_at
    // Esta funcao adiciona o elemento 'elem' no indice 'index' (somente se 0 <=
    // index <= m_size). Se o 'index' estiver fora do intervalo especificado
    // acima, esta funcao lanca uma excecao do tipo std::out_of_range com a
    // mensagem "indice fora do intervalo". Antes de fazer a insercao, todos os
    // elementos posicionado a partir do indice k em diante sao deslocados uma
    // posicao para a direita. Cuidado com a alocacao de memoria. Complexidade:
    // O(n) no pior caso
    void insert_at(int elem, unsigned int index);

    // Funcao remove_at
    // Essa funcao remove o elemento posicionado no indice 'index' da lista.
    // O 'index' deve estar dentro do intervalo: 0 <= index <= m_size-1
    // Se o 'index' estiver fora do intervalo especificado acima, esta funcao
    // lanca uma excecao do tipo std::out_of_range com a mensagem "indice fora
    // do intervalo". Ao remover um elemento, pode ser necessario deslocar
    // elementos para a esquerda. Complexidade: O(n) no pior caso
    void remove_at(unsigned int index);
};

// ----------------------------------------------------------
// Implementacao das funcoes-membro da classe Vector
// ----------------------------------------------------------
Vector::Vector(unsigned int cap) : m_size{0}, m_capacity{cap} {
    m_vet = new int[m_capacity];
}

Vector::Vector(const Vector& v) {
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_vet = new int[m_capacity];
    for (unsigned int i = 0; i < m_size; ++i) {
        m_vet[i] = v.m_vet[i];
    }
}

void Vector::reserve(unsigned int newCap) {
    if (m_capacity < newCap) {
        m_capacity = newCap;
        int* aux = new int[m_capacity];
        for (unsigned int i = 0; i < m_size; ++i) {
            aux[i] = m_vet[i];
        }
        delete[] m_vet;
        m_vet = aux;
    }
}

void Vector::push_back(int val) {
    if (m_size == m_capacity) {  // aumenta de precisar
        reserve(2 * (m_capacity + 1));
    }
    m_vet[m_size] = val;  // insere
    m_size++;             // incrementa m_size
}

int& Vector::at(unsigned int i) {
    if (i < m_size) {
        return m_vet[i];
    } else {
        throw std::out_of_range("erro no indice");
    }
}

const int& Vector::at(unsigned int i) const {
    if (i < m_size) {
        return m_vet[i];
    } else {
        throw std::out_of_range("erro no indice");
    }
}

Vector::~Vector() { delete[] m_vet; }

unsigned int Vector::size() const { return m_size; }

unsigned int Vector::capacity() const { return m_capacity; }

bool Vector::empty() const { return m_size == 0; }

int& Vector::operator[](unsigned int i) { return m_vet[i]; }

const int& Vector::operator[](unsigned int i) const { return m_vet[i]; }

void Vector::pop_back() {
    if (m_size > 0) {
        m_size--;
    }
}

int& Vector::front() { return m_vet[0]; }

const int& Vector::front() const { return m_vet[0]; }

int& Vector::back() { return m_vet[m_size - 1]; }

const int& Vector::back() const { return m_vet[m_size - 1]; }

void Vector::remove_at(unsigned int index) {
    if (index <= m_size - 1) {
        for (int i = index; i < m_size - 1; i++) {
            m_vet[i] = m_vet[i + 1];
        }
        m_size--;
    } else {
        throw std::out_of_range("indice fora do intervalo");
    }
}

void Vector::remove_all(int elem) {
    int index = 0;
    for (int i = 0; i < m_size; i++) {
        if (m_vet[i] != elem) {
            m_vet[index] = m_vet[i];
            index++;
        }
    }
    m_size = index;
}

void Vector::insert_at(int elem, unsigned int index) {
    if (index <= m_size) {
        if (m_size == m_capacity) {
            reserve((2 * m_capacity) + 1);
        }
        for (int i = m_size; i > index; i--) {
            m_vet[i] = m_vet[i - 1];
        }
        m_vet[index] = elem;
        m_size++;
    } else {
        throw std::out_of_range("indice fora do intervalo");
    }
}
#endif  // VECTOR_H