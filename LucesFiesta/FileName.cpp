
/*@ <answer>
 *
 * Nombre y Apellidos:Nestor Marin Gomez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

//numBombillas(bombillas, potencia) = numero de bombillas necesarias teniendo n tipos de bombillas para cubrir una potencia determinada.

struct Bombilla {
    int potencia;
    int coste;
};

/*
* 
El coste mínimo de la instalación hasta una potencia dada es el menor de los siguientes:
            El coste mínimo de la instalación hasta la potencia anterior, sin instalar ninguna bombilla de la nueva potencia.
            El coste mínimo de la instalación hasta la potencia anterior, más el coste de la nueva bombilla.

*/


Bombilla resolver(int pMax, int pMin, const vector<Bombilla>& bombillas) {

    int n = bombillas.size();
    Matriz<int> m(n + 1, pMax + 1, 1000000); // Crea una matriz `m` de tamaño `n + 1` por `pMax + 1` con valores inicializados a 1000000

    //Casos base 
    for (int i = 0; i <= n; i++) {
        m[i][0] = 0; 
    } 

    for (int j = 1; j <= pMax; j++) { 
        m[0][j] = 1000000; 
    }

    //Caso recursivo 
    for (int i = 1; i <= n; ++i) // Recorre las bombillas (filas)
    {
        for (int j = 1; j <= pMax; ++j) // Recorre las potencias (columnas)
        {
            if (bombillas[i - 1].potencia <= j)          // Verifica si la potencia de la bombilla actual es menor o igual a la potencia objetivo `j`
            {
                m[i][j] = min(m[i - 1][j], m[i][j - bombillas[i - 1].potencia] + bombillas[i - 1].coste); // Actualiza el coste mínimo de la instalación hasta la potencia `j` considerando la posibilidad de instalar la bombilla actual
            }
            else m[i][j] = m[i - 1][j]; // Si la potencia de la bombilla actual es mayor que la potencia objetivo, no se puede instalar, por lo que el coste mínimo es el mismo que el coste mínimo de la instalación hasta la potencia objetivo sin instalar la bombilla actual
        }
    }

    //Una vez tengo la matriz rellena 

    int minPotencia = 0, costeMin = 1000000; 

    for (int i = pMin; i <= pMax; i++) { // Recorre las potencias objetivo desde `pMin` hasta `pMax`

        int aux = m[n][i]; // Almacena el coste mínimo de la instalación hasta la potencia `i`

        if (aux < costeMin) { // Si el coste mínimo actual es menor que el coste mínimo anterior
            costeMin = aux; // Actualiza el coste mínimo
            minPotencia = i; // Actualiza la mínima potencia objetivo
        }
    }

    return { minPotencia, costeMin }; // Devuelve un par con la mínima potencia objetivo y el coste mínimo
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int n, pMax, pMin;
    cin >> n >> pMax >> pMin;
    if (!std::cin)  // fin de la entrada
        return false;
    vector<Bombilla> bombillas(n);
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < n; i++) {
        cin >> bombillas[i].potencia;
    }
    for (int i = 0; i < n; i++) {
        cin >> bombillas[i].coste;
    }

    Bombilla sol = resolver(pMax, pMin, bombillas);
    // escribir la solución
    if (sol.coste == 1000000) cout << "IMPOSIBLE\n";
    else cout << sol.coste << " " << sol.potencia << endl;

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
