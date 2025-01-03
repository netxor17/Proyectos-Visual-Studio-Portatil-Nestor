
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */

int resolver(int n) {
    if (n < 10) {
        if (n % 2 == 0) return 0;
        else return n;
    }
    else {
        int d;
        if (n % 2 == 0) d = 0;
        else d = n % 10;
        if (d != 0) {
            return resolver(n / 10) * 10 + d;
        }
        else return resolver(n / 10) + d;

    }
}
// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int numero;
    cin >> numero;
    if (!cin)
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    cout << resolver(numero) << endl;
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("eliminarPares.txt");
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
