// Nestor Marin Gomez.....
// A80 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdint>


#include "Polinomio.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int exponente, coeficiente;

    cin >> coeficiente >> exponente ;

    if (!cin)
        return false;

    Polinomio p;

    while (!(coeficiente == 0 && exponente == 0)) {
        p.anadirMonomio( coeficiente, exponente);
        cin >> coeficiente >> exponente;
    }

    int nValores, valor;
    cin >> nValores;

    for (int i = 0; i < nValores; ++i) {
        cin >> valor;
        cout << p.evaluarPolinomio(valor) << " " ;
    }
    cout << "\n";


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
