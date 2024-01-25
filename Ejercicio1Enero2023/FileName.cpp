// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool resolver(const vector<int>& v, int valor) {
    int a = 0, b = 0;
    int suma = 0;
    while (a < v.size() && suma != valor) {
        if (suma + v[a] <= valor) {
            suma += v[a];
            a++;
        }
        else {
            suma -= v[b];
            b++;
        }
    }
    return suma == valor;
}

// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == -1)
        return false;
    vector<int> v(n);

    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
    int valor;
    cin >> valor;

    bool s = resolver(v,valor);

    if (s == true) cout << "SI\n";
    else cout << "NO\n";
    

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
