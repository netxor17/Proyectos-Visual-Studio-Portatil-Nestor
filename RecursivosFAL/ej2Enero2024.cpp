
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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
int resolver(const vector<int>& v, int ini, int fin) {
    if (ini == fin) {//un elemento
        return 0;
    }
    else if (ini + 1 == fin) {
        return (v[fin] - v[ini]);
    }
    else {
        int mitad = (ini + fin) / 2;
        int izq = resolver(v, ini, mitad);
        int der = resolver(v, mitad, fin);
        return max(izq,der);
    }
}



void resuelveCaso() {

    // leer los datos de la entrada
    int tam;
    cin >> tam;
    vector<int> v(tam);
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < tam; i++) {
        cin >> v[i];
    }
    // escribir la solución
    int sol = resolver(v, 0, v.size() - 1);
    cout << sol << endl;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej2Enero2024.txt");
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
