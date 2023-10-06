// Nestor Marin Gomez    .....
// A79 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


// función que resuelve el problema
pair<bool,int> resolver(const vector<int> &v) {

    bool ok = false;
    int suma = 0;
    int index = -1;
    int ref = 0;

    for()

    return { ok, index };
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nElems;
    cin >> nElems;

    vector<int> v(nElems);

    for (int i = 0; i < nElems; ++i)
    {
        cin >> v[i];
    }

    pair<bool,int> sol = resolver(v);

    if (sol.first == true)
    {
        cout << "Si " << sol.second;
    }
    else cout << "No";
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