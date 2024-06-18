// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tProyecto {
    int min;
    int max;
    int sueldo;
};

//ramas: equipos
//altura: proyectos

// función que resuelve el problema
void resolver(const vector<int>& equipos, const vector<tProyecto>& proyectos, int k, int& minSueldo, vector<int> &sol, vector<int> &mejorSol, int &sueldoAct) {
    for (int i = 0; i < equipos.size(); i++) {
        sol[k] = i; //proyecto k asignado al equipo i
        //marcas
        if (k == sol.size() - 1) {//sol final
            if (sueldoAct < minSueldo) {
                minSueldo = sueldoAct;
                mejorSol = sol;
            }
        }
        else {
            resolver(equipos, proyectos, k + 1, minSueldo, sol, mejorSol, sueldoAct);
        }
        sueldoAct -= proyectos[i].sueldo;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nEquipos, nProyectos, nPersonas, necMin, necMax;
    cin >> nEquipos >> nProyectos;
    vector<int> equipos(nEquipos);
    vector<tProyecto> proyectos(nProyectos);
    for (int i = 0; i < nEquipos; i++) {
        cin >> equipos[i];
    }
    for (int j = 0; j < nProyectos; j++) {
        cin >> proyectos[j].min;
    }
    for (int j = 0; j < nProyectos; j++) {
        cin >> proyectos[j].max;
    }
    for (int j = 0; j < nProyectos; j++) {
        cin >> proyectos[j].sueldo;
    }
    int minSueldo = INT_MAX;
    vector<int> sol(nEquipos);
    vector<int> mejorSol(nEquipos);
    int sueldo = 0;
    resolver(equipos,proyectos,0,minSueldo, sol, mejorSol,sueldo);
    // escribir sol
    if (minSueldo == INT_MAX) cout << "NO \n";
    else cout << minSueldo <<endl;

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