// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

// función que resuelve el problema
int resolver( const vector<int> &v, PriorityQueue<int> &p) {
    int suma = 0;
    int acum = 0;
    while (p.size() > 1) {
        int a = p.top();
        p.pop();
        int b = p.top();
        p.pop();
        suma += a + b;
        p.push(a+b);//pongo otra vez en la cola de prioridad el elemento resultante de la suma
    }
    return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nElems;
    cin >> nElems;
    if (nElems ==0)
        return false;
    PriorityQueue<int> p;
    vector<int> v(nElems);
    for (int i = 0; i < nElems; i++) {
        cin >> v[i];
        p.push(v[i]);
    }
    int sol = resolver(v,p);

    // escribir sol
    cout << sol << endl;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("cuestaSumar.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
