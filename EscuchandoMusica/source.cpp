// Nestor Marin Gomez .....
//a79 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//Ramas: ida, vuelta, no la cojo (3 ramas)
//Altura: las canciones (posiciones vector solucion)


int estimar(vector<pair<int, int>>const& canciones, int tiempoIdaAct, int tiempoVueltaAct, int k, const vector<int> &sol, int tiempoIda, int tiempoVuelta) {
    int i = k + 1; //para las siguientes etapas
    int sumaTiempo = tiempoIdaAct + tiempoVueltaAct; //tiempo para estimar
    int sumaSatis = 0;//satisfaccion a estimar
    int sumaTiemposTrayectos = tiempoIda + tiempoVuelta; //tiempo total trayectos

    while (i < sol.size() && sumaTiempo + canciones[i].first <= sumaTiemposTrayectos) {
        sumaSatis += canciones[i].second;
        sumaTiempo += canciones[i].first;
        i++;
    }
    //puede quedar un tiempo donde no cabe la siguiente cancion pero aun queda tiempo
    if (i < sol.size() && sumaTiempo < sumaTiemposTrayectos) {//parte proporcional de la cancion que se puede coger aun
        sumaSatis += canciones[i].second * (sumaTiemposTrayectos - sumaTiempo) / canciones[i].first + 1;
    }

    return sumaSatis;
}

void resolverVA(vector<pair<int,int>>const &canciones,const int tiempoIda,int &tiempoIdaAct,int &tiempoVueltaAct, const int tiempoVuelta,int k, vector <int>& sol, int &satisAct, int& satisMejor, int &tiempoAct,vector<int>& solMejor) {
    //cojo para la ida
    sol[k] = 1; //ida
    satisAct += canciones[k].second;
    tiempoIdaAct += canciones[k].first;
    //marcado
    if (tiempoIdaAct <= tiempoIda) {// es valida para la ida
        if (k == sol.size() - 1) {
            if (satisAct > satisMejor && tiempoIdaAct == tiempoIda && tiempoVueltaAct == tiempoVuelta) {
                satisMejor = satisAct;
                solMejor = sol;
            }
        }
        else {
            resolverVA(canciones,tiempoIda,tiempoIdaAct,tiempoVueltaAct,tiempoVuelta,k+1,sol,satisAct,satisMejor,tiempoAct,solMejor);
        }
    }
    //desmarco
    satisAct -= canciones[k].second;
    tiempoIdaAct -= canciones[k].first;

    //cojo para la vuelta
    sol[k] = 2;//vuelta
    satisAct += canciones[k].second;
    tiempoVueltaAct += canciones[k].first;
    //marco
    if (tiempoVueltaAct <= tiempoVuelta) {// es valida para la ida
        if (k == sol.size() - 1) {
            if (satisAct > satisMejor && tiempoIdaAct == tiempoIda && tiempoVueltaAct == tiempoVuelta) {
                satisMejor = satisAct;
                solMejor = sol;
            }
        }
        else {
            resolverVA(canciones, tiempoIda, tiempoIdaAct, tiempoVueltaAct, tiempoVuelta, k + 1, sol, satisAct, satisMejor, tiempoAct, solMejor);
        }
    }
    satisAct -= canciones[k].second;
    tiempoVueltaAct -= canciones[k].first;

    //no la cojo
    sol[k] = 0;
    //siempre es sol
    if (k == sol.size() - 1) {
        if (satisAct > satisMejor && tiempoIdaAct == tiempoIda && tiempoVueltaAct == tiempoVuelta) {
            satisMejor = satisAct;
            solMejor = sol;
        }
    }
    //falta estimar
    else {
        if (estimar(canciones,tiempoIdaAct,tiempoVueltaAct,k,sol,tiempoIda,tiempoVuelta) + satisAct > satisMejor)
            resolverVA(canciones, tiempoIda, tiempoIdaAct, tiempoVueltaAct, tiempoVuelta, k + 1, sol, satisAct, satisMejor, tiempoAct, solMejor);
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

    vector<bool> marcas(n);

    int tIdaAct =0, tVueltaAct = 0, tAct= 0, satisMejor = 0, satisAct = 0;

    //resolverVA(canciones,t1,t2,0,sol,satisAct, satisMejor,tAct, sol);
    resolverVA(canciones, t1, tIdaAct,tVueltaAct,t2, 0, sol, satisAct, satisMejor, tAct, sol);
    
    if (satisMejor > 0)
        cout << satisMejor << "\n";

    else cout << "Imposible\n";
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
