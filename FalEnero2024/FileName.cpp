// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void inicializaIntervalo(vector<double>&v, double ini, double fin) {
    double i = ini;
    while (i <= fin) {
        v.push_back(i);
        i += 0.01;
    }
    v.push_back(i);
}

double valor(const vector<int>& v, double n) {
    double suma = 0;
    int i = 0;
    while (i < v.size() - 1) {
        suma += v[i] * n;
        i++;
    }
    suma += v[i];
    return suma;
}

// función que resuelve el problema
double resolver(const vector<int> &v, vector<double> const &intervalo, double ini, double fin) {
    double mitad = (ini + fin) / 2.0; 
    double resultado = valor(v, mitad);
    double resultado2 =valor(v, ini);
    //caso base
    if (resultado <= 0.01) {
        return mitad;
    }
    else { //caso recursivo
        if (resultado > 0) {
           return resolver(v, intervalo, ini, mitad);
        }
        else if (resultado < 0)  {
            return resolver(v, intervalo, mitad, fin);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nValores = 5;
    vector<int> polinomio(nValores);
    vector<double> intervalo;
    for (int i = 0; i < nValores; i++) {
        cin >> polinomio[i];
    }
    double ini, fin;
    cin >> ini >> fin;
    inicializaIntervalo(intervalo, ini, fin);
    double sol = resolver(polinomio,intervalo, ini, fin);
    // escribir sol
    cout << setprecision(2) << sol <<endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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