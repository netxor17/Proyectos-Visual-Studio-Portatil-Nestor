
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
    //caso base
    if (ini == fin) { //un elemento
        return (v[ini] % 2 == 0);
    }
    else if (ini + 1 == fin) { //dos elementos
        return (v[ini] % 2 == 0) + (v[fin] % 2 == 0);
    }
    else {
        int mitad = (ini + fin) / 2;
        int izq = resolver(v, ini, mitad);
        int der = resolver(v, mitad+1, fin);
        if ((izq != -1) && (der != -1) && (abs(izq - der) <= 2)) {
            return izq + der;
        }
        else return -1;
    }
}



bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n==0 )
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int sol = resolver(v, 0, v.size()-1);

    if (sol != -1) cout << "SI\n";
    else cout << "NO\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("numerosCaucasicos.txt");
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
