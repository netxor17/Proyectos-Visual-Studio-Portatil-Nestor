// Nestor Marin Gomez
// a79 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


struct tSol {
    int ini;
    int fin;
};

tSol resolver(const vector<int>& v, int transporte) {
    int longSegMax = 0, iniSegMax = 0, longAct = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (transporte < v[i]) {//si cumple la condicion
            longAct++;//aumento longitud
            if (longAct > longSegMax) {//miro si es mejor que la que tenia
                longSegMax = longAct;
                iniSegMax = i - longAct + 1;
            }
        }
        else {//si he roto la condicion, reseteo
            longAct = 0;
        }
    }
    return {iniSegMax, iniSegMax + longSegMax -1 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int edificios, transporte;
    cin >> edificios >> transporte;
    vector<int> v(edificios, 0);

    for (int i = 0; i < edificios; ++i) {
        cin >> v[i];
    }

   // TipoSolucion sol = resolver(datos);
    // escribir sol
    tSol sol = resolver(v, transporte);

    cout << sol.ini << " " << sol.fin << "\n";

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