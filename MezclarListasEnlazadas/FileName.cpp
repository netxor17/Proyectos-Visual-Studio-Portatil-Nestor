// Nestor Marin Gomez  
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

   void mezclaOrdenada(linked_list_ed_Nestor <int>& l) {
        Nodo* act1 = this->prim;
        Nodo* act2 = l.prim;
        Nodo* act3 = nullptr;

        while (act1 != nullptr && act2 != nullptr) {
            if (act1->elem < act2->elem) {
                act3 = act1;
                act1 = act1->sig;
            }
            else {
                if (act3 == nullptr) {
                    this->prim = act2;
                    l.prim = act2->sig;
                    act2->sig = act1;
                    act3 = act2;
                    act2 = l.prim;
                }
                else {
                    act3->sig = act2;
                    l.prim = act2->sig;
                    act2->sig = act1;
                    act3 = act2;
                    act2 = l.prim;
                }
            }
        }
        if (act2 != nullptr) {
            if (this->empty()) {//lista1 vacia, uso la segunda lista
                this->prim = l.prim; 
                this->ult = l.ult;
            }
            else {//si no esta vacia
                this->ult->sig = l.prim;//anado la segunda lista, lo que quede
                this->ult = l.ult;//el ultimo es el ultimo de la segunda
            }
        }
        l.prim = nullptr;
        l.ult = nullptr;
   }

};//fin clase

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    linked_list_ed_Nestor<int> lista1;
    linked_list_ed_Nestor<int> lista2;
    int e;
    cin >> e;
    while (e != 0) {
        lista1.push_back(e);
        cin >> e;
    }

    cin >> e;
    while (e != 0) {
        lista2.push_back(e);
        cin >> e;
    }

    lista1.mezclaOrdenada(lista2);
    lista1.mostrarContenido();

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