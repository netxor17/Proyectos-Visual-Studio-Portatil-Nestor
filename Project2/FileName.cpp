// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
bool resolver(const vector<int>& v, int ini, int fin, int min, int max) {
    if (ini + 1 == fin) {//vector un elemento
        if (v[ini] != min && v[ini] != max) return true;
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] != min && v[mitad] != max) return true;
        else if (v[mitad] == min) resolver(v, mitad + 1, fin,min,max);
        else resolver(v, ini, mitad,min,max);
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
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    //vector ordenado
    int min = v[0], max = v[v.size() - 1];
    bool sol = resolver(v,0,v.size(),min,max);
    if (sol==true) cout << "SI\n";
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
