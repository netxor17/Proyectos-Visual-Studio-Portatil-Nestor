// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

using namespace std;


template <typename Valor>
class ARM_Kruskal {
private:
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    int maxAuto;
    int min;
    int numConexas;
public:
    Valor costeARM() const {
        return this->coste;
    }

    int minimo() const {
        return maxAuto;
    }

    int nConexas() const{
        return this->numConexas;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a);
                min = a.valor();
                coste += a.valor();
                maxAuto = max(maxAuto, min);
                if (_ARM.size() == g.V() - 1) break;
            }
        }
        numConexas = cjtos.num_cjtos();
    }
};



// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nCiudades, nCarreteras;
    cin >> nCiudades;
    if (!std::cin)
        return false;
    cin >> nCarreteras;

    GrafoValorado<int> g(nCiudades);
    int ini, dest, valor;
    for (int i = 0; i < nCarreteras; i++) {
        cin >> ini;
        cin >> dest;
        cin >> valor;
        g.ponArista({ ini -1 ,dest -1,valor });
    }

    ARM_Kruskal<int> kruskal(g);
    if (kruskal.nConexas() > 1) cout << "Imposible\n";
    else cout<< kruskal.minimo() << endl ;
    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("autonomiaCoches.txt");
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