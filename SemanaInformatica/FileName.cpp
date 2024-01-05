
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
    PriorityQueue<Companero> compas;//cola de prioridad de compa�eros
    int cont = 0;//contador de compa�eros necesarios
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
