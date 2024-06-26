﻿// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


// función que resuelve el problema
void resolver(vector<long long int>  &datos, const int erroneo) {
    int i = 0;
    int cont = 0;
    while (i < datos.size())
    {
        if (datos[i] != erroneo)
        {
            datos[cont] = datos[i];
            ++cont;
        }
        ++i;
    }
    datos.resize(cont);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numElem;
	long long int valorErroneo;
    cin >> numElem >> valorErroneo;

    vector<long long int> v(numElem);

    for(int i =0; i < numElem; ++i)
    {
        cin >> v[i];
    }

    // escribir sol
    resolver(v, valorErroneo);
    if (v.size() == 0) cout << "0" << endl;
    else
    {
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); ++i)
        {
            if(v[i] !=0)
            {
                cout << v[i] << " ";

            }
            else {}
        }
    }

    cout << endl;
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