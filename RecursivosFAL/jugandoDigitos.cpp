
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


int resuelve(int n) {
    //caso base
    if (n < 10) {
        if (n % 2 == 0) return n + 1;
        else return n - 1;
    }
    else {
        int digito;
        if (n % 2 == 0) digito = n % 10 + 1;
        else digito = n % 10 - 1;
        return resuelve(n / 10) * 10 + digito;
    }
    
}
// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

void resuelveCaso() {
    int numero;
    cin >> numero;
    int sol = resuelve(numero);
    // leer los datos de la entrada
    cout << sol << endl;
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("jugandoDigitos.txt");
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
