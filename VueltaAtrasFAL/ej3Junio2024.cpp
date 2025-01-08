// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <climits>
using namespace std;


// función que resuelve el problema
void resolver(const vector<int>& montes, const vector<vector<int>>& distancias, int etapa, const int& maxDistancia, int& distanciaActual, int& minimaDistancia, vector<int>&sol, vector<int>&aux, const vector<int>& acum) {
    //recorro las ramas
    for (int i = 0; i < montes.size(); i++) {
        sol[etapa] = i;
        int distanciaAux = distancias[etapa][i];

        if (distanciaAux <= maxDistancia) { //puedo añadirlo
            distanciaActual += distancias[etapa][i];
            aux[i]--;
            if (etapa == sol.size() - 1) {
                int cont = 0;
                for (int a = 0; a < aux.size(); a++) {
                    if (aux[a] <= 0) {
                        cont++;
                    }
                }
                if (cont == aux.size()) {
                    if (distanciaActual < minimaDistancia) {
                        minimaDistancia = distanciaActual;
                    }
                }
            }
            else {
                //estimacion
                if (distanciaActual + acum[etapa + 1] < minimaDistancia) {
                    resolver(montes, distancias, etapa + 1, maxDistancia, distanciaActual, minimaDistancia, sol, aux,acum);
                }
            }
            aux[i]++;
            distanciaActual -= distancias[etapa][i];
        }
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nMontes, nVigilantes;
    cin >> nMontes >> nVigilantes;
    if (nMontes == 0 && nVigilantes == 0)
        return false;

    vector<int> montes(nMontes);
    vector<int> aux;
    for (int i = 0; i < nMontes; i++) {
        cin >> montes[i];
        aux.push_back(montes[i]);
    }
    int maxDistancia;
    cin >> maxDistancia; //distancia maxima a recorrer
    vector<vector<int>> distancias(nVigilantes, vector<int>(nMontes));
    for (int i = 0; i < nVigilantes; i++) {
        for (int j = 0; j < nMontes; j++) {
            cin >> distancias[i][j];
        }
    }

    vector<int> minimos(nVigilantes);
    for (int i = 0; i < nVigilantes; i++) {
        int minimo = distancias[i][0];
        for (int j = 0; j < nMontes; j++) {
            if (distancias[i][j] < minimo) {
                minimo = distancias[i][j];
            }
        }
        minimos[i] = minimo;
    }
    vector<int> acum(nVigilantes);
    acum[acum.size() - 1] = minimos[minimos.size() - 1];
    for (int j = minimos.size() - 2; j >= 0; j--) {
        acum[j] += minimos[j];
    }
    int minimaDistancia = INT_MAX;
    int distanciaActual = 0;
    vector<int> sol(nVigilantes);
    resolver(montes, distancias, 0, maxDistancia, distanciaActual, minimaDistancia, sol, aux,acum);

    if (minimaDistancia == INT_MAX) cout << "IMPOSIBLE\n";
    else cout << minimaDistancia << endl;

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("ej3Junio2024.txt");
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
