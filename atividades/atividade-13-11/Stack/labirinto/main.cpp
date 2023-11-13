#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Pos {
    int l;
    int c;
};

// retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p) {
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

void resolve(vector<string>& mat, Pos inicio, Pos fim) {
    stack<Pos> pilha;
    pilha.push(inicio);

    while (!pilha.empty()) {
        Pos topo = pilha.top();
        pilha.pop();

        if (topo.l == fim.l && topo.c == fim.c) return;

        vector<Pos> vizinhosNaoVisitados;
        for (Pos vizinho : get_vizinhos(topo)) {
            if (mat[vizinho.l][vizinho.c] == ' ') {
                mat[vizinho.l][vizinho.c] = '.';
                vizinhosNaoVisitados.push_back(vizinho);
            }
        }

        if (vizinhosNaoVisitados.empty()) {
            pilha.pop();
        }

        for (Pos vizinho : vizinhosNaoVisitados) {
            pilha.push(vizinho);
        }
    }
}

int main() {
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, "");  // começa com nl strings ""
    getchar();                   // remove \n after nc
    Pos inicio, fim;

    // carregando matriz
    for (int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    // procurando inicio e fim e colocando ' ' nas posições iniciais
    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++) {
            if (mat[l][c] == 'I') {
                mat[l][c] = ' ';
                inicio = Pos{l, c};
            }
            if (mat[l][c] == 'F') {
                mat[l][c] = ' ';
                fim = Pos{l, c};
            }
        }
    }

    resolve(mat, inicio, fim);

    for (string line : mat)
        cout << line << endl;
    /* cout << "       nl=" << nl << " nc=" << nc << "\n";
    cout << "inicio: l=" << inicio.l << " , c=" << inicio.c << endl;
    cout << "   fim: l=" << fim.l << " , c=" << fim.c << endl; */
}