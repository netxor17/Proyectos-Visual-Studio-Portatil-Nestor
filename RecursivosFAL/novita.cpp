// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;


// función que resuelve el problema
pair<int, int> resolver(vector<int> v1, vector<int> v2, int ini, int fin) {
    if (ini + 1 == fin) { //vector dos elementos
        if (v1[ini] == v2[ini]) {
            return { v1[ini],-1 };
        }
        if (v1[fin] == v2[fin]) {
            return { v1[fin],-1 };
        }
        if ((v1[ini] < v2[ini]) && v1[fin] > v2[fin]) {
            return { v1[ini],v1[fin] };
        }
        return { -1,-1 };
    }
    else {
        int m = (ini + fin) / 2;
        if (v1[m] == v2[m]) {
            return { v1[m],-1 };
        }
        if ((v1[m] < v2[m]) && v1[m + 1] > v2[m + 1]) {
            return { v1[m],v1[m + 1] };
        }
        if (v1[m] >= v2[m]) {
            auto izq = resolver(v1, v2, ini, m);
            return izq;
        }
        else {
            auto dcha = resolver(v1, v2, m + 1, fin);
            return dcha;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> v1(n);
    vector<int> v2(n);

    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
    }
    auto sol = resolver(v1, v2, 0, v1.size() - 1);

    // escribir sol
    if (sol.second == -1) {
        cout << "HABLAN " << sol.first << endl;
    }
    else {
        cout << "SE CRUZAN " << sol.first << " " << sol.second << endl;
    }
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("novita.txt");
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