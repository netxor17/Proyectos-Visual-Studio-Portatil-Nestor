//******************************************************
// IMPORTANTE
// NOMBRE Y APELLIDOS DEL ALUMNO:
// USUARIO DEL JUEZ DE ESTE EXAMEN:
// LABORATORIO Y PUESTO:
//******************************************************

// Explicación de la solución y justificación del coste de tu algoritmo.














#include <iostream>
#include <fstream> 
#include "bintree_eda.h"
using namespace std;

// Aqui el código del alumno
// Puedes definir las funciones auxiliares que necesites

pair<bintree<int>, int> calcular_arbol_acum(bintree<)

bintree<int> acumula(bintree<int> arbol) {
    return calcular_arbol_acum(arbol).first;

}

void resuelve() {
    // Leer los datos
    auto arbol = leerArbol(-1);
    // LLamada a la función que resuelve el problema
    auto aux = acumula(arbol);
    // Escribir los resultados
    auto sol = aux.preorder();
    if (!sol.empty()) {
        std::cout << sol[0];
        for (int i = 1; i < sol.size(); ++i)
            std::cout << ' ' << sol[i];
    }
    std::cout << '\n';
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("casos2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos = 1;   std::cin >> numCasos; std::cin.ignore();
    for (int i = 0; i < numCasos; ++i) resuelve();

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
