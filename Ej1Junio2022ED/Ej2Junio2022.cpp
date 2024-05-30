
// Función que elimina de una lista los valores repetidos
// en tiempo lineal

#include <iostream>
#include <algorithm>
#include <list> 
#include <unordered_set> 
#include <fstream>

using namespace std;

// La función recorre la lista con un iterador. 
// Utiliza un conjunto no ordenado para guardar los valores
// y poder comprobar en tiempo constante si un elemento
// ya está incluido en la lista
template <typename T>
void eliminar_repetidos(std::list<T>& l) {
    std::unordered_set<T> conj;
    auto it = l.begin(); // inicializa el iterador al principio de la lista
    while (it != l.end()) {
        if (conj.count(*it) == 0) { // el elemento no pertenece al conjunto
            conj.insert(*it); // se anade al conjunto
            ++it; // Se pasa al siguiente en la lista, ya que es la primera vez que aparece el valor
        }
        else {// está repetido
            it = l.erase(it); // Se elimina y se pasa al siguiente
        }
    }
}

bool resuelveCaso() {
    char tipo; std::cin >> tipo;
    if (!std::cin) return false;
    int numElem; std::cin >> numElem;
    if (tipo == 'N') { // tipo entero
        std::list<int> l;
        // leer los datos
        for (int i = 0; i < numElem; ++i) {
            int aux; std::cin >> aux;
            l.push_back(aux);
        }
        // LLamada a la funcion
        eliminar_repetidos(l);
        // Escribir el resultado
        auto it = l.begin();
        if (it != l.end()) {
            std::cout << *it;
            ++it;
        }
        while (it != l.end()) {
            std::cout << ' ' << *it;
            ++it;
        }
        std::cout << '\n';
    }
    else { // tipo string
        std::list<std::string> l;
        // Leer los datos
        for (int i = 0; i < numElem; ++i) {
            std::string aux; std::cin >> aux;
            l.push_back(aux);
        }
        // LLamada a la funcion
        eliminar_repetidos(l);
        // Escribir el resultado
        auto it = l.begin();
        if (it != l.end()) {
            std::cout << *it;
            ++it;
        }
        while (it != l.end()) {
            std::cout << ' ' << *it;
            ++it;
        }
        std::cout << '\n';
    }

    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif  

    while (resuelveCaso());

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}