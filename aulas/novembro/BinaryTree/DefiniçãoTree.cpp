// ÁRVORE

// Filho: nó que tem um nó pai.

// Pai: nó que tem um nó filho.

// Nó folha: nó que não tem filhos.

// Ancestrais: todos os nós no caminho da raiz até o nó.

// Descendentes: todos os nós que estão no caminho do nó até as folhas.

// Profundidade: número de nós entre a raiz e o nó.

// Nível: Dizemos que todos os nós com profundidade igual a k formam o nível k.

// Altura: Número de nós no maior caminho da raiz até uma folha. Toda folha tem
// altura 1.

// -----------------------------------------------------------------------------

// ÁRVORE BINÁRIA: árvore em que cada nó tem no máximo dois filhos.

// Árvore estritamente binária: todo nó possui 0 ou 2 filhos.

// Árvore completa: possui a propriedade de que, se r é um nó tal que alguma

// subárvore de r é vazia, então r se localiza no penúltimo ou último nível da
// árvore.

// Árvore cheia: todos os nós internos possuem dois filhos e todas as folhas
// estão no último nível.

// -----------------------------------------------------------------------------

// Qual o número mínimo de nós em uma árvore binária de altura h?
// Resposta: h

// Qual o número máximo de nós em uma árvore binária de altura h?
// Resposta: 2^h - 1

// Se a árvore binária tem n >= 1 nós, então:
// a altura é no mínimo log2(n+1) (Árvore completa) e no máximo n.