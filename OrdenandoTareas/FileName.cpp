#include <iostream>
#include <fstream>
#include "Digrafo.h"
#include <deque>
#include <vector>

using namespace std;

class OrdenTopologicoSinCiclos {

public:

    OrdenTopologicoSinCiclos(Digrafo const& g) : visit(g.V(), false),
        apilado(g.V(), false), hayciclo(false) {
        for (int v = 0; v < g.V(); ++v) {
            if (!visit[v])
                dfs(g, v);
            if (getHayCiclo()) return;
        }
    }

    // devuelve la ordenación topológica
    std::deque<int> const& orden() const {
        return _orden;
    }

    bool getHayCiclo() const { return hayciclo; }


private:

    std::vector<bool> visit; // visit[v] = ¿se ha alcanzado a v en el dfs?
    std::vector<bool> apilado; // apilado[v] = ¿está el vértice v en la pila?
    std::deque<int> _orden; // ordenación topológica
    bool hayciclo;

    void dfs(Digrafo const& g, int v) {
        visit[v] = true;
        apilado[v] = true;

        for (int w : g.ady(v)) {
            if (hayciclo) // si hemos encontrado un ciclo terminamos
                return;
            if (!visit[w]) { // encontrado un nuevo vértice, seguimos
                dfs(g, w);
            }
            else if (apilado[w]) { // hemos detectado un ciclo
                hayciclo = true;
                return;  // Salimos inmediatamente al detectar un ciclo
            }
        }

        apilado[v] = false;
        _orden.push_front(v);
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int n, m;
    cin >> n >> m;

    if (!std::cin)  // fin de la entrada
        return false;

    Digrafo digrafo(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        digrafo.ponArista(a - 1, b - 1);
    }

    OrdenTopologicoSinCiclos ordenacionTopologica(digrafo);

    if (ordenacionTopologica.getHayCiclo()) cout << "Imposible\n";
    else {
        deque<int> orden = ordenacionTopologica.orden();
        while (!orden.empty()) {
            cout << orden.front() + 1 << " ";
            orden.pop_front();
        }
        cout << "\n";
    }

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
