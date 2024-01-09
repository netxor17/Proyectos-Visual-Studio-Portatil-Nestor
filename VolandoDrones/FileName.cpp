
/*@ <answer>
 *
 * Nombre y Apellidos: Nestor Marin Gomez
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

struct tPila {//struct para cola de prioridad
    int horasDisponibles;
    bool operator<(const tPila otra) const {//cuanto mayor autonomia mejor
        return horasDisponibles > otra.horasDisponibles;//ajusto la prioridad
    }
};

int resuelve(int nDrones, PriorityQueue<tPila>& cajaPilasGrandes, PriorityQueue<tPila>& cajaPilasPeques) {
    int contHoras = 0;
    int dronesConCarga = 0;

    PriorityQueue<tPila> pGrande, pPequena;//auxiliares para rellenar las cajas 

    while (dronesConCarga < nDrones && !cajaPilasGrandes.empty() && !cajaPilasPeques.empty()) { //inicializo los drones
        tPila a = cajaPilasGrandes.top();//recojo la mas cargada de las grandes
        cajaPilasGrandes.pop();
        tPila b = cajaPilasPeques.top(); //recojo la mas cargada de las pequenas
        cajaPilasPeques.pop();

        int horasDisponibles = min(a.horasDisponibles, b.horasDisponibles); //solo puede volar el minimo de horas de las dos baterias
       //resto horas de vuelo a las pilas
        pGrande.push({ a.horasDisponibles - horasDisponibles });
        pPequena.push({ b.horasDisponibles - horasDisponibles });

        contHoras += horasDisponibles;//actualizo
        dronesConCarga++;//aumento contador
    }


    //cuando ya se han gastado todos los drones
    //guardamos las pilas que aun no se han gastado
    while (!pPequena.empty() && pPequena.top().horasDisponibles > 0) {//actualizo la cola de prioridad pequena
        cajaPilasPeques.push(pPequena.top());
        pPequena.pop();
    }
    //actualizo la caja grande tambien
    while (!pGrande.empty() && pGrande.top().horasDisponibles > 0) {//actualizo la cola de prioridad grande
        cajaPilasGrandes.push(pGrande.top());
        pGrande.pop();
    }

    return contHoras;
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int nDrones, nPilasGrandes, nPilasPequenas, nHorasGrande, nHorasPequena;

    cin >> nDrones;
    if (!std::cin)  // fin de la entrada
        return false;

    cin >> nPilasGrandes >> nPilasPequenas;

    int valor;

    PriorityQueue<tPila> cajaPilasGrandes;//cola de prioridad caja grande

    PriorityQueue<tPila> cajaPilasPeques;//cola de prioridad caja pequeña

    for (int i = 0; i < nPilasGrandes; i++) {
        cin >> valor;
        cajaPilasGrandes.push({valor});
    }

    for (int i = 0; i < nPilasPequenas; i++) {
        cin >> valor;
        cajaPilasPeques.push({ valor });
    }
        
    //mientras haya horas de vuelo disponibles
    while ((valor = resuelve(nDrones, cajaPilasGrandes, cajaPilasPeques)) > 0) {
        cout << valor << " ";
    }
   // cout << resuelve(nDrones, pilasGrandes, pilasPeques);

    cout << "\n";

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
