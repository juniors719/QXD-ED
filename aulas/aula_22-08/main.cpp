#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {

    /* string s1 = "ana";
    string s2 = "ANA";
    if(s1<s2) cout << s1;
    else cout << s2; */



    /* std::istringstream inputstream;
    inputstream.str("123.456.789-10");

    int x;
    char w;
    int z;
    inputstream >> x;
    inputstream >> w;
    inputstream >> z;

    cout << x << endl << z; */

    istringstream iss;
    float soma, numero;
    string leitura;
    getline(cin, leitura);
    iss.str(leitura);
    while(iss >> numero) soma += numero;
    cout << soma << endl;

    for(int i = 0; i < 5; i++) {
        soma = 0;
        getline(cin, leitura);
        iss.str(leitura);
        while(iss >> numero) soma += numero;
        cout << soma << endl;
        iss.clear();
    }


    
}