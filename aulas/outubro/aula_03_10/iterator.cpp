/**
 * Formas de sobrecarregar um operador:
 * 1. Implementar operador como função membro da classe
 *
 * 2. Implementar operador como função global.
 * (Obs.: nem todos os operadores podem ser implementados como função global.
 * Ex.: operador=, operador++, operador--, etc.) Exemplos de operadores que só
 * podem ser implementados como função global: operador << , operador >>.
 * O motivo é que esses operadores precisam acessar o objeto que está à esquerda
 * do operador. Ex.: cout << "Hello World!".
 *
 * 3. Implementar operador como função friend da classe.
 * Isso permite que a função acesse os membros privados da classe.
 * Exemplo:
 * friend bool operator==(const Ponto& p1, const Ponto& p2);
 *
 */
