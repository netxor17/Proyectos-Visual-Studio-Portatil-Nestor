
/*@ <answer>
 *
 * Nombre y Apellidos: Javier Parra Gonzalez y Nestor Marin Gomez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "IndexPQ.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 La solucion que hemos utilizado es modificar la clase IndexPq para que pueda recibir un tipo generico, para ello hemos decidido cambiar el template
	y hemos modificado el vector de posiciones, lo hemos hecho de tipo unordered_map para poder meter una clave string y un valor entero.
	Tambien hemos modificado varias funciones para tratar el caso de recibir un tipo generico.

Para los casos de entrada hemos leido las lineas:
	Para el evento C hemos usado la funcion nueva update2 para actualizar la prioridad.
	Para el evento TC hemos visto si podiamos mostrar un elemento, lo hemos guardado, lo hemos mostrado y despues lo hemos sacado para poder ver el siguiente.
	Luego hemos vuelto a colocar los que hemos sacado.
	Para el evento E solamente hemos actualizado con prioridad negativa.


En cuanto al coste, la funcion que resuelve el problema llama tantas veces como lineas hay. Segun el evento llama a una funcion.
	En el caso del evento C, llama a update2 que tiene un coste logaritmico de N, siendo N el numero de elementos ya que la funcion flotar tiene coste O(log N).
	En el caso de TC, el coste depende del numero de veces que se ejecute, en el caso peor N. O(N)
	En el caso del evento E, el coste es del O(log N) siendo N el numero de elementos.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int numLineas; cin >> numLineas;
    string tipo;
    string tema;
    int numCitas;

    if (!std::cin)  // fin de la entrada
        return false;


    IndexPQ<string, pair<int, int>, greater<pair<int, int>>> pq;

    for (int i = 0; i < numLineas; i++) {

        cin >> tipo;
        if (tipo == "C") {
            cin >> tema >> numCitas;
            pq.update2(tema, make_pair(numCitas, i));
        }
        else if (tipo == "TC") {
            if (pq.size() > 0) {
                string elem = pq.top().elem;
                pair<int, int> p = pq.top().prioridad;

                pq.pop();
                cout << "1 " << elem << "\n";

                if (pq.size() > 0) {
                    string elem = pq.top().elem;
                    pair<int, int> p = pq.top().prioridad;

                    pq.pop();
                    cout << "2 " << elem << "\n";
                    if (pq.size() > 0) {
                        string elem = pq.top().elem;
                        pair<int, int> p = pq.top().prioridad;
                        pq.pop();
                        cout << "3 " << elem << "\n";

                        pq.push(elem, p);
                    }

                    pq.push(elem, p);

                }
                pq.push(elem, p);


            }


        }

        else if (tipo == "E") {


            cin >> tema >> numCitas;
            pq.update2(tema, make_pair(numCitas * (-1), i));
        }

    }
    cout << "---" << "\n";



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
