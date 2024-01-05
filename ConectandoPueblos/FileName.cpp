
/*@ <answer>
 *
 * Nombre y Apellidos: Néstor Marin Gomez DA42
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"


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
	int numConexas;//para saber si no puedo llegar a un pueblo
public:
	Valor costeARM() const { return coste; }
	std::vector<Arista<Valor>> const& ARM() const { return _ARM; }
	
	int numConexass() const {
		return this->numConexas;
	}

	ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), numConexas(0) {
		PriorityQueue<Arista<Valor>> pq(g.aristas()); //O(A) siendo A el num de aristas.
		ConjuntosDisjuntos cjtos(g.V()); //O(V) siendo v el numero de vertices del grafo
		while (!pq.empty()) {
			auto a = pq.top();
			pq.pop(); //O(logA)
			int v = a.uno(), w = a.otro(v); //O(1)
			if (!cjtos.unidos(v, w)) { //O(lg ^* V)
				cjtos.unir(v, w);
				_ARM.push_back(a); //cte
				coste = a.valor();//valor de la arista es el coste
				if (_ARM.size() == g.V() - 1) break;
			}
		}
		numConexas = (cjtos.num_cjtos()); //cte
	}
};

void resuelveCaso() {

    // leer los datos de la entrada
    int nPueblos, nCarreteras;
    cin >> nPueblos >> nCarreteras;

    GrafoValorado<int> g(nPueblos); //creo el grafo de nPueblos vertices

    for (int i = 0; i < nCarreteras; ++i) {
        int horas, pueblo1, pueblo2;
        cin >> pueblo1 >> pueblo2 >> horas;
        Arista<int> a(pueblo1-1, pueblo2-1, horas);//creo una arista valorada
		g.ponArista(a); //la pongo
    }   
	ARM_Kruskal<int> k(g);//arbol de recubrimiento minimo
	if (k.numConexass() > 1) cout << "Imposible\n";
	else cout << k.costeARM() << "\n";

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
