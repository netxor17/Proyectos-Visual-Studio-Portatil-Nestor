// Nestor Marin Gomez  
//A80


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "linked_list_ed.h"
#include "Fecha.h"

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

    void borrarUnoDeCadaDos() {
        Nodo* act = this->prim;
        Nodo* ult = this->ult;
        while (act != nullptr && act != ult) {
            Nodo* a_borrar = act->sig;
            act->sig = a_borrar->sig;
            act = act->sig;
            delete a_borrar;
        }
    }
};//fin clase

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    linked_list_ed_Nestor<Fecha> lista;
    unsigned int h, m, s;
    char aux;
    int nElems;
    cin >> nElems;
    if (nElems == 0) return false;
    for (int i = 0; i < nElems; ++i) {
        std::cin >> h >> aux >> m >> aux >> s;
        Fecha hora(h, m, s);
        lista.push_back(hora);
    }

    lista.borrarUnoDeCadaDos();
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