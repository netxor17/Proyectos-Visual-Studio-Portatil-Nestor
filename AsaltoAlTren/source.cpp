// Nestor Marin Gomez .....
// A79.....


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*Coste de la solucion
    El primer bucle de la funcion resolver, tiene coste n, siendo n la longitud del intervalo, que en este caso son los vagones a asaltar.
    El segundo bucle de la funcion resolver tiene que dar v.size() - p vueltas, y en cada vuelta se hacen todo operaciones de coste constante. Por lo que
        el bucle tiene coste O(v.size -p) que es equivalente a O(v.size).

    Por lo que el coste en general del algoritmo es O(v.size).


*/

// función que resuelve el problema
pair<int, int>  resolver(const vector<int> &v, int vagonesAsaltar) {
    // Primer intervalo
    int sumaMax = 0; int sumaAct = 0; int posIni;
    for (int i = 0; i < vagonesAsaltar; ++i) {
        sumaAct += v[i];
    }
    sumaMax = sumaAct; posIni = 0;
    // Resto del vector
    for (int i = vagonesAsaltar; i < v.size(); ++i) {
        sumaAct -= v[i - vagonesAsaltar];
        sumaAct += v[i];
        if (sumaAct >= sumaMax) { // El intervalo es mejor
            posIni = i - vagonesAsaltar + 1;
            sumaMax = sumaAct;
        }
    }
    return { posIni, sumaMax };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int nVagones, vagonesAsaltar;
    cin >> nVagones >> vagonesAsaltar;
    vector<int> v(nVagones);
    for (int i = 0; i < nVagones; ++i) {
        cin >> v[i];
    }
    pair<int,int> sol = resolver(v, vagonesAsaltar);

    cout << sol.first << " " << sol.second << " \n";
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}