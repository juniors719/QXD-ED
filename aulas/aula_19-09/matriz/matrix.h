#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

class Matrix {
   private:
    int nLinhas;
    int mColunas;
    int** matrix;

   public:
    // construtor
    Matrix(int nLinhas, int mColunas) {
        this->nLinhas = nLinhas;
        this->mColunas = mColunas;
        matrix = new int*[nLinhas];
        for (int i = 0; i < nLinhas; i++) {
            matrix[i] = new int[mColunas];
        }
    }

    // destrutor
    ~Matrix() {
        for (int i = 0; i < nLinhas; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        std::cout << "matriz deletada\n";
    }

    int getValue(int i, int j) { return matrix[i][j]; }
    void setValue(int i, int j, int value) { matrix[i][j] = value; }
    int get_n_linhas() { return nLinhas; }
    int get_n_colunas() { return mColunas; }
    void imprimeMatrix() {
        for (int l = 0; l < nLinhas; l++) {
            for (int c = 0; c < mColunas; c++) {
                std::cout << matrix[l][c];
                if (c < mColunas - 1) std::cout << " ";
            }
            std::cout << "\n";
        }
    }
    bool comparaMatrix(Matrix& otherMatrix) {
        if (nLinhas != otherMatrix.get_n_linhas() ||
            mColunas != otherMatrix.get_n_colunas()) {
            return false;
        }
        for (int l = 0; l < nLinhas; l++) {
            for (int c = 0; c < mColunas; c++) {
                if (matrix[l][c] != otherMatrix.getValue(l, c)) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif