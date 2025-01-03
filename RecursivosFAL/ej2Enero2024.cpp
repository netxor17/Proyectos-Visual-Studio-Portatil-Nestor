
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
    // escribir la soluci�n
    int sol = resolver(v, 0, v.size() - 1);
    cout << sol << endl;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
