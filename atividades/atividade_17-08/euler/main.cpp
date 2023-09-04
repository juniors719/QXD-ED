#include <iostream>
#include <iomanip>
using namespace std;

double fatorial(int n){
    if(n <= 1) return 1;
    else return n * fatorial(n-1);
}

double euler(int n){
    if(n == 0) return 1;
    else return (1/fatorial(n)) + euler(n-1);
}

int main(){
    int n; cin >> n;
    cout << fixed << setprecision(6) << euler(n) << endl;
}