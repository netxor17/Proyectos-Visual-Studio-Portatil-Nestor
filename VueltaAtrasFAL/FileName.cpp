// Nestor Marin Gomez
// FAL-A76
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
void resolver(const vector<int>& v, int k, int m, bool& posible, int sumaActual) {
    // Caso base: Si hemos recorrido todos los números
    if (k == v.size()) {
        // Si la suma actual es igual a m, se encuentra una solución
        if (sumaActual == m) {
            posible = true;
        }
        return;
    }

    // Si ya encontramos una solución, no continuamos explorando
    if (posible) return;

    // Explorar con suma (rama izquierda del árbol binario)
    resolver(v, k + 1, m, posible, sumaActual + v[k]);

    // Si no se encontró solución, explorar con resta (rama derecha del árbol binario)
    if (!posible) {
        resolver(v, k + 1, m, posible, sumaActual - v[k]);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int m, n;
    cin >> m >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    bool posible = false; // Variable para determinar si es posible obtener el número m
    resolver(v, 0, m, posible, 0);
    if (posible == true) {
        cout << "SI";
    }
    else {
        cout << "NO";
    }
    cout << endl;
    // escribir sol
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