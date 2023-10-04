/**
 * @file Vector.h
 * @author Atilio G. Luiz
 * @date 02-10-2023
 * @brief Classe generica que implementa uma lista linear sequencial
 */
#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>

template <typename T>
class Vector {
   private:
    unsigned int m_size{};      // numero de elementos atualmente na lista
    unsigned int m_capacity{};  // capacidade atual da lista: o tamanho real do
                                // vetor interno
    T* m_vet{};                 // ponteiro para o vetor de inteiros

   public:
    // Classe interna iterator
    // implementa a lógica de um iterador para a classe Vector
    class iterator {
       private:
        T* m_ptr;  // ponteiro para o elemento atual do vector

       public:
        // Construtor customizado
        iterator(T* ptr = nullptr) { m_ptr = ptr; };

        // Sobrecarga do operador de dereferencia
        // retorna uma referência para o elemento apontado pelo iterador
        T& operator*() { return *m_ptr; }

        // operador seta ->
        // retorna o valor do atributo privado do iterador, que é um ponteiro
        T* operator->() { return m_ptr; }

        // sobrecarga do operador de indexação
        // recebe um inteiro i e retorna o elemento no indice i
        T& operator[](long n) { return *(m_ptr + n); }

        // sobrecarga do operador de pre-incremento
        // faz o iterador apontar para o proximo elemento do vector
        iterator& operator++() {
            m_ptr++;
            return *this;
        }

        // sobrecarga do operador de pos-incremento
        // faz o iterador apontar para o proximo elemento do vector
        // não usamos referencia no parametro pq o aux é uma copia do iterador
        // original, e será destruido ao final da função
        iterator operator++(int) {
            iterator aux = *this;
            m_ptr++;
            return aux;
        }

        // sobrecarga do operador de igualdade
        friend bool operator==(const iterator& it1, const iterator& it2) {
            return it1.m_ptr == it2.m_ptr;
        }

        // sobrecarga do operador de diferença
        friend bool operator!=(const iterator& it1, const iterator& it2) {
            return it1.m_ptr != it2.m_ptr;
        }
    };  // fim da classe interna iterator

    // Funcao que retorna um iterador para o primeiro elemento do vector
    iterator begin() { return iterator(m_vet); }

    // Função que retorna um iterador para o primeiro bit após o último elemento
    // do vector
    iterator end() { return iterator(m_vet + m_size); }

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
    void push_back(const T& val);

    // Funcao que recebe um índice i e retorna
    // o elemento que esta no índice i.
    // Se o indice nao existir na lista, essa funcao
    // vai lancar uma excecao.
    // Complexidade: O(1)
    T& at(unsigned int i);

    // Versao const da funcao at()
    // Complexidade: O(1)
    const T& at(unsigned int i) const;

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
    T& operator[](unsigned int i);

    // versao const do operador[]
    // Complexidade: O(1)
    const T& operator[](unsigned int i) const;

    // Funcao que remove o ultimo elemento da lista, se a lista nao estiver
    // vazia. Se a lista estiver vazia, entao essa funcao nao faz nada. O que
    // essa funcao faz de fato eh apenas decrementar o atributo m_size.
    // Complexidade: O(1)
    void pop_back();

    // sobrecarga do operador de atribuicao
    // essa funcao possibilita atribuir um vector a outro e fazer uma copia
    // automatica
    Vector& operator=(const Vector& v);

    // Compara vectors e retorna 'true' se, e somente se, eles forem identicos.
    // Dois vectors sao identicos se, e somente se, eles tem o mesmo numero de
    // elementos e se os elementos correspondentes tem o mesmo valor.
    bool operator==(const Vector& v);
};

template <typename T>
bool Vector<T>::operator==(const Vector& v) {
    if (m_size != v.m_size) {
        return false;
    }
    for (unsigned int i{0}; i < m_size; ++i) {
        if (m_vet[i] != v.m_vet[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& v) {
    if (this != &v) {  // aqui tambem fucionaria: if(m_vet != v.m_vet)
        m_size = v.m_size;
        m_capacity = v.m_capacity;
        delete[] m_vet;
        m_vet = new T[m_capacity];
        for (unsigned int i{0}; i < m_size; ++i) {
            m_vet[i] = v.m_vet[i];
        }
    }
    return *this;
}

// ----------------------------------------------------------
// Implementacao das funcoes-membro da classe Vector
// ----------------------------------------------------------
template <typename T>
Vector<T>::Vector(unsigned int cap) : m_size{0}, m_capacity{cap} {
    m_vet = new T[m_capacity];
}

template <typename T>
Vector<T>::Vector(const Vector& v) {
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_vet = new T[m_capacity];
    for (unsigned int i = 0; i < m_size; ++i) {
        m_vet[i] = v.m_vet[i];
    }
}

template <typename T>
void Vector<T>::reserve(unsigned int newCap) {
    if (m_capacity < newCap) {
        m_capacity = newCap;
        T* aux = new T[m_capacity];
        for (unsigned int i = 0; i < m_size; ++i) {
            aux[i] = m_vet[i];
        }
        delete[] m_vet;
        m_vet = aux;
    }
}

template <typename T>
void Vector<T>::push_back(const T& val) {
    if (m_size == m_capacity) {  // aumenta de precisar
        reserve(2 * (m_capacity + 1));
    }
    m_vet[m_size] = val;  // insere
    m_size++;             // incrementa m_size
}

template <typename T>
T& Vector<T>::at(unsigned int i) {
    if (i < m_size) {
        return m_vet[i];
    } else {
        throw std::out_of_range("erro no indice");
    }
}

template <typename T>
const T& Vector<T>::at(unsigned int i) const {
    if (i < m_size) {
        return m_vet[i];
    } else {
        throw std::out_of_range("erro no indice");
    }
}

template <typename T>
Vector<T>::~Vector() {
    delete[] m_vet;
}

template <typename T>
unsigned int Vector<T>::size() const {
    return m_size;
}

template <typename T>
unsigned int Vector<T>::capacity() const {
    return m_capacity;
}

template <typename T>
bool Vector<T>::empty() const {
    return m_size == 0;
}

template <typename T>
T& Vector<T>::operator[](unsigned int i) {
    return m_vet[i];
}

template <typename T>
const T& Vector<T>::operator[](unsigned int i) const {
    return m_vet[i];
}

template <typename T>
void Vector<T>::pop_back() {
    if (m_size > 0) {
        m_size--;
    }
}

#endif  // VECTOR_H