
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


int sumaDigitos(int n) {
    //caso base
    if (n < 10) {
        return n;
    }
    else {
        int digito = n % 10;
        return sumaDigitos(n / 10) + digito;
    }

}
// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void resuelveCaso() {
    int tam,n;
    cin >> tam;
    cin >> n;
    int sol1 = sumaDigitos(n);
    vector <int> v(tam);
    for (int i = 0; i < tam; i++) {
        cin >> v[i];
        int sol2 = sumaDigitos(v[i]);
        if (sol1 == sol2) cout << v[i] << " ";
    }
    cout << endl;

    // leer los datos de la entrada
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("sumaDigitos.txt");
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
