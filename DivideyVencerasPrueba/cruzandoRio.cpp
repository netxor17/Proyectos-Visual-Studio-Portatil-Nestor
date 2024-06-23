// Nombre del alumno DIEGO CHOCANO RAMOS
// Usuario del Juez A12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int izq(vector<int>const& v, int ini, int fin) {
    if (ini + 1 >= fin) return ini;
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] > v[mitad + 1]) return izq(v, mitad + 1, fin);
        else return izq(v, ini, mitad + 1);
    }
}
int Dr(vector<int>const& v, int ini, int fin) {
    if (ini + 1 >= fin) return ini;
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad - 1] < v[mitad]) return Dr(v, ini, mitad);
        else return Dr(v, mitad, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == -1)
        return false;
    vector<int> v(n);
    for (int& n : v) cin >> n;
    int sol = izq(v, 0, v.size());

    if (n == 0) cout << "0" << endl;
    else {
        if (sol != n - 1) {
            int fin = Dr(v, 0, v.size());
            cout << fin - sol + 1 << endl;
        }
        else cout << "1" << endl;
    }
    // escribir sol
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("cruzandoRio.txt");
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
