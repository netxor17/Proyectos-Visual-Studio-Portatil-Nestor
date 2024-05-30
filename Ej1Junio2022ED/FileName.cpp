//******************************************************
// IMPORTANTE
// NOMBRE Y APELLIDOS DEL ALUMNO:
// USUARIO DEL JUEZ DE ESTE EXAMEN:
// LABORATORIO Y PUESTO:
//******************************************************

// Explicación de la solución y justificación del coste de tu algoritmo.




#include <iostream>
#include <fstream>
#include <cmath>
#include "bintree_eda.h"

using namespace std;



// Aqui el código del alumno
// Puedes definir las funciones auxiliares que necesites


pair<int,int> caminoPares2(bintree<int> const& a) {
    if (a.empty()) {
        return { 0,0 };
    }
    else {
        pair<int, int> izq = caminoPares2(a.left());
        pair<int, int> der = caminoPares2(a.right());
        //veo la rama con mas pares
        int masPares = max(izq.first, izq.first);
        //ahora veo los pares actuales de la rama
        int paresAct = izq.first + der.first;

        if (a.root() % 2 == 0) {
            masPares++;
            paresAct++;
        }

        return { masPares, max({izq.second,der.second,paresAct}) };
    }
}

int caminoPares(bintree<int> const& a) {
    int max = 0;
    pair<int,int> sol = caminoPares2(a);
    return sol.first;
}


// No modificar el código a partir de aqui.
// Entrada y salida de datos
void resuelveCaso() {
    bintree<int> a = leerArbol(-1);
    std::cout << caminoPares(a) << '\n';
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos = 1;   std::cin >> numCasos; std::cin.ignore();
    for (int i = 0; i < numCasos; ++i) resuelveCaso();


#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
