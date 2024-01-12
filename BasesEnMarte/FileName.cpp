
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
        baterias.push({ t,id,t });//a�ado a la cola de prioridad
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

        if (bateriaActual.vidaUtil <= 0) {//si no tiene carga
            if (!batReserva.empty()) {//si quedan baterias de reserva
                Bateria nuevaBat = batReserva.top();//cojo el mas prioritario
                batReserva.pop();//la quito
                nuevaBat.final = bateriaActual.final + nuevaBat.vidaUtil;//actualizo
                baterias.push(nuevaBat);//la a�ado a las baterias que se usan
            }
        }
        else {
            bateriaActual.final += bateriaActual.vidaUtil;//actualizo
            baterias.push(bateriaActual);
        }
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n
     // escribir la soluci�n
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
