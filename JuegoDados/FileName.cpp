//Nestor Marin Gomez a79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
vector<int> resolver(const vector<int> &v, int puntMax) {
    vector<int> apariciones(puntMax);//vector para cada valor de una cara del dado
    
    for (int n : v) ++apariciones[n-1];//cuento las apariciones de cada tirada

    int aparicionesMax = apariciones[0];//inicializo

    for (int i = 0; i < apariciones.size(); ++i) {
        aparicionesMax = max(aparicionesMax,apariciones[i]);//comparo con cada posicion y me quedo con el maximo
    }
    vector<int> sol;//no declaro una dimension porque no se cual va a tener

    for (int i = 0; i < apariciones.size(); ++i) {
        //si el numero de apariciones de la posicion i del vector de apariciones coincide con las maximas apariciones
        //lo añado al vector haciendo un push_back(), añadiendolo al final del vector
        if (apariciones[i] == aparicionesMax) sol.push_back(i+1);
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nTiradas, puntMax;
    cin >> nTiradas;
    if (nTiradas == -1)
        return false;
    cin >> puntMax;

    vector<int> v(nTiradas);
    for (int i = 0; i < nTiradas; ++i) {
        cin >> v[i];
    }

   vector<int> sol = resolver(v, puntMax);

   cout << sol[sol.size() - 1];//si slo tiene un elemento, lo muestro
   //cout << sol.back();

   for (int i = sol.size() - 1; i > 0; --i) {//muestro los demas elementos
       cout << " " << sol[i - 1];//muestro de menor a mayor
   }
   cout << "\n";
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
