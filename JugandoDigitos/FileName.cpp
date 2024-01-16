// Nestor Marin Gomez 
// a79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using lli = long long int;
using namespace std;


//Casos base:
//  si n < 10:
//          si n %2 == 1 (impar) n-1;
//          sin n %2 == 0 (par) n+1
// 
//Caso recursivo:
// 
// resolver(n/10) *10 + r % 10;



// función que resuelve el problema
 int resolver(int d) {
     if (d < 10) {//caso base (condicion de parada)
         if (d % 2 == 0) {//es par
             return d + 1;
         }
         else {
             return d - 1;
         }
     }
     else {
         int condicion = ((d % 10) % 2 == 0) ? (d % 10) + 1 : (d % 10) - 1;
         return resolver(d / 10) * 10 + condicion ;
     }
  
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    int sol = resolver(n);
    // escribir sol
    cout << sol <<"\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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