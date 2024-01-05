
/*@ <answer>
 *
 * Nombre y Apellidos: Nestor Marin Gomez DA42
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"

using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

template <typename Valor>
class ARM_Kruskal {//uso kruskal para ver el arbol de recubrimiento minimo
private:
	std::vector<Arista<Valor>> _ARM;
	Valor coste;
	int nConexas;//para saber si no puedo llegar a un pueblo
public:
	Valor costeARM() const { return coste; }
	std::vector<Arista<Valor>> const& ARM() const { return _ARM; }

	int numConexas() const {
		return this->nConexas;
	}

	ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), nConexas(0) {
		PriorityQueue<Arista<Valor>> pq(g.aristas()); //O(A) siendo A el num de aristas.
		ConjuntosDisjuntos cjtos(g.V()); //O(V) siendo v el numero de vertices del grafo
		while (!pq.empty()) {
			auto a = pq.top();
			pq.pop(); //O(logA)
			int v = a.uno(), w = a.otro(v); //O(1)
			if (!cjtos.unidos(v, w)) { //O(lg ^* V)
				cjtos.unir(v, w);
				_ARM.push_back(a); //cte
				coste += a.valor();//valor de la arista es el coste
				if (_ARM.size() == g.V() - 1) break;
			}
		}
		nConexas = (cjtos.num_cjtos()); //cte
	}
};

bool resuelveCaso() {

    // leer los datos de la entrada
	int vertices,aristas;
	cin >> vertices;
    if (!std::cin)  // fin de la entrada
        return false;
	cin >> aristas;

	GrafoValorado<int> g(vertices);//Grafo valorado que representa la ciudad

	for (int i= 0; i < aristas; ++i) {
		int c1, c2, coste;
		cin >> c1 >> c2 >> coste;
		Arista<int> a(c1-1, c2-1, coste);
		g.ponArista(a);
	}
    // resolver el caso posiblemente llamando a otras funciones

	ARM_Kruskal<int> kruskal(g); //arm del grafo

	if (kruskal.numConexas() > 1) cout << "Imposible\n";
	else cout << kruskal.costeARM() << "\n";

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
