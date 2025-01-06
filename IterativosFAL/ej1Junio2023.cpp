
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


long long int contarSegmentosConsecutivos(const vector<int>& v) {
    long long int longitudSegmento = 1;  // Longitud del segmento actual
    long long int segmentos = 0;         // N�mero total de segmentos

    for (int i = 1; i < v.size(); ++i) {
        if (abs(v[i] - v[i - 1]) == 1) {
            // Incrementa la longitud del segmento si es consecutivo
            longitudSegmento++;
        }
        else {
            // Si no es consecutivo, calcula los segmentos v�lidos del segmento actual
            if (longitudSegmento >= 2) {
                segmentos += (longitudSegmento * (longitudSegmento - 1)) / 2;
            }
            // Reinicia la longitud del segmento
            longitudSegmento = 1;
        }
    }

    // Considerar el �ltimo segmento
    if (longitudSegmento >= 2) {
        segmentos += (longitudSegmento * (longitudSegmento - 1)) / 2;
    }

    return segmentos;
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
