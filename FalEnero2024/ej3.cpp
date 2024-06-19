// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


struct tDatos {
    string atraccion;
    int tiempo;
    int satis;
    bool acuatico;
};

std::istream& operator>> (std::istream& in, tDatos& d) {
    in >> d.atraccion >> d.tiempo >> d.satis >> d.acuatico;
    return in;
}

// Explicación del árbol de exploración empleado y del vector solución
/*
Es un arbol binario, en el que las ramas son: me subo o no me subo, y la altura son las
atracciones.

Mientras haya tiempo aun para estar en el parque, miro si la atraccion que me voy a subir
me da tiempo, me subo

Si veo que es solucion fina, comparo si es mejor la satisfaccion actual que la mejor, y
la actualizo

Ramas: 2 ramas, me subo en la atraccion o no me subo

Altura: tantas como atracciones hay.

Vector solucion: tantas posiciones como altura tenga el arbol.

Cada posicion es una atraccion, y los valores son si me he subido o no.

*/

// función que resuelve el problemavoid 
void resolverVA(const vector<tDatos>& d,int tiempoLimite, int &tiempoRestante,int k,int &mojan, int& salpican, int& tiempoAct, int& satisAct, int& satisMejor, vector <int>& sol,
vector<int>& mejorSol) {
    sol[k] = true; //me subo a la atraccion
    if (d[k].tiempo <= tiempoRestante) {
        //marco
        tiempoAct += d[k].tiempo;//aumento tiempo
        tiempoRestante -= d[k].tiempo;
        satisAct += d[k].satis;
        if (d[k].acuatico == 1) mojan++;
        else if (d[k].acuatico == 0) salpican++;
        //fin marcaje
        if (k == sol.size() - 1) {//he llegado a una solucion final
            if (mojan <= salpican) {
                if (satisAct > satisMejor) {
                    satisMejor = satisAct;
                    mejorSol = sol;
                }
            }
        }
        else {
            resolverVA(d, tiempoLimite, tiempoRestante, k + 1, mojan, salpican, tiempoAct, satisAct, satisMejor, sol, mejorSol);
        }
        //desmarco
        tiempoAct -= d[k].tiempo;
        tiempoRestante += d[k].tiempo;
        satisAct -= d[k].satis;
        if (d[k].acuatico == 1) mojan--;
        else if (d[k].acuatico == 0) salpican--;
        //fin desmarcaje
    }
    //no la cojo
    sol[k] = false;
    if (k == sol.size() - 1) {//he llegado a una solucion final
        if (mojan <= salpican) {
            if (satisAct > satisMejor) {
                satisMejor = satisAct;
                mejorSol = sol;
            }
        }
    }
    else {
        resolverVA(d, tiempoLimite, tiempoRestante, k + 1, mojan, salpican, tiempoAct, satisAct, satisMejor, sol, mejorSol);
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
// leer los datos de la entrada
    int n, t; std::cin >> n >> t;
    if (n == 0 && t == 0) return false;
    std::vector<tDatos> v(n);
    for (tDatos& d : v) std::cin >> d;

    vector<int> sol(n);//vector solucion
    vector<int> mSol(n);
    int mojan = 0;
    int salpican = 0;
    //resolverVA(v, 0,t, , satisAct, satisMejor, sol, solMejor);
    // Dar valor a los parametros de la llamada a VA,
    // LLamada a la función de VA
    // Escribir los resultados
    int tiempoAct = 0;
    int satisAct = 0;
    int satisMejor = 0;
    resolverVA(v, t, t, 0, mojan, salpican, tiempoAct, satisAct, satisMejor, sol, mSol);
    if (satisMejor > 0) cout << satisMejor << "\n";
    else cout << "NINGUNA\n";

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
