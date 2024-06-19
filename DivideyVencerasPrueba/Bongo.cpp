
// El juego del bongo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(int const& C, std::vector<int>const& v, int ini, int fin) {
    // Caso base 1 elemento
    if (ini == fin) { //ini == fin porque fin era size - 1
        if (C + ini == v[ini]) {
            return v[ini];
        }
        else return -1;
    }
    else {
        int m = (ini + fin) / 2;
        if (C + m == v[m])
            return v[m];
        else if (C + m < v[m])
            return resolver(C, v, ini, m); //parte izda
        else
            return resolver(C, v, m+1, fin); //parte dcha

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    int N, C, num; // N: num de numeros en el carton || C: numero cantado

    std::cin >> N >> C;
    std::vector<int> v;

    for (int i = 0; i < N; ++i) {
        std::cin >> num;
        v.push_back(num);
    }
    int sol = resolver(C, v, 0, N-1);
    if (sol > 0)
        std::cout << sol << '\n';
    else
        std::cout << "NO" << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("35sample.in");
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