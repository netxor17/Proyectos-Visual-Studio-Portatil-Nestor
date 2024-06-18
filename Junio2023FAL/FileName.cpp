// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<int> &v) {
    int longAct = 1;
    int a = 1;
    int b = 1;
    int contSegmentos = 0;
    if (v.size() > 1) {
        while (b < v.size()) {
            if (v[a] + 1 == v[a - 1] || v[a] - 1 == v[a - 1]) {
                longAct++;
                if (longAct >= 2) {
                    contSegmentos++;
                }
                if (a < v.size() -1) {
                    a++;
                }
                else {
                    longAct = 1;
                    b++;
                    a = b;
                }
            }
            else {
                longAct = 1;
                b++;
                a = b;
            }
        }
    }
    else {
        contSegmentos =  0;
    }
    return contSegmentos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nElems;
    cin >> nElems;
    vector<int> v(nElems);

    for (int i = 0; i < nElems; i++) {
        cin >> v[i];
    }
    int sol = resolver(v);
    // escribir sol
    cout << sol << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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