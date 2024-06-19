﻿


// Contar las veces que aparece un dig en un num

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolverFinal(long long int num, int const& D, int cont) {

    int digito = num % 10;
    //caso base:
    if (num < 10)
        return (num == D ? cont += 1 : cont); // añadimos al cont el digito

    else {

        if (digito == D)
            cont += 1;

        return resolverFinal(num / 10, D, cont);
    }


}

int resolverNoFinal(long long int num, int const& D) {
    int digito = num % 10;
    //caso base:
    if (num < 10)
        return (digito == D ? 1 : 0); // añadimos al cont el digito
    else {
        return  resolverNoFinal(num / 10, D) + (digito == D ? 1 : 0); //resultado llamada recursiva + si ese digito es == D
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    long long int num;
    int D; // digito que queremos contar

    std::cin >> num >> D;

    int sol1 = resolverNoFinal(num, D);
    int sol2 = resolverFinal(num, D, 0);

    // escribir sol
    std::cout << sol1 << " " << sol2 << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos5.txt");
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