
/*@ <answer>
 *
 * Nombre y Apellidos:Nestor Marin Gomez DA42
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue .h"


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

struct Actividad {
    int inicio, fin;
    bool operator<(const Actividad &otra) const {
        return inicio < otra.inicio;//si empieza antes, es mejor
    }
};

struct Companero {
    int final;
    bool operator<(const Companero & otro) const{
        return final < otro.final; 
    }
};

int resuelve(PriorityQueue<Actividad>& a)  {
    PriorityQueue<Companero> compas;//cola de prioridad de compañeros
    int cont = 0;//contador de compañeros necesarios
    while (!a.empty()) {//hay actividades
        Actividad act = a.top();//cojo la cima
        a.pop();//la saco
        if (compas.empty() || compas.top().final > act.inicio) {//si no hay compi disponible
            cont++;//necesito otro
        }
        else {
            compas.pop();//lo saco de la charla donde este
        }
        compas.push({ act.fin });//lo meto en la actividad
    }
    return cont - 1;//me tengo que quitar a mi mismo
}



bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    PriorityQueue<Actividad> actividades;

    for (int i = 0; i < n; i++) {
        int ini, fin;
        cin >> ini >> fin;
        actividades.push({ ini,fin });
    }

    cout << resuelve(actividades) << "\n";
    // resolver el caso posiblemente llamando a otras funciones

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
