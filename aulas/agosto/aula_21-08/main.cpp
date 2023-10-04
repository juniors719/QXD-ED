#include <iostream>
#include <limits>
using namespace std;

/**
 * @brief Essa função lê e retorn um inteiro
 * 
 * @return int 
 */
int read_int(){
    int valor{};
    while(true){
        cin >> valor;
        if (cin.fail()) { // houve erro de leitura
            cin.clear(); // reseto os bits de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpo o buffer
            cout << "Entrada inválida. Tente novamente.";
        } else { // não houve falha na leitura
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpo o buffer
            return valor;
        }
    }
}

int main(){
    int x{};
    cout << "Digite um inteiro: ";
    x = read_int();
    cout << "O valor digitado foi: " << x << endl;
}