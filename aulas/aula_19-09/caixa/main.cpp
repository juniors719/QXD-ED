#include <iostream>
using namespace std;
#include "box.h"

int main() {
    // Box caixa(3.4, 5.6, 7.8);
    // cout << caixa.volume() << endl;
    Box b;
    cout << b.volume() << endl;
    b.setHeight(2);
    b.setLenght(3);
    b.setWidth(4);
    cout << b.volume() << endl;
}
