
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
int resuelve(const vector<int>& v, const vector<int>& v2, int ini, int fin) {
    //caso base
    if (ini == fin) {
        return v2[ini];
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] == v2[mitad]) { //si son iguales, lo he metido a la derecha
            return resuelve(v, v2, mitad+1, fin);
        }
        else {
            return resuelve(v, v2, ini, mitad);
        }
    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n==-1)
        return false;
    vector<int> v(n);
    vector<int> v2(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < v2.size(); i++) {
        cin >> v2[i];
    }
    // resolver el caso posiblemente llamando a otras funciones
    int sol = resuelve(v,v2, 0, v2.size() - 1);

    cout << sol << endl;
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej2Enero2021.txt");
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
