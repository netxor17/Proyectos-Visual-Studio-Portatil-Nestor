// Nestor Marin Gomez  
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
            cout <<" " << act->elem;
            act = act->sig;
        }
        cout << "\n";
    }

    void intercambiarElementos() {
        Nodo* act = this->fantasma->sig;
        Nodo* next = act->sig;
        if (this->empty() || next == this->fantasma) return;//lista vacia o un elemento
        while (act != this->fantasma) {
            Nodo* aux = next->sig;
            //primero desenganchar el nodo act
            act->ant->sig = act->sig;
            act->sig->ant = act->ant;
            act->sig = next->sig;
            act->ant = next;
            next->sig = act;
            act->ant = next;
            p = aux;
            q = au->sig;
        }
    }
};//fin clase

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    double_linked_list_ed_Nestor<int> lista;
    int nElems;
    cin >> nElems;
    if (nElems == 0) return false;
    for (int i = 0; i < nElems; ++i) {
        int n;
        cin >> n;
        lista.push_back(n);
    }

    lista.intercambiarElementos();
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