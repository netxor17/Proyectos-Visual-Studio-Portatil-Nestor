
// ED Junio 2023. Grupo A
// Ejercicio 2

//****************************************************
//
// IMPORTANTE
//
// Nombre y apellidos
// Usuario del juez usado en esta prueba
//
//**************************************************** 


#include <iostream>
#include <fstream>
#include <iomanip>   

#include "bintree_eda.h"

using namespace std;

struct tPremios {

    int botin = 0;
    int vida = 1;
};

tPremios aventura(bintree <int> const& a) {
    if (a.empty()) {
        return { 0, 1 };
    }
    else {
        tPremios izq = aventura(a.left());
        tPremios der = aventura(a.right());
        tPremios total;
        total.botin = max(izq.botin, der.botin);
        if (der.botin == izq.botin) {
            total.vida = min(izq.vida,der.vida);
        }
        else{
            if (total.botin == izq.botin) {
                total.vida = izq.vida;
            }
            else {
                total.vida = der.vida;
            }
        }
        int valor = a.root();
        if (valor == 1) {
             if (total.vida != 1) {
                 total.vida--;
             }
        }
        else if (valor < 0) {
            int resta = abs(valor);
            total.vida+= resta;
        }
        else {
            total.botin += valor;
        }
        return total;
    }
}


// Aqui funci�n recursiva que resuelve el problema



void resuelveCaso() {
    // Lectura de los datos del �rbol
    auto arbol = leerArbol(0);
    tPremios premio;
    premio = aventura(arbol);
    cout << premio.botin << " " << premio.vida << endl;

    // LLamar a la funci�n que resuelve el problema y escribir el resultado

}


int main() {

#ifndef DOMJUDGE
    std::ifstream in("caso2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
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

