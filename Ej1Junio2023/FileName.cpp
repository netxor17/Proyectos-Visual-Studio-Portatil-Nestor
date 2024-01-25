// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSol {
    int gananciaMax, iniSeg, finalSeg;
};

int resolverAux(const vector<int>& v, int G,int &ini, int &fin, int &maxLong) {
    int suma = 0; int maxBeneficio=0;
    while (fin < v.size()) {
        suma += v[fin];
        if (suma > 0) {
            fin++;
            if (suma > maxBeneficio) {
                maxBeneficio = max(maxBeneficio, suma);
                maxLong = max(maxLong, fin - ini);
            }
        }
        else {
            if (maxBeneficio >= G) {
                return maxBeneficio;
            }
            else {
                suma -= v[ini];
                fin++;
                ini++;
            }
        }
    }
    return maxBeneficio;
}

tSol resolver(const vector<int> &v, int G) {
    int ini = 0, fin =0, maxLong = 0;
    int sol = resolverAux(v, G, ini, fin,maxLong);
    return { sol,ini,fin -1};
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    tSol sol = resolver(v,s);
    // escribir sol

    if (sol.gananciaMax < s) cout << "NO COMPENSA\n";
    else cout << sol.gananciaMax << " " << sol.iniSeg << " " << sol.finalSeg << "\n";

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