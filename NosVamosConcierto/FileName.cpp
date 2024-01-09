
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
using namespace std;

/*@ <answer>

 Recursion:
    Casos base:
        -Siguiente festival si no puedes ir al actual
        -0 si no quedan festivales
    Caso recursivos:
        resultado = max(ir al actual, no ir)

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Festival
{
    int grupos;
    int precio;
};

int resolver(int festivales, int presupuesto, const vector <Festival>& v) {

    Matriz<int> m(festivales + 1, presupuesto + 1, -1);//matriz de soluciones
    //Casoss base
    for (int i = 0; i <= festivales; i++) {
        m[i][0] = 0;
    }

    for (int j = 1; j <= presupuesto; j++) {
        m[0][j] = 0;
    }

    //Caso recursivo
    for (int i = 1; i <= festivales; i++) {
        for (int j = 1; j <= presupuesto; j++) {
            if (v[i - 1].precio > presupuesto) {
                m[i][j] = m[i - 1][j];
            }
            else {
                //no asistir al festival i y mantener la sol para el festival i-1
                //o asistir al festival y restar el precio de ese festival del presupuesto
                m[i][j] = max(m[i - 1][j], m[i - 1][j - v[i - 1].precio] + v[i - 1].grupos);
            }
        }

    }

    return m[festivales][presupuesto];
}



bool resuelveCaso() {

    // leer los datos de la entrada
    int presupuesto, nFestivales;
    cin >> presupuesto >> nFestivales;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<Festival> v(nFestivales);

    int nGrupos, precioEntrada;
    for (int i = 0; i < nFestivales; i++) {
        cin >> nGrupos >> precioEntrada;
        v[i] = { nGrupos, precioEntrada };
    }

    int sol = resolver(nFestivales, presupuesto, v);

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