// Nestor Marin Gomez .....
// A79 ......


#include <iostream>
#include <iomanip>
#include <fstream>

/*
Recurrencia de la funcion:

T(n):   c1 si n <= 1;
        T(n-1) + c2 si n>1

Desplegado: 

*/
// función que resuelve el problema

long long int resolver(int num, int valor, long long int aux1, long long int aux2) {
    //caso base
    if (num == 0) return aux2;
    //caso base
    else if (num == 1) return aux1;
    else {
        return resolver(num - 1, valor, 2*valor*aux1 - 2*(num-1)*aux2, aux1);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num, valor;
    std::cin >> num;
    if (num == -1)
        return false;
    std::cin >> valor;

    long long int sol = resolver(num,valor,2*valor,1);

    std::cout << sol<< "\n";

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
