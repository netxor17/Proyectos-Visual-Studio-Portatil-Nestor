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

int mayoritarioRecurs(vector<int> const& v, int ini, int fin) {
    int n = fin - ini;
    if (ini >= fin) {//vector vacio
        return 0;
    }
    else if (ini + 1 == fin) {//vector 1 elemento
        return v[ini];
    }
    else {//caso recursivo
        int mitad = (ini + fin) / 2;

        int mayoritarioIzq = mayoritarioRecurs(v, ini, mitad);
        int mayoritarioDer = mayoritarioRecurs(v, mitad, fin);

        int vecesIzq = contarApariciones(v, mayoritarioIzq, ini, fin);
        int vecesDer = contarApariciones(v, mayoritarioDer, ini, fin);

        if (vecesIzq > n / 2) {
            return mayoritarioIzq;
        }
        else if (vecesDer > n / 2) {
            return mayoritarioDer;
        }
        else {
            return 0;
        }
    }

    //Se podria hacer una funcion que devuelva un par de enteros, para a la hora de llamar a la funcion que recorre el vector
    //solo recorra la mitad de ese vector, ya sabiendo el numero de veces que aparecia ese elemento en la otra mitad.
    //pero no me da tiempo
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
    int sol = mayoritarioRecurs(v,0,v.size());
    // escribir sol
    if (sol == 0) {
        cout << "NO\n";
    }
    else {
        cout << sol << "\n";
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