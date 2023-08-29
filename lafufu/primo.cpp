#include <iostream>

using namespace std;

bool primo(int numero){
    int count=0;
    for(int i = 2; i < numero;i++){
        if(numero % i == 0) return false;
    }
    return true;
}

int main(){
    int A, B;
    cin >> A >> B;
    
    for( int i=A; i<=B; i++){
        if(primo(i)){
            cout << i << '\n';
        }
    }
return 0;
}