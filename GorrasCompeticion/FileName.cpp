
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
        cola.push(v[i]);//a�ado a la cola
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
           
        cola.push(equipoResultante);//lo a�ado a la cola
    }

    cout << contGorras << "\n";
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
