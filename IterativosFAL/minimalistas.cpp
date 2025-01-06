// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int minimalistas(const vector<int>& v) {
    int i = 1;
    int sol = 0;
    int minimo = v[0];
    int cont = 0;
    while (i < v.size()) {
        //veo v[i]
        if (v[i] < minimo) {
            minimo = v[i];
            sol = minimo;
        }
        else if (v[i] == minimo) {
            cont++;
            return cont;
        }
        else {}
        i++;
    }
    return cont;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n==-1)
        return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int sol = minimalistas(v);
    if (sol != 0) {
        cout << "NO\n";
    }
    else cout << "SI\n";
    // escribir sol
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("minimalistas.txt");
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
