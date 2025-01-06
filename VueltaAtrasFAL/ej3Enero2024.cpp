// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct tDatos
{
    string nombre;
    int tiempo;
    int satis;
    int acuatica;
};


// función que resuelve el problema
void resolver(const vector<tDatos> &v, int etapa,int &tiempoActual,const int &tiempoTotal,int &mojan, int &salpican, int &satisActual, int &satisMejor, vector<bool>&solucion) {
    //me subo a la atraccion
    solucion[etapa] = true;
    tiempoActual += v[etapa].tiempo;
    satisActual += v[etapa].satis;
    if (v[etapa].acuatica == 1) mojan++; //mojan
    else salpican++; //salpican
    if (tiempoActual <= tiempoTotal) { //es valida
        if (etapa == solucion.size() - 1) {
            if (mojan<=salpican) {
                if (satisActual > satisMejor) {
                    satisMejor = satisActual;
                }
            }
        }
        else {
            resolver(v, etapa + 1, tiempoActual, tiempoTotal, mojan,salpican,satisActual,satisMejor, solucion);
        }
    }
    tiempoActual -= v[etapa].tiempo;
    satisActual -= v[etapa].satis;
    if (v[etapa].acuatica == 1) mojan--; //mojan
    else salpican--;
    //no me subo
    solucion[etapa] = false;
    //siempre es valido
    if (etapa == solucion.size() - 1) {
        if (mojan <= salpican) {
            if (satisActual > satisMejor) {
                satisMejor = satisActual;
            }
        }
    }
    else {
        resolver(v, etapa + 1, tiempoActual, tiempoTotal, mojan, salpican, satisActual, satisMejor, solucion);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nAtracciones, tiempo;
    cin >> nAtracciones >> tiempo;
    if (nAtracciones == 0 && tiempo == 0)
        return false;
    vector<tDatos> v(nAtracciones);

    for (int i = 0; i < nAtracciones; i++) {
        cin >> v[i].nombre;
        cin >> v[i].tiempo;
        cin >> v[i].satis;
        cin >> v[i].acuatica;
    }
    int tiempoActual = 0;
    int satisMejor = 0;
    int satisActual = 0;
    int mojan = 0, salpican = 0;
    vector<bool> solucion(nAtracciones);
    resolver(v,0,tiempoActual,tiempo,mojan,salpican,satisActual,satisMejor,solucion);

    if (satisMejor != 0) cout << satisMejor << endl;
    else cout << "NINGUNA" << endl;

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("ej3Enero2024.txt");
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
