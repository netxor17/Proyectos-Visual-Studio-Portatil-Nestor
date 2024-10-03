
/*@ <answer>
 *
 * Nombre y Apellidos: Nestor Marin Gomez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

pair<long long int, int> resuelve(const vector<int>& v) {
    
    int menor = v[0];
    long long int suma = 0;
    int cont = 0;
    int apariciones = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < menor) {
            int aux = menor;
            aux *= apariciones;
            suma += aux;
            cont += apariciones;
            menor = v[i];
            apariciones = 1;
        }
        else if (v[i] == menor) ++apariciones;
        else {
            suma += v[i];
            cont++;
        }
    }
    return { suma,cont };
}

void resuelveCaso() {
    int numElems;
    cin >> numElems;
    vector<int> v(numElems);
    // leer los datos de la entrada
    for (int i = 0; i < numElems; i++) {
        cin >> v[i];
    }
    pair<long long int,int> sol = resuelve(v);
    // resolver el caso posiblemente llamando a otras funciones
    cout << sol.first << " " << sol.second << endl;
    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos_encuestas.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
