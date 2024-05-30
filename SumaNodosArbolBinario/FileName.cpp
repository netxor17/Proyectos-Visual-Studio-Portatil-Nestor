// Nestor Marin Gomez
// A80

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "bintree_eda.h"


template <class T>
class bintree_ext : public bintree <T> {
    using Link = typename bintree <T>::Link;
public:
    bintree_ext() : bintree <T>() {}
    bintree_ext(bintree_ext <T> const& l, T const& e, bintree_ext <T> const& r) :
        bintree <T>(l, e, r) {}
    int suma() {
        return sumaNodos(this->raiz);
    }

private:
    int sumaNodos(Link r) {
        if (r == nullptr) {
            return 0;
        }
        else {
            int izq = sumaNodos(r->left);
            int der = sumaNodos(r->right);

            return izq + der + r->elem;
        }
    }
};


template <typename T>
inline bintree_ext<T> leerArbol_ext(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un arbol vacio
        return {};
    }
    else { // leer recursivamente los hijos
        bintree_ext<T> iz = leerArbol_ext(vacio);
        bintree_ext<T> dr = leerArbol_ext(vacio);
        return { iz, raiz, dr };
    }
}

template <class T>
int suma2(bintree<T> const& arbol) {
    return resolver(arbol);
}

// función que resuelve el problema
template <class T>
int  resolver(bintree<T> const& arbol) { //numAcum, suma
    if (arbol.empty()) {
        return 0;
    }
    else {
        int izq = resolver(arbol.left());
        int der = resolver(arbol.right());
        return izq + der + arbol.root();
    }
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    int sol1 = suma2(arbol);
    //bintree_ext<int> extendido = leerArbol_ext(-1);
    //int sol = extendido.suma();
    cout << sol1 << "\n";

    // escribir sol
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}