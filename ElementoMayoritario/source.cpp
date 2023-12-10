// Nestor Marin Gomez .....
// A79......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


int contarApariciones(const vector<int>& v, int elemento, int inicio, int fin) {
    int count = 0;
    for (int i = inicio; i < fin; ++i) {
        if (v[i] == elemento) {
            count++;
        }
    }
    return count;
}

pair<int, int> mayoritarioRecurs(vector<int> const& v, int ini, int fin) {
    int n = fin - ini;
    if (ini >= fin) {//vector vacio
        return { 0,0 }; 
    }
    else if (ini + 1 == fin) {//vector 1 elemento
        return { v[ini] , 1 };// devuelve el elemento y la cantidad de veces que aparece
    }
    else {//caso recursivo
        int mitad = (ini + fin) / 2;

        auto mayoritarioIzq = mayoritarioRecurs(v, ini, mitad);//devuelve el numero mayoritario de la izquierda, y las veces que aparece
        auto mayoritarioDer = mayoritarioRecurs(v, mitad, fin);//devuelve el numero mayoritario de la derecha, y las veces que aparece

        int vecesIzq = contarApariciones(v, mayoritarioIzq.first, mitad, fin) + mayoritarioIzq.second; // mira la otra mitad
        int vecesDer = contarApariciones(v, mayoritarioDer.first, ini, mitad) + mayoritarioDer.second; // mira la otra mitad

        if (vecesIzq > n / 2) {
            return { mayoritarioIzq.first, vecesIzq };
        }
        else if (vecesDer > n / 2) {
            return { mayoritarioDer.first, vecesDer };
        }
        else {
            return { 0,0 };
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int i = 0;
    vector<int> v;
    cin >> n;
    while (n != 0) {
        v.push_back(n);
        cin >> n;
    }
    auto sol = mayoritarioRecurs(v,0,v.size());
    // escribir sol
    if (sol.second == 0) {
        cout << "NO\n";
    }
    else {
        cout << sol.first << "\n";
    }
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