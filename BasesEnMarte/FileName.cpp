
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Bateria {
    int final;
    int id;
    int vidaUtil;

    bool operator<(const Bateria& otra) const {
        return final < otra.final || (final == otra.final && id < otra.id);
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int b;
    cin >> b;
    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<Bateria> baterias;//cola de prioridad de baterias

    int id = 1, t;
    for (int i = 0; i < b; i++, id++) {
        cin >> t;
        baterias.push({ t,id,t });//añado a la cola de prioridad
    }

    int r;
    cin >> r;

    PriorityQueue<Bateria> batReserva;//cola de prioridad de baterias de reserva

    int duracion;
    for (int i = 0; i < r; i++, id++) {
        cin >> duracion;
        batReserva.push({ 0,id,duracion });
    }

    int z, T;
    cin >> z >> T;

    while (!baterias.empty() && baterias.top().final <= T) {//mientras haya baterias 
        Bateria bateriaActual = baterias.top();//cojo el mas prioritario
        baterias.pop();//la elimino

        bateriaActual.vidaUtil -= z;//resto la vida util

        if (bateriaActual.vidaUtil <= 0) {//si aun tiene carga
            if (!batReserva.empty()) {//si quedan baterias de reserva
                Bateria nuevaBat = batReserva.top();//cojo el mas prioritario
                batReserva.pop();//la quito
                nuevaBat.final = bateriaActual.final + nuevaBat.vidaUtil;//actualizo
                baterias.push(nuevaBat);//la añado a las baterias que se usan
            }
        }
        else {
            bateriaActual.final += bateriaActual.vidaUtil;//actualizo
            baterias.push(bateriaActual);
        }
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
     // escribir la solución
    if (baterias.empty()) cout << "ABANDONEN INMEDIATAMENTE LA BASE";
    else if (baterias.size() < b) cout << "FALLO EN EL SISTEMA";
    else cout << "CORRECTO";

    while (!baterias.empty()) {
        cout << "\n" << baterias.top().id << " " << baterias.top().final;
        baterias.pop();
    }

    cout << "\n---\n";
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
