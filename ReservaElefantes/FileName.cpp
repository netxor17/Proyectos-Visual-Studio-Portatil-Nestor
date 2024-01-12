// Nestor Marin Gomez
//a79

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
void resolver(const vector<int> &datos, vector<long long int> & acumulados)
{
    //en el vector acumulados, voy a ir acumulando la suma en cada posicion
    acumulados[0] = 0;
    for (int i = 1; i < acumulados.size(); ++i) {
        acumulados[i] = acumulados[i - 1] + datos[i - 1];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int inicio, final;
    cin >> inicio >> final;
    if (inicio == 0 && final == 0)
        return false;
    int numeroNnacimientos = final - inicio + 1;
    vector<int> v(numeroNnacimientos, 0);

    for (int i = 0; i < numeroNnacimientos; ++i) {
        cin >> v[i];
    }
    int nPreguntas;
    cin >> nPreguntas;

    vector<long long int> acumulados(v.size() + 1);//vector de acumulados

    resolver(v, acumulados);
    
    for (int i = 0; i < nPreguntas; ++i) {
        int ini, fin;
        cin >> ini >> fin;
        cout << acumulados[fin - inicio + 1] - acumulados[ini - inicio] << "\n";
    }
    cout << "---\n";

    // escribir sol

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
