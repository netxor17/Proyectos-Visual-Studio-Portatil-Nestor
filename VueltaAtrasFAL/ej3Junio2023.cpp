// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

struct tProyecto {
    int minimo;
    int maximo;
    int sueldo;
};


// función que resuelve el problema

void resolver(const vector<int>& grupos, const vector<tProyecto>& proyectos, int etapa, int& sueldoActual, int& minSueldo, vector<int>& sol, vector<int>& aux) {
    // recorro las ramas (proyectos)
    for (int i = 0; i < proyectos.size(); i++) {
        sol[etapa] = i; 
        aux[i] += grupos[etapa];
        sueldoActual += proyectos[i].sueldo * grupos[etapa];
        // Poda de optimalidad
        if (sueldoActual < minSueldo) {
            if (etapa == grupos.size() - 1) {
                bool valido = true;
                for (int j = 0; j < proyectos.size(); j++) {
                    if (aux[j] < proyectos[j].minimo || aux[j] > proyectos[j].maximo) {
                        valido = false;
                        break;
                    }
                }
                if (valido) {
                    minSueldo = sueldoActual; 
                }
            }
            else {
                resolver(grupos, proyectos, etapa + 1, sueldoActual, minSueldo, sol, aux);
            }
        }
        aux[i] -= grupos[etapa];
        sueldoActual -= proyectos[i].sueldo * grupos[etapa];
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nGrupos, nProyectos;
    cin >> nGrupos >> nProyectos;

    vector<int> grupos(nGrupos);
    vector<tProyecto>proyectos(nProyectos);
    vector<int> aux(nProyectos,0);
    for (int i = 0; i < nGrupos; i++) {
        cin >> grupos[i];
    }
    for (int i = 0; i < nProyectos; i++) {
       cin >> proyectos[i].minimo;
    }
    for (int i = 0; i < nProyectos; i++) {
        cin >> proyectos[i].maximo;
    }
    for (int i = 0; i < nProyectos; i++) {
        cin >> proyectos[i].sueldo;
    }
    int sueldoActual =0;
    int minSueldo = INT_MAX;
    vector<int> sol(nGrupos); //vector solucion
    resolver(grupos,proyectos, 0, sueldoActual, minSueldo, sol, aux);

    if (minSueldo == INT_MAX) cout << "NO\n";
    else cout << minSueldo << endl;

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("ej3Junio2023.txt");
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
