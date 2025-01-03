
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

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
