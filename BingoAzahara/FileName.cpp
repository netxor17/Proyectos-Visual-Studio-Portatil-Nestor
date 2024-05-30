//A80
//Nestor Marin Gomez.


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <set>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nPersonas;
    cin >> nPersonas;
    if (nPersonas == 0)
        return false;

    unordered_map<string, set<int>> mapaJugadores;
    for (int i = 0; i < nPersonas; i++) {
        string nombre;
        cin >> nombre;
        int n;
        cin >> n;
        set<int> numerosCarton;
        while (n != 0) {
            numerosCarton.insert(n);
            cin >> n;
        }
        mapaJugadores[nombre] = numerosCarton;
    }


    set<string> sol;
    while (!sol.size()) {
        int bola;
        cin >> bola;
        for (const auto& i : mapaJugadores) {
            if (i.second.count(bola) != 0) {
                mapaJugadores[i.first].erase(bola);
            }
            if (mapaJugadores[i.first].size() == 0) {
                sol.insert(i.first);
                if (sol.size() == nPersonas) {
                    break;
                }
            }
        }
        //cin >> bola;
    }
    // escribir sol
    for (auto i = sol.begin(); i != sol.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n";
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}