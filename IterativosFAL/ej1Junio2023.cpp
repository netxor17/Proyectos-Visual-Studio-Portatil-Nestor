
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
                // Si el segmento tiene al menos 2 elementos, contamos los subsegmentos v�lidos
                nSegmentos += (longitudSegmento - 1);
            }
            // Reiniciar la longitud del segmento
            longitudSegmento = 1;
        }
    }

    // Verificar el �ltimo segmento
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

    // escribir la soluci�n
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
