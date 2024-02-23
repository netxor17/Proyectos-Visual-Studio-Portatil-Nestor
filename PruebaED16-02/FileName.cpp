﻿// Nestor Marin Gomez  
//A80


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "double_linked_list_ed.h"


using namespace std;

template <typename T>
class double_linked_list_ed_Nestor : public double_linked_list_ed<T> {
    using Nodo = typename double_linked_list_ed<T>::Nodo;
public:
    //anado los dos metodos que se piden
    void mostrarContenido() const {
        Nodo* act = this->fantasma->sig;
        if (act != this->fantasma) {
            cout << act->elem;
            act = act->sig;
        }
        while (act != this->fantasma) {
            cout << " " << act->elem ;
            act = act->sig;
        }
        cout << "\n";
    }

    void particion(int pivote) {
        Nodo* act = this->fantasma->sig;
        Nodo* primer_derecha = nullptr;
        Nodo* aux = nullptr;
        if (this->empty() || act->sig == this->fantasma) return;//lista vacia o un elemento
        while (act != this->fantasma && act != primer_derecha) {
            if (act->elem <= pivote) {
                act = act->sig;//avanzo
            }
            else {
                if (primer_derecha == nullptr) {//todavia no apunta a nada
                    primer_derecha = act;//primer elemento mayor que el pivote
                }
                aux = act->sig;
                act->ant->sig = act->sig;
                act->sig->ant = act->ant;
                act->ant = this->fantasma->ant;
                act->sig = this->fantasma;

                this->fantasma->ant->sig = act;
                this->fantasma->ant = act;

                act = aux;
            }
        }
    }
};//fin clase

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    double_linked_list_ed_Nestor<int> lista;
    int nElems, pivote;
    cin >> nElems;
    if (!cin) return false;
    cin >> pivote;
    for (int i = 0; i < nElems; ++i) {
        int n;
        cin >> n;
        lista.push_back(n);
    }

    lista.particion(pivote);
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