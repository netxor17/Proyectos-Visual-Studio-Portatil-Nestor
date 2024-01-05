// Nestor Marin Gomez .....
//a79 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//Ramas: ida, vuelta, no la cojo (3 ramas)
//Altura: las canciones (posiciones vector solucion)


void resolverVA(vector<pair<int,int>>const &canciones,const int tiempoIda, const int tiempoVuelta,int k, vector <int>& sol, int &satisAct, int& satisMejor, int &tiempoAct,vector<int>& solMejor) {
    //cojo para la ida
    sol[k] = 1; //ida
    satisAct += canciones[k].second;
    tiempoAct += canciones[k].first;
    //marcado
    if (tiempoAct <= tiempoIda) {// es valida para la ida
        if (k == sol.size() - 1) {
            if (satisAct > satisMejor && tiempoAct == tiempoIda) {
                satisMejor = satisAct;
                solMejor = sol;
            }
        }
        else {
            resolverVA(canciones,tiempoIda,tiempoVuelta,k+1,sol,satisAct,satisMejor,tiempoAct,solMejor);
        }
    }
    //desmarco
    satisAct -= canciones[k].second;
    tiempoAct -= canciones[k].first;
    //cojo para la vuelta
    sol[k] = 2;//vuelta
    satisAct += canciones[k].second;
    tiempoAct += canciones[k].first;
    //marco
    if (tiempoAct <= tiempoVuelta) {// es valida para la ida
        if (k == sol.size() - 1) {
            if (satisAct > satisMejor && tiempoAct == tiempoVuelta) {
                satisMejor = satisAct;
                solMejor = sol;
            }
        }
        else {
            resolverVA(canciones, tiempoIda, tiempoVuelta, k + 1, sol, satisAct, satisMejor, tiempoAct, solMejor);
        }
    }
    satisAct -= canciones[k].second;
    tiempoAct -= canciones[k].first;
    //no la cojo
    sol[k] = 0;
    if (k == sol.size() - 1) {
        if (satisAct > satisMejor && tiempoAct <= tiempoVuelta) {
            satisMejor = satisAct;
            solMejor = sol;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, t1, t2;
    cin >> n;
    if (n == 0)
        return false;
    cin >> t1 >> t2;

    vector<pair<int,int>> canciones(n);

    vector<int> sol(n);

    for (int i = 0; i < n; ++i) {
        cin >> canciones[i].first >> canciones[i].second;
    }
    //(vector<pair<int,int>>const &canciones,const int tiempoIda, const int tiempoVuelta,int k, vector <int>& sol, int &satisAct, int& satisMejor, int &tiempoAct,vector<int>& solMejor) {
    int tAct= 1, satisMejor = 1, satisAct = 1;
    resolverVA(canciones,t1,t2,0,sol,satisAct, satisMejor,tAct, sol);
    
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i] << "\n";
    }
    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
