// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"
#include <algorithm>
using namespace std;

//Que vamos a calcular
/*
 Alinear(i,j) = maximo valor al alinear dos cadenas desde x0 a xi, y y0 a yj
 
 //Casos base: 
 Alinear(0,j) = S[-,j] + Alinear(0,j-1)
 Alinear(i,0) = S[i,-] + Alinear(i-1,0)
 Alinear(0,0) = 0; //no cojo ninguna letra de ningun lado
 
 Recursion:
 Alinear(i,j) = max( S[i,j] + Alinear(i-1,j-1), S[-,j] + Alinear(i,j-1), S[i,-] + Alinear(i -1, j));
*/



// función que resuelve el problema
int resolver(const Matriz<int> &m, string cadena1, string cadena2, int i, int j) {
    Matriz<int> sol(m.numfils() + 1, m.numcols() + 1, -1);
    //caso base primero
    sol[0][0] = 0;
    for (int x = 1; x < j; x++) {
        sol[0][x] = m[4][j] + resolver(m,cadena1,cadena2,0,x-1);
    }
    for (int x = 1; x < j; x++) {
        sol[x][0] = m[x][4] + sol[x-1][0];
    }
    for (int x = 2; x < i; x++) {
        for (int z = 2; z < j; z++) {
            sol[x][z] = max(m[i][j] + sol[x - 1][z - 1], (m[i][4] + sol[x - 1][z] + m[4][j] + sol[x][z - 1]));
        }
    }

    return sol[i][j];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Matriz<int> m(5, 5, 0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> m[i][j];
        }
    }

    int nPares;
    cin >> nPares;
    vector<string> cadenas(2*nPares);

    for (int i = 0; i < 2*nPares; i++) {
        cin >> cadenas[i];
    }
    for (int i = 0; i < 2*nPares;i+=2 ) {
        int sol = resolver(m, cadenas[i], cadenas[i + 1], 5, 5);
        cout << sol <<endl;
    }
   // int sol = resolver(m,cad1,cad2, 5,5);
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("alinearCadenas.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}