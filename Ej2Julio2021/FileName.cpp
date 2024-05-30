//******************************************************
// IMPORTANTE
// NOMBRE Y APELLIDOS DEL ALUMNO:
// USUARIO DEL JUEZ DE ESTE EXAMEN:
// LABORATORIO Y PUESTO:
//******************************************************

// Explicación de la solución y justificación del coste de tu algoritmo.













#include <iostream> 
#include <fstream> 
#include "double_linked_list_ed.h"

template <typename T>
class lista_ext : public double_linked_list_ed<T> {
    using Nodo = typename double_linked_list_ed<T>::Nodo;
public:
    void print(std::ostream& o = std::cout) const {
        if (!this->empty()) {// la lista no esta vacia
            Nodo* aux = this->fantasma->sig;
            o << aux->elem;
            aux = aux->sig;
            while (aux != this->fantasma) {
                o << ' ' << aux->elem;
                aux = aux->sig;
            }
        }
    }

    void desparizar(lista_ext<T>& aux) {
        Nodo* act = this->fantasma->sig;
        Nodo* auxiliar = nullptr;
        Nodo* actSegunda = aux.fantasma->sig;

        while (act != this->fantasma) {//mientras no llegue al final
            if(act->elem %2 == 0){ // si es par el elemento
                auxiliar = act; //guardo referencia al actual
                act->ant-> sig = act->sig; //actualizo
                act->sig->ant = act->ant; //actualizo
                act = act->sig; //aumento el actual
                auxiliar->sig = actSegunda->sig; //referencio
                actSegunda->sig = auxiliar; //referencio a la nueva lista
                auxiliar->ant = actSegunda; //

                actSegunda = actSegunda->sig; //aumento
            }
            act = act->sig; //avanzo el actual de la primera lista
        }
    }

};


void resuelveCaso() {
    // Lectura de los datos de entrada
    lista_ext<int> l;
    lista_ext<int> aux;
    int n; std::cin >> n;
    while (n != 0) {
        l.push_back(n);
        std::cin >> n;
    }
    std::cin >> n;
    while (n != 0) {
        aux.push_back(n);
        std::cin >> n;
    }
    // LLamada a la funcion que resuelve el problema
    l.desparizar(aux);
    // Escribir los resultados
    l.print();
    std::cout << '\n';
    aux.print();
    std::cout << '\n';
}


int main() {

#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos = 1;   std::cin >> numCasos; std::cin.ignore();

    for (int i = 0; i < numCasos; ++i) resuelveCaso();


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

