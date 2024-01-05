
/*@ <answer>
 *
 * Nombre y Apellidos: N�stor Marin Gomez DA42
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
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

struct Comic {
    int id;//identificador del comic
    int pila;//pila en donde se encuentra
};

bool operator<(const Comic& c1, const Comic& c2) {
    return c1.id < c2.id;//para saber cual es mejor comic (menor es mejor)
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int nPilas, kComics;
    cin >> nPilas;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<stack<int>> pilas;//vector de pilas

    // resolver el caso posiblemente llamando a otras funciones
    int idMinimo = 1000000;//inicializo el mejor id a un monton

    for (int i = 0; i < nPilas; ++i) {
        cin >> kComics;//numero de elementos de la pila
        stack<int> pila;//para hacer una pila

        for (int i = 0; i < kComics; ++i) {
            int e;
            cin >> e;//leo el elemento
            idMinimo = min(idMinimo, e);//para saber cual es el minimo elemento a buscar mas tarde
            pila.push(e);//a�ado el elemento a la pila
        }
        pilas.push_back(pila);//a�ado la pila al vector de pilas
    }
        PriorityQueue<Comic> comics;//cola de prioridad de pair<int,int>

        int cont = 1;//para saber cuantas personas han cogido ya un comic

        //a�ado a la cola de prioridad los comics de la cima de ambas pilas
        for (int i = 0; i < nPilas; i++) {
            comics.push({ pilas[i].top(),i}); 
        }

        //ahora voy a buscar el comic con idMinimo
        while (comics.top().id != idMinimo) {//si no es el minimo de todos los comics(el mejor)
            Comic mejorComicActual = comics.top();//veo el mejor comic actual
            comics.pop();//saco de la cola de prioridad
            pilas[mejorComicActual.pila].pop();//lo saco de la pila

            if (!pilas[mejorComicActual.pila].empty()) {//si quedan comics en la pila
                comics.push({ pilas[mejorComicActual.pila].top(),mejorComicActual.pila });//lo a�ado a la cola de prioridad
            }
            cont++;//aumento el contador de personas que han cogido comic
        }

        cout << cont << "\n";
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
