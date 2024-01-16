// Nestor Marin Gomez .....
// A79 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esValida(vector<int>& marcas, const int &i) {
    if (marcas[i] > 1) {//el trabajo se ha asignado
        return false;
    }
    return true;
}

// Ramas: el coste de cada trabajo
// Altura: cada funcionario
// Vector solucion: posiciones son los funcionarios, y los valores son el coste de las tareas
// función que resuelve el problema
void funcionariosVA(const vector<vector<int>>& tiempos, vector<int>& sol, int k, int& acum, int& total,vector<int> &marcas) {
    for (int i = 0; i < tiempos.size(); ++i) {//recorro las ramas (cada tarea)
        sol[k] = i;
        //marco
        total += tiempos[k][i];
        marcas[i]++; //pongo a 1
        //he marcado
        if (esValida(marcas, i)) {
            if (k == tiempos.size() - 1) { //solucion final
                if (total < acum) acum = total;
            }
            else {
                funcionariosVA(tiempos, sol, k + 1, acum, total, marcas);
            }
        }
        //desmarco
        total -= tiempos[k][i];
        marcas[i]--;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nFuncionarios;
    cin >> nFuncionarios;

    if (nFuncionarios == 0)
        return false;

    vector<vector<int>>tiempos;
    tiempos.resize(nFuncionarios, vector<int>(nFuncionarios));
    //leo los datos
    for (int i = 0; i < nFuncionarios; ++i) {
        for (int j = 0; j < nFuncionarios; ++j) {
            cin >> tiempos[i][j];
        }
    }

    vector<int> sol(nFuncionarios);//vector solucion

    int j = 0, acum = 0;
    for (int i = 0; i < nFuncionarios; ++i) {
        sol[i] = tiempos[i][j];
        acum += sol[i];
        ++j;
    }

    vector<int> marcas(nFuncionarios,0);

    int total = 0;
    funcionariosVA(tiempos, sol, 0, acum, total, marcas);
    // escribir sol
    cout << acum << "\n";

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
