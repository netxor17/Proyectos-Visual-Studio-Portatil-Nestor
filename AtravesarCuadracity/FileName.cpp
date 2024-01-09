//Nestor Marin Gomez
//Ejercicio atravesar Cuadracity

#include <iostream>
#include <vector>
#include <fstream>


#include "Matriz.h"

using namespace std;


int contarFormas(const Matriz<char>& m) {
    int nFilas, nCols;
    nFilas = m.numfils();
    nCols = m.numcols();

    Matriz<int> sol(nFilas, nCols, 0);

    // Casos base
    // Para la primera columna (de arriba a abajo)
    for (int i = 0; i < nFilas; i++) {
        if (m[i][0] != 'X') {
            sol[i][0] = 1;
        }
        else {
            break;  // Si hay un obstáculo, no hay más formas de llegar a posiciones en esta columna
        }
    }

    // Para la primera fila (de izda a dcha)
    for (int j = 0; j < nCols; j++) {
        if (m[0][j] != 'X') {
            sol[0][j] = 1;
        }
        else {
            break;  // Si hay un obstáculo, no hay más formas de llegar a posiciones en esta fila
        }
    }

    // Caso recursivo
    for (int i = 1; i < nFilas; i++) {
        for (int j = 1; j < nCols; j++) {
            if (m[i][j] != 'X') {//si no hay obstaculo, lo calculo
                sol[i][j] = sol[i - 1][j] + sol[i][j - 1];
            }
            else {//si hay obstaculo es 0 las maneras de llegar
                sol[i][j] = 0;
            }
        }
    }
    return sol[nFilas - 1][nCols - 1];
}

//Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta.
bool resuelveCaso() {

    int N, M;

    cin >> N;

    if (!std::cin) return false;

    cin >> M;

    Matriz<char> m(N, M, '.');

    char c;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;
            if (c == 'X') m[i][j] = 'X';
        }
    }

    cout << contarFormas(m) << "\n";
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}