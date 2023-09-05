#include <iostream>
using namespace std;

int somatorio(int n) {
    if (n == 1) return 1;
    return n + somatorio(n - 1);
}

long fatorial(long n) {
    if (n == 0) return 1;
    return n * fatorial(n - 1);
}

long expo(long a, long b) {
    if (b == 0) return 1;
    return a * expo(a, b - 1);
}

bool ehPalindromo(string a) {
    int lenght = a.size();
    if (lenght == 0 | lenght == 1)
        return true;
    else if (a[0] != a[lenght - 1])
        return false;
    else
        return ehPalindromo(a.substr(1, lenght));
}

int main() {
    int n;
    cin >> n;
    cout << somatorio(n) << endl;
    cout << fatorial(n) << endl;
    cout << expo(3, 4) << endl;
    if (ehPalindromo("rcadar")) {
        cout << "eh palindromo" << endl;
    } else
        cout << "n eh palindromo" << endl;
}