/**
 * NAO MEXA NESSE ARQUIVO, ELE JA ESTA FINALIZADO
 */
#include <iostream>
#include <sstream>
#include <string>

#include "Vector.h"
using namespace std;

int main() {
    Vector myvec;

    while (true) {
        string line;
        string comando;

        getline(cin, line);
        stringstream ss{line};
        ss >> comando;

        if (comando == "exit") {
            cout << "$exit\n";
            return 0;
        }
        // front
        else if (comando == "front") {
            cout << "$front\n";
            cout << myvec.front() << '\n';
            const Vector cvec(myvec);
            cout << "front of const copy vector: " << cvec.front() << '\n';
        }
        // back
        else if (comando == "back") {
            cout << "$back\n";
            cout << myvec.back() << '\n';
            const Vector cvec(myvec);
            cout << "back of const copy vector: " << cvec.back() << '\n';
        }
        // removeall [v]
        // remove todos os elementos com valor v
        else if (comando == "removeall") {
            int v;
            ss >> v;
            cout << "$removeall " << v << '\n';
            myvec.remove_all(v);
        }
        // insertat [v] [k]
        // insere o elemento v no indice k
        else if (comando == "insertat") {
            int v, k;
            ss >> v;
            ss >> k;
            cout << "$insertat " << v << " " << k << '\n';
            try {
                myvec.insert_at(v, k);
            } catch (const std::out_of_range& e) {
                cout << "fail: " << e.what() << '\n';
            }
        }
        // removeat [v]
        // remove o elemento no indice k
        else if (comando == "removeat") {
            int k;
            ss >> k;
            cout << "$removeat " << k << '\n';
            try {
                myvec.remove_at(k);
            } catch (const std::out_of_range& e) {
                cout << "fail: " << e.what() << '\n';
            }
        }
        // pushback v1 v2 ... vk
        else if (comando == "pushback") {
            int v;
            cout << "$pushback ";
            while (ss >> v) {
                cout << v << " ";
                myvec.push_back(v);
            }
            cout << "\n";
        }
        // print
        else if (comando == "print") {
            cout << "$print\n";
            for (size_t i{}; i < myvec.size(); ++i) {
                cout << myvec[i] << " ";
            }
            cout << endl;
        }
        // size
        else if (comando == "size") {
            cout << "$size\n";
            cout << myvec.size() << endl;
        } else {
            cout << "comando inexistente" << endl;
        }
    }
    return 0;
}