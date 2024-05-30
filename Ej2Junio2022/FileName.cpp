// ****  IMPORTANTE  ******

// Nombre y apellidos del estudiante

// Usuario del juez de examen

//*************************************


#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

// Explicación del algoritmo empleado




// Coste de la solución. Para justificar el coste se debe escribir la recurrencia que permite calcularlo.



struct tSol {
    int numBarcos=0;
    int tesorosRestantes=0;
    int capacidad = 0;
};


// Aqui la/las función/funciones que resuelven el problema

tSol resolver(const bintree<int>& a, int n) {
    if (a.empty()) {
        return { 0, 0 };
    }
    else {
        tSol izq = resolver(a.left(), n);
        tSol der = resolver(a.right(), n);
        int barcosTotales = izq.numBarcos + der.numBarcos;
        int tesorosTotales = izq.capacidad + der.capacidad;
        if (a.root() < tesorosTotales) {
            return { barcosTotales, tesorosTotales - a.root()};
        }
        else {
            tSol izq = resolver(a.left(), n);
            tSol dcha = resolver(a.right(), n);
            int barcostotales = izq.numBarcos + dcha.numBarcos;
            int tesoros = izq.tesorosRestantes + dcha.tesorosRestantes;
            if (tesoros >= a.root()) {
                return { barcostotales,tesoros - a.root() };
            }
            else {
                int numero = a.root();
                numero -= tesoros;
                barcostotales++;
                while (numero > n) {
                    numero -= n;
                    barcostotales++;
                }
                return{ barcostotales,n - numero };
            }
        }
    }
}



// Resuelve cada caso de entrada
void resuelveCaso() {
    // Lectura de los datos
    auto arbol = leerArbol(-1);
    int n; std::cin >> n;

    // Aqui la llamada a la función que resuelve el problema
    tSol solucion = resolver(arbol, n);
    cout << solucion.numBarcos << " " << solucion.tesorosRestantes <<endl;

    // Aqui escribir los resultados de la llamada a la función
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("casos2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to sample2.txt
#endif

    int numCasos = 1;  std::cin >> numCasos; std::cin.ignore();
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
