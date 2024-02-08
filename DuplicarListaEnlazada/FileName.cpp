﻿// Nestor Marin Gomez  
//A80


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "linked_list_ed.h"

using namespace std;

template <typename T>
class linked_list_ed_Nestor : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;
public:
    //anado los dos metodos que se piden
    void mostrarContenido() const {
        Nodo* aux = this->prim;
        while (aux != nullptr) {
            cout << aux->elem << " ";
            aux = aux->sig;
        }
        cout << "\n";
    }

    void duplicaLista() {
        Nodo* aux = this->prim;
        while (aux != nullptr) {
            Nodo* nuevo = new Nodo(aux->elem);
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
            aux = nuevo->sig;
        }
    }
};//fin clase

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    linked_list_ed_Nestor<int> lista;
    int dato;
    cin >> dato;
    if (!std::cin)
        return false;
    while (dato != 0) {
        lista.push_back(dato);
        cin >> dato;
    }

    lista.duplicaLista();
    lista.mostrarContenido();

    // escribir sol


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