/*
NOMBRE Y APELLIDOS:

Nº USUARIO DOMJUDGE:

*/

#include <iostream>
#include <vector>


using namespace std;

const int MAX_PERSONAS = 20;
const int MAX_VEHICULOS = 10;


// Datos de entrada

/*
(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.


*/

typedef struct {
    bool ha_bebido[MAX_PERSONAS];   // ha_bebido[i]: La persona i ha bebido
    int capacidad[MAX_VEHICULOS];   // capacidad[v]: Nº de personas que caben en el vehículo v
    int n_personas;                 // Nº total de personas en el clan
    int n_vehiculos;                // Nº total de vehículos
} tDatos;



void resolverVA(const tDatos& d, int k, int& cont, vector<bool> &conductor, vector<int> &integrantes, vector<int> &borrachos, vector<int> &sol) {
    for (int i = 0; i < d.n_vehiculos; ++i) {//recorro las ramas
        sol[k]=i;
        integrantes[i]++;
        if (d.ha_bebido[k]) borrachos[i]++;
        if (integrantes[i] < d.capacidad[i] && borrachos[i] < d.capacidad[i]/2) {
            if (!d.ha_bebido[k] && !conductor[i]) {
                conductor[i] = true;//tiene conductor
            }
            if (k == sol.size() - 1) {//he rellenado toda la solucion
                cont++;
            }
            else {
                resolverVA(d,k+1,cont,conductor,integrantes,borrachos,sol);
            }
            if (!d.ha_bebido[k] && !conductor[i]) conductor[i] = false;
        }
        if (d.ha_bebido[k]) borrachos[i]--;
        integrantes[i]--;
    }
}

int num_asignaciones(const tDatos& datos) {
    // A IMPLEMENTAR
    int k = 0, cont =0;
    vector<bool> conductor;
    vector<int> integrantes;
    vector<int> borrachos;
    vector<int> sol;
    resolverVA(datos, k, cont, conductor, integrantes, borrachos, sol);
    return cont;
    }


bool ejecuta() {
    tDatos datos;
    cin >> datos.n_vehiculos;
    if (datos.n_vehiculos == -1) return false;
    cin >> datos.n_personas;
    for (int v = 0; v < datos.n_vehiculos; v++) {
        int bebe;
        cin >> datos.capacidad[v];
    }
    for (int p = 0; p < datos.n_personas; p++) {
        int bebe;
        cin >> bebe;
        if (bebe == 0) {
            datos.ha_bebido[p] = false;
        }
        else {
            datos.ha_bebido[p] = true;
        }
    }
    cout << num_asignaciones(datos) << endl;
    return true;

}


int main() {
    while (ejecuta());
}