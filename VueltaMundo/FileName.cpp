// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

using lli = long long int;

// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nDias;
    cin >> nDias;
    if (nDias == -1)
        return false;

    vector<lli> v(nDias);

    for (int i = 0; i < nDias; ++i) {
        cin >> v[i];
    }


    //calculo en un vector la suma acumulada de los km

    vector<lli> sumaAcumulada(nDias + 1, 0);

    for(int i = nDias -1; i >= 0; --i) {
        sumaAcumulada[i] = sumaAcumulada[i + 1] + v[i];//vector de acumulados por dia
    }


    int nPreguntas;
    cin >> nPreguntas;

    for (int i = 0; i < nPreguntas; ++i) {
        int dia; 
        cin >> dia;
        cout << sumaAcumulada[dia-1] << "\n";
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