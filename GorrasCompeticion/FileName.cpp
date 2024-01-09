
/*@ <answer>
 *
 * Nombre y Apellidos:Nestor Marin Gomez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Equipo {
    int seguidores;

    bool operator<(const Equipo& e) const {
        return seguidores < e.seguidores; //quien tenga menos seguidores
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<Equipo> v(n);//vector de equipos

    PriorityQueue<Equipo> cola;//cola de prioridad de equipos

    for (int i = 0; i < n; i++) {
        cin >> v[i].seguidores;
        cola.push(v[i]);//añado a la cola
    }

    int contGorras=0;
    
    while (cola.size() > 1) {//mientras haya dos equipos en la cola

        Equipo equipo1 = cola.top();
        cola.pop();
        Equipo equipo2 = cola.top();
        cola.pop();

        contGorras += equipo1.seguidores + equipo2.seguidores;//importante el += porque hay que comprar cada vez mas

        Equipo equipoResultante;
        equipoResultante.seguidores = equipo1.seguidores + equipo2.seguidores;//actualizo el equipo vencedor
           
        cola.push(equipoResultante);//lo añado a la cola
    }

    cout << contGorras << "\n";
    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
