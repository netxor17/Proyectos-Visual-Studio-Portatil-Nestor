
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.


 @ </answer> */

struct tSol{
    int sumaIzq;
    bool interesante;
};


tSol resuelve(int n, int sumaDch) {
    if (n % 10 == 0)
        return { -1,false };
    else if (n < 10)
        return { n,sumaDch % n == 0 };
    else {
        int ultDigito = n % 10;
        tSol sol = resuelve(n / 10, sumaDch + ultDigito);
        bool interesante = sol.interesante && (sol.sumaIzq % ultDigito == 0) && (sumaDch % ultDigito == 0);
        return { sol.sumaIzq + ultDigito,interesante };
    }
}
 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

void resuelveCaso() {
    int numero;
    cin >> numero;
    tSol sol;
    sol = resuelve(numero, 0);
    // leer los datos de la entrada
    if (sol.interesante) cout << "SI\n";
    else cout << "NO\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("numerosInteresantes.txt");
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
