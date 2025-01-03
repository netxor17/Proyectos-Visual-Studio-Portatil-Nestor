
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

int contarSegmentosConsecutivos(const vector<int>& v) {
    int n = v.size();
    if (n < 2) return 0;  // No hay segmentos si el vector tiene menos de 2 elementos

    int nSegmentos = 0;
    int longitudSegmento = 1;  // Longitud del segmento consecutivo actual

    // Recorrer el vector y contar segmentos consecutivos
    for (int i = 1; i < n; ++i) {
        if (abs(v[i] - v[i - 1]) == 1) {
            // Si los elementos son consecutivos, incrementamos la longitud del segmento
            longitudSegmento++;
        }
        else {
            // Si los elementos no son consecutivos, verificamos el segmento anterior
            if (longitudSegmento >= 2) {
                // Si el segmento tiene al menos 2 elementos, contamos los subsegmentos válidos
                nSegmentos += (longitudSegmento - 1);
            }
            // Reiniciar la longitud del segmento
            longitudSegmento = 1;
        }
    }

    // Verificar el último segmento
    if (longitudSegmento >= 2) {
        nSegmentos += (longitudSegmento);
    }

    return nSegmentos;
}


void resuelveCaso() {

    // leer los datos de la entrada
    int tamVector;
    cin >> tamVector;

    vector<int> v(tamVector);

    for (int i = 0; i < tamVector; i++) {
        cin >> v[i];
    }

    cout << contarSegmentosConsecutivos(v) << endl;

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej1Junio2023.txt");
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
