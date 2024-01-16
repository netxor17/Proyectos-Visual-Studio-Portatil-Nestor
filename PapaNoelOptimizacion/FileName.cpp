// Nestor Marin Gomez a79

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tDatos {
    int numJuguetes, numNinos;
    vector<vector<int>> satisfacciones;
};

struct tSol {
    int sumaSatis;
    vector<int> sol;
};


// función que resuelve el problema

//vector solucion: cada posicion es un niño, y el contenido es un juguete

//Arbol: Ramas: los juguetes
//Altura: los niños

void resuelveVA(const tDatos& datos, int k, tSol& s, vector <bool>& marcas, int& satisMejor, const vector<int>& acum) {
    for (int i = 0; i < datos.numJuguetes; i++) {//for para las ramas
        s.sol[k] = i;
        //marco
        if (!marcas[i]) {//es valido, no lo he cogido
            s.sumaSatis += datos.satisfacciones[k][i];
            marcas[i] = true;
            if (k == s.sol.size() - 1) {//es sol final
                if (s.sumaSatis > satisMejor) {//reviso si es optima esta suma
                    satisMejor = s.sumaSatis;
                }
            }
            else {//no es sol final
                if (s.sumaSatis + acum[k + 1] > satisMejor) {//estimacion para k+1
                    resuelveVA(datos, k + 1, s, marcas, satisMejor, acum);
                }
            }
            //desmarco
            s.sumaSatis -= datos.satisfacciones[k][i];
            marcas[i] = false;
        }


    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    tDatos datos;
    // leer los datos de la entrada
    cin >> datos.numJuguetes;
    if (!std::cin)
        return false;
    cin >> datos.numNinos;
    //leo las satisfacciones
    for (int i = 0; i < datos.numNinos; ++i) {
        vector<int> aux(datos.numJuguetes);
        for (int j = 0; j < datos.numJuguetes; ++j) {
            cin >> aux[j];
        }
        datos.satisfacciones.push_back(aux);
    }

    //calculo vector de maximos
    vector<int> acum(datos.numNinos);

    for (int i = 0; i < datos.numNinos; ++i) {
        int auxMax = datos.satisfacciones[i][0];//maxima satisfaccion del iesimo nino
        for (int j = 1; j < datos.numJuguetes; ++j) {
            if (auxMax < datos.satisfacciones[i][j]) auxMax = datos.satisfacciones[i][j];
        }
        acum[i] = auxMax;
    }

    //vector de acumulados
    for (int i = acum.size() - 1; i > 0; --i) {
        acum[i - 1] += acum[i];
    }

    //inicializacion posible para sol mejor
    int satisMejor = 0;

    for (int i = 0; i < datos.numNinos; ++i) {
        satisMejor += datos.satisfacciones[i][i];
    }

    //preparo los datos de la solucion

    tSol s;

    s.sol.assign(datos.numNinos, 0);//digo que son todos 0
    s.sumaSatis = 0;
    vector<bool> marcas(datos.numJuguetes, false);
    
    resuelveVA(datos,0,s,marcas,satisMejor,acum );

    // escribir sol
    cout << satisMejor << "\n";

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