// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
int resolver(vector<int> const& v, int ini, int fin, const int ahorro, const int presupuesto) {
    int diasRestantes;
    if(ini + 1 == fin) { //vector un elemento
        diasRestantes = ((int)v.size() - ini);
        if ((v[ini] + (ahorro * diasRestantes)) > presupuesto) {
            return ini;
        }
    }
    else {
        int m = (ini + fin) / 2;
        diasRestantes = ((int)v.size() - m);
        if (v[m] + (ahorro * diasRestantes) == presupuesto) return m;//justo es la mitad
        else if (v[m] + (ahorro * diasRestantes) < presupuesto) resolver(v, m, fin, ahorro, presupuesto); //busco en la mitad drcha
        else resolver(v, ini, m, ahorro, presupuesto);//busco mitad izda
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int p, a, n;
    cin >> p >> a >> n;

    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    //son valores crecientes
    int sol = resolver(v, 0, v.size(), a, p);
    // escribir sol
    cout << sol << "\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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