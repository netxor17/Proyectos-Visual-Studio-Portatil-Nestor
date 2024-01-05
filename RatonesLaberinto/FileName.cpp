
/*@ <answer>
 *
 * Nombre y Apellidos:Nestor Marin Gomez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "IndexPQ.h"
#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>


template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {
    
    // leer los datos de la entrada
    int n, s, tiempo, p;
    cin >> n >> s >> tiempo >> p;

    if (!std::cin)  // fin de la entrada
        return false;
    DigrafoValorado<int> g(n);

    for (int i = 0; i < p; i++) {
        int p1, p2, coste;
        cin >> p1 >> p2 >> coste;
        AristaDirigida<int> a(p2 - 1, p1 - 1, coste);//creo una arista dirigida, aqui tenia el error!!!!
        g.ponArista(a);
    }
    s--;//ver por que es s--
    Dijkstra<int> d(g,s);
    
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (i != s) {
            if (d.hayCamino(i) && d.distancia(i) <= tiempo) {
                cont++;
            }
        }
    }
    
    cout << cont << "\n";
    return true;

}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
