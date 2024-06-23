// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

#include "DigrafoValorado.h"
#include "IndexPQ.h"

using namespace std;
template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig, int tesoro) : origen(orig), tesoro(tesoro),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }

    int minimoRespiracion() const {
        return respiracion;
    }

    Valor distancia(int v) const { return dist[v];}

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    int respiracion;
    int tesoro;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); 
            ulti[w] = a;
            if (a.valor() > respiracion) respiracion = a.valor();
            if (tesoro != w) {
                respiracion = 0;
            }
            pq.update(w, dist[w]);
        }
    }
};



// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    cin >> n;
    if (!std::cin)
        return false;
    cin >> m;

    DigrafoValorado<int> digrafo(n);
    int ini, dest, valor;
    for (int i = 0; i < m; i++) {
        cin >> ini;
        cin >> dest;
        cin >> valor;
        digrafo.ponArista({ ini - 1 ,dest - 1,valor });
        digrafo.ponArista({dest - 1, ini -1 ,valor });
    }
    int palencia, tesoro;
    cin >> palencia >> tesoro;
    Dijkstra<int> sol(digrafo, palencia -1 , tesoro-1);

    if (sol.hayCamino(tesoro - 1) == 0) cout << "IMPOSIBLE\n";
    else cout << sol.minimoRespiracion() << endl ;
    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("minasEmperador.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}