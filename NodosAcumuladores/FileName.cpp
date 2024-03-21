// Nestor Marin Gomez
// A80


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "bintree_eda.h"


template <class T >
class bintree_ext : public bintree <T > {
    using Link = typename bintree <T >::Link;
public:
    bintree_ext() : bintree <T >() {}
    bintree_ext(bintree_ext <T > const& l, T const& e, bintree_ext <T > const& r) :
        bintree <T >(l, e, r) {}
    int acum() const {
        return acumNodos(this->raiz).first;
    }
private:
    pair<int, int> acumNodos(Link r) const {
        if (r == nullptr) {
            return { 0,0 };
        }
        else {
            //numAcum, suma
            pair<int, int> izq = acumNodos(r->left);
            pair<int, int> der = acumNodos(r->right);
            int nAcums = izq.first + der.first;
            if (izq.second + der.second == r->elem) {
                return { nAcums + 1, izq.second + der.second + r->elem };
            }
            else {
                return { nAcums , izq.second + der.second + r->elem };
            }
        }
    }
};


template <typename T >
inline bintree_ext <T > leerArbol_ext(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un arbol vacio
        return {};
    }
    else { // leer recursivamente los hijos
        bintree_ext <T > iz = leerArbol_ext(vacio);
        bintree_ext <T > dr = leerArbol_ext(vacio);
        return { iz , raiz , dr };
    }
}

template <class T>

int resuelve(bintree<T> const& arbol) {
    return resolver(arbol).first;
}

// función que resuelve el problema
pair<int, int>  resolver(bintree<int> const& arbol)  { //numAcum, suma
    if (arbol.empty()) {
        return { 0,0 };
    }
    else {
        //numAcum, suma
        pair<int, int> izq = resolver(arbol.left());
        pair<int, int> der = resolver(arbol.right());
        int nAcums = izq.first + der.first;
        if (izq.second + der.second == arbol.root()) {
            return { nAcums + 1, izq.second + der.second + arbol.root() };
        }
        else {
            return { nAcums , izq.second + der.second + arbol.root() };
        }
    }
};



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
   // bintree<int> arbol = leerArbol(-1);
   // int sol = resuelve(arbol);
    bintree_ext<int> extendido = leerArbol_ext(-1);
    int sol = extendido.acum();
    cout << sol << "\n";

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