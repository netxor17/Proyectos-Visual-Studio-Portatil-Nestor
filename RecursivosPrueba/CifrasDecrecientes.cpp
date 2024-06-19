// Contar las veces que aparece un dig en un num
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int resolverNoFinalAux(long long int num, int max_derecha) {
    if (num == 0) {
        return 0;
    }
    int digito_actual = num % 10;
    int resto = resolverNoFinalAux(num / 10, std::max(max_derecha, digito_actual));

    if (digito_actual >= max_derecha) {
        return resto * 10 + digito_actual;
    }
    else {
        return resto;
    }
}

// Función principal recursiva
int resolverNoFinal2(long long int num) {
    return resolverNoFinalAux(num, -1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    long long int num;
    std::cin >> num;
    int sol2 = resolverNoFinal2(num);
    // escribir sol
    std::cout << sol2 << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("cifrasDecrecientes.txt");
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