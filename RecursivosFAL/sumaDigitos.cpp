
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
// Escribe el c�digo completo de tu soluci�n aqu� debajo
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

    // escribir la soluci�n
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
