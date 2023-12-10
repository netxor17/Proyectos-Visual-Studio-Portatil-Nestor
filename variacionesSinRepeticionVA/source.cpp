// Nestor Marin Gomez .....
// a79 ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tDatos {
    int m, n;
};

struct tSol {
    std::vector<char> sol;
    std::vector<bool> marcas;
};

// Declaración de la función
void escribirSolucion(std::vector<char> const& v);

void variaciones(tDatos const& datos, int k, tSol& s) {
    for (char i = 'a'; i < 'a' + datos.m; ++i) {
        s.sol[k] = i;
        if (!s.marcas[i - 'a']) { // Si la letra no está utilizada
            s.marcas[i - 'a'] = true;
            if (k == datos.n - 1) { // Es solución
                escribirSolucion(s.sol);
            }
            else { // Genera el resto de la solución
                variaciones(datos, k + 1, s);
            }
            s.marcas[i - 'a'] = false;
        }
    }
}

// Definición de la función
void escribirSolucion(std::vector<char> const& v) {
    for (char c : v) std::cout << c;
    std::cout << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la configuración y escribiendo la respuesta
bool resuelveCaso() {
    int m, n;
    std::cin >> m >> n;
    if (!std::cin) return false;

    tSol s;
    s.sol.resize(n);
    s.marcas.assign(m, false);

    variaciones({ m, n }, 0, s);
    std::cout << '\n';

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos . txt
#endif

    while (resuelveCaso()) {} // Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
