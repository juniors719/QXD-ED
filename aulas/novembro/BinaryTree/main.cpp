#include <iostream>

#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree<int> t7("8 3 1 # # 6 4 # # 7 # # 10 # 14 13 # # #");

    t7.preOrder();
    cout << endl;

    cout << t7.contains(9) << endl;
    cout << "Size = " << t7.size() << endl;
    cout << "Serial = " << t7.serial() << endl;
}