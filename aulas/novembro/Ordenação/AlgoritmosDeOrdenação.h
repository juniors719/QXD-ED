#ifndef ALGORITMOSDEORDENACAO_H
#define ALGORITMOSDEORDENACAO_H

#include <iostream>

// INSERTION SORT

// O Insertion Sort é um algoritmo de ordenação simples que funciona construindo uma sequência
// ordenada de elementos um de cada vez. Aqui está uma explicação resumida
// de como o Insertion Sort funciona em C++:

// - Início: Começa com o segundo elemento (índice 1) e considera-o como o elemento atual.
// - Comparação e Inserção: Compara o elemento atual com os elementos anteriores na
//      sequência ordenada. Move os elementos maiores para a direita para abrir espaço
//      e insere o elemento atual na posição correta.
// - Repetição: Repete esse processo para cada elemento subsequente até que toda
//      a sequência esteja ordenada.

// O Insertion Sort destaca-se como um algoritmo de ordenação estável, preservando a ordem relativa
// dos elementos iguais durante o processo. Além disso, caracteriza-se como um método de
// ordenação in-place, o que significa que opera diretamente sobre o array de entrada, sem exigir
// espaço adicional para armazenamento temporário.

// Embora seja eficiente para conjuntos de dados pequenos, é importante observar que o
// Insertion Sort possui uma complexidade de tempo quadrática, ou seja, o tempo de execução
// aumenta proporcionalmente ao quadrado do número de elementos na entrada.
// Contudo, sua adaptabilidade o torna uma escolha valiosa em cenários nos quais a
// entrada já se encontra parcialmente ordenada, pois nesses casos, o algoritmo é
// capaz de reduzir significativamente seu tempo de execução.

// Algoritmo in loco

void insertionSort(int *vetor, int tamanho) {
    for (int j = 1; j < tamanho; j++) {     // j = 1, pois o primeiro elemento já está ordenado
        int key = vetor[j];                 // key é o elemento que será inserido na parte ordenada
        int i = j - 1;                      // i é o índice do último elemento da parte ordenada
        while (i >= 0 && vetor[i] > key) {  // enquanto o elemento da parte ordenada for maior que o key
            vetor[i + 1] = vetor[i];        // o elemento da parte ordenada é deslocado para a direita
            i--;                            // i é decrementado
        }                                   // quando o elemento da parte ordenada for menor que o key, o loop é interrompido
        vetor[i + 1] = key;                 // o key é inserido na parte ordenada
    }
}

// #######################################################################################################################

// SELECTION SORT

// O Selection Sort é um algoritmo de ordenação simples que funciona encontrando o menor elemento
// e colocando-o na primeira posição, depois o segundo menor elemento na segunda posição e assim
// sucessivamente. Aqui está uma explicação resumida de como o Selection Sort funciona em C++:

// - Início: Começa com o primeiro elemento (índice 0) e considera-o como o elemento atual.
// - Busca: Percorre o array inteiro para encontrar o menor elemento.
// - Troca: Troca o elemento atual com o menor elemento encontrado.
// - Repetição: Repete esse processo para cada elemento subsequente até que toda
//      a sequência esteja ordenada.

// O Selection Sort destaca-se como um algoritmo de ordenação in-place, o que significa que
// opera diretamente sobre o array de entrada, sem exigir espaço adicional para armazenamento
// temporário. Além disso, caracteriza-se como um método de ordenação instável, pois não
// preserva a ordem relativa dos elementos iguais durante o processo.

// Embora seja eficiente para conjuntos de dados pequenos, é importante observar que o
// Selection Sort possui uma complexidade de tempo quadrática, ou seja, o tempo de execução
// aumenta proporcionalmente ao quadrado do número de elementos na entrada.

// Algoritmo in loco

void selectionSort(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {      // i = 0, pois o primeiro elemento já está ordenado
        int min = i;                             // min é o índice do menor elemento
        for (int j = i + 1; j < tamanho; j++) {  // j = i + 1, pois o elemento i já está ordenado
            if (vetor[j] < vetor[min]) {         // se o elemento j for menor que o elemento min
                min = j;                         // min passa a ser o índice do elemento j
            }
        }
        int aux = vetor[i];     // aux é o elemento que será trocado de posição
        vetor[i] = vetor[min];  // o elemento min é colocado na posição i
        vetor[min] = aux;       // o elemento aux é colocado na posição min
    }
}

// #######################################################################################################################

// QUICK SORT

// O Quick Sort é um algoritmo de ordenação eficiente que funciona dividindo o arrray em dois.
// O Quick Sort aplica o paradigma de divisão e conquista para reduzir o tempo de execução.

// Dividir: rearranja o vetor A[p..r] em dois subvetores (possivelmente vazios) A[p..q-1] e A[q+1..r], tal que
// A[p..q-1] <= A[q] <= A[q+1..r]. O índice é calculado como parte do procedimento de particionamento.

// Como particionar o array:
// - Escolha um elemento do array, chamado de pivô (no nosso caso, o último elemento do array).
// A[0..j-1] são elementos menores ou iguais ao pivô.
// A[j+1..r] são elementos maiores ou iguais ao pivô.
// para algum j tal que p <= j <= r.
// k -> variável que percorre o array
// j -> variável que indica a quebra do array (posição do pivô). Aponta para o primeiro elemento maior que o pivô.
// A[0..j-1] -> elementos menores ou iguais ao pivô
// A[j..k-1] -> elementos maiores ou iguais ao pivô
// A[k..n-2] -> elementos não analisados
// A[n-1] -> pivô
// Caso 1: O elemento k é menor que o pivô. Troca-se os elementos A[j] e A[k] e incrementa-se j e k.
// Caso 2: O elemento k é maior que o pivô. Incrementa-se k.
// Caso 3: O elemento k é igual ao pivô. Incrementa-se k.
// Caso parada: k = n-1. Troca-se os elementos A[j] e A[k] e retorna-se j.

int partition(int A[], int l, int r) {
    int pivo = A[r];               // pivo é o último elemento do array
    int j = l;                     // j é o índice do primeiro elemento do array
    for (int k = l; k < r; ++k) {  // k é o índice do elemento que está sendo analisado
        if (A[k] <= pivo) {        // se o elemento k for menor ou igual ao pivo
            int aux = A[j];        // aux é o elemento que será trocado de posição
            A[k] = A[j];           // o elemento j é colocado na posição k
            A[j] = aux;            // o elemento aux é colocado na posição j
            j++;                   // j é incrementado
        }
    }
    A[r] = A[j];  // o elemento j é colocado na posição r
    A[j] = pivo;  // o elemento pivo é colocado na posição j
    return j;     // retorna o índice do pivô
}

void quickSort(int A[], int l, int r) {
    if (l < r) {                     // se o índice do primeiro elemento for menor que o índice do último elemento
        int j = partition(A, l, r);  // j é o índice do pivô
        quickSort(A, l, j - 1);      // ordena a primeira parte do array
        quickSort(A, j + 1, r);      // ordena a segunda parte do array
    }
}

// DIVIDIR - particionar o array em dois subarrays
// CONQUISTAR - ordenar os subarrays recursivamente
// COMBINAR - não é necessário combinar os subarrays, pois o array já está ordenado

// Caso médio: O(n log n) para permutação aleatória
// Pior caso: O(n^2) - Vetor já ordenado ou vetor ordenado de forma inversa
// Precisa de espaço adicional O(n) para a pilha de recursão

// #######################################################################################################################

#endif  // ALGORITMOSDEORDENACAO_H