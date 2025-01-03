
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

long long int resolver(const vector<int>& v, const int& l) {
    int n = v.size();
    long long countSubsegments = 0; // Contador de subsegmentos v�lidos.
    int length = 1; // Longitud actual del segmento de elementos iguales.

    for (int i = 1; i < n; ++i) {
        if (v[i] == v[i - 1]) {
            ++length; // Incrementar la longitud del segmento actual.
        }
        else {
            // Calcular subsegmentos v�lidos para el segmento actual.
            if (length >= l) {
                int validSegments = length - l + 1;
                countSubsegments += (long long)(validSegments * (validSegments + 1)) / 2;
            }
            length = 1; // Reiniciar la longitud del segmento.
        }
    }

    // Procesar el �ltimo segmento.
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

    // escribir la soluci�n
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
