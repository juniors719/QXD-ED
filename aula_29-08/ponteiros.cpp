#include <iostream>
using namespace std;

// void imprimir_vetor(int a, int vet[]) {
void imprimir_vetor(int a, int *vet) {
    for (size_t i = 0; i < a; i++)
    {
        cout << vet[i] << endl;
    }
    
}

int main(){

    // tipo de dado * nome_do_ponteiro
    // é o operador * que informa ao compilador que a variável nome_do_ponteiro vai guardar um endereço de memória
    
    // Exemplo:
    // int *p_int;
    // double * p_d;
    // int* p_intt;

    int x {20}; // declarando uma variável x
    int* ptr {&x}; // declarando ponteiro com o endereço da variável x

    cout << x << endl;
    cout << &x << endl;
    cout << ptr << endl;
    cout << *ptr << endl; // usando o operador *, conseguimos enviar o valor que está sendo referenciado pelo endereço de memória que o ponteiro aponta

    cout << sizeof(ptr) << endl;

    int* ptr2 {nullptr}; // declarando valor nulo ao ponteiro, para evitar lixo -> operador: nullptr

    *ptr = 50; // guardando valor na variável x, através de ptr

    cout << *ptr << endl;


    // ARRAYS E PONTEIROS

    int array[5] = {9, 7, 5, 3, 1};

    cout << "Endereço de array[0]: " << &array[0] << endl;
    cout << array << endl; // todo array decai para um ponteiro para o endereço de memória do primeiro valor do array (pos 0);

    imprimir_vetor(5, array);

    return 0;
}