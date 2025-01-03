
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

long long int resolver(const vector<int>& v, const int& l) {
    int n = v.size();
    long long countSubsegments = 0; // Contador de subsegmentos válidos.
    int length = 1; // Longitud actual del segmento de elementos iguales.

    for (int i = 1; i < n; ++i) {
        if (v[i] == v[i - 1]) {
            ++length; // Incrementar la longitud del segmento actual.
        }
        else {
            // Calcular subsegmentos válidos para el segmento actual.
            if (length >= l) {
                int validSegments = length - l + 1;
                countSubsegments += (long long)(validSegments * (validSegments + 1)) / 2;
            }
            length = 1; // Reiniciar la longitud del segmento.
        }
    }

    // Procesar el último segmento.
    if (length >= l) {
        int validSegments = length - l + 1;
        countSubsegments += (long long)(validSegments * (validSegments + 1)) / 2;
    }

    return countSubsegments;
}


void resuelveCaso() {

    // leer los datos de la entrada
    int tamVector, l;
    cin >> l;
    cin >> tamVector;

    vector<int> v(tamVector);

    for (int i = 0; i < tamVector; i++) {
        cin >> v[i];
    }

   cout << resolver(v, l) <<endl;

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej1Enero2024.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
