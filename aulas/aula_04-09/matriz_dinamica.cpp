#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Digite o tamanho da matriz quadrada: ";
    cin >> n;

    // criando uma matriz dinâmica;
    int **mat = new int *[n];
    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[n];
    }

    // lendo a matriz;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    // imprimindo a matriz
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // deletando a matriz
    for (int i = 0; i < n; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}