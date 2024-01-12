
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

#include "Matriz.h"
using namespace std;

/*@ <answer>

tirar(i,j) formas de conseguir sumar la cantidad j tirando un dado de i caras.

casos base :
    Conseguir la cantidad j con caras de valor 0
    tirar(0,j) = 0;

    Conseguir un 0 con caras de valor i
    tirar(i,0) = 1; //no tirar el dado es una manera

caso recursivo
    tirar(i,j) = tirar(i-1, j) + tirar ( i, j-i);

    //tirar(i-1,j) formas de llegar a la cantidad j sin coger esa cara de valor i
    //tirar(i,j-i) formas de llegar a la cantidad descontada (j-i) porque cojo ese valor i

 @ </answer> */

long long int tirar(int k, int s) {
    Matriz<long long int> m(k + 1, s + 1, 0);//matriz de soluciones
    //caso base 1
    for (int i = 0; i <= k; i++) {
        m[i][0] = 1;
    }
    //caso base 2
    for (int j = 0; j <= k; j++) {
        m[0][j] = 0;
    }
    //casos recursivos
    //relleno la matriz de izda a dcha y arriba a abajo
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= s; j++) {
            if ((j >= i)) {//si la cantidad pendiente es mayor que el valor de la cara
                m[i][j] = m[i - 1][j] + m[i][j - i];
            }
            else {//para que no se salga del vector cuando j es peque�o
                m[i][j] = m[i - 1][j];
            }
        }
    }
    return m[k][s];//devuelvo la ultima posicion (abajo a la derecha)
}


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

void resuelveCaso() {

    // leer los datos de la entrada
    int caras, suma;
    cin >> caras >> suma;

    cout << tirar(caras, suma) << "\n";

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
