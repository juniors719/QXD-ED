#include <iostream>

#include "Vector.h"
using namespace std;

int main() {
    Vector<string> vec1, vec2, vec3, vec4;

    vec1.push_back("ana");
    vec1.push_back("marcos");
    vec4.push_back("Sebastiao");

    vec3 = vec2 = vec1;

    cout << "Elementos do vec1: ";
    for (unsigned int i{0}; i < vec1.size(); ++i) {
        cout << vec1[i] << " ";
    }
    cout << endl;
    cout << "Elementos do vec3: ";
    for (unsigned int i{0}; i < vec3.size(); ++i) {
        cout << vec3[i] << " ";
    }
    cout << endl;
    cout << "Elementos do vec4: ";
    for (unsigned int i{0}; i < vec4.size(); ++i) {
        cout << vec4[i] << " ";
    }
    cout << endl;

    if (vec1 == vec3) {
        cout << "vec1 e vec3 sao iguais" << endl;
    } else {
        cout << "vec1 e vec3 sao diferentes" << endl;
    }

    if (vec1 == vec4) {
        cout << "vec1 e vec4 sao iguais" << endl;
    } else {
        cout << "vec1 e vec4 sao diferentes" << endl;
    }
}