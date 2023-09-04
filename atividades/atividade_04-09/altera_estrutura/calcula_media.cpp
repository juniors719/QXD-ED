/**
 * @file calcula_media.cpp
 * @author Júnior Silva (junior.silva@alu.ufc.br)
 * @brief
 * @version 0.1
 * @date 04-09-2023
 *
 *
 */

#include <iomanip>   // std::setprecision
#include <iostream>  // std::cout, std::fixed

struct aluno {
    float nota[3];
    float media;
};

// Recebe um aluno passado por referência, e preenche o campo 'media' com a
// média das 3 notas do aluno.
void calcula_media(aluno *a) {
    float media = ((a->nota[0] + a->nota[1] + a->nota[2]) / 3);
    a->media = media;
}

int main() {
    aluno a;
    for (int i = 0; i < 3; i++) std::cin >> a.nota[i];

    // Chame a função 'calcula_media' passando o aluno 'a' por referência.
    calcula_media(&a);

    std::cout << std::fixed;
    std::cout << std::setprecision(1) << a.media;

    return 0;
}