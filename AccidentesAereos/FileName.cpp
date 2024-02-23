// Nestor Marin Gomez.
// A80


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nLineas;
    cin >> nLineas;
    if (!std::cin)
        return false;
    string fecha;
    int nAccidentes;
    stack<pair<string, int>> pila;
    for (int i = 0; i < nLineas; ++i) {
        cin >> fecha;
        cin >> nAccidentes;
        while (!pila.empty() && pila.top().second <= nAccidentes ) {
            pila.pop();
        }
        if (pila.empty()) {
            cout << "NO HAY" <<"\n";
            pila.push({ fecha, nAccidentes });

        }
        else {
            cout << pila.top().first <<"\n";
            pila.push({ fecha, nAccidentes });
        }
    }
    cout << "---" << endl;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
