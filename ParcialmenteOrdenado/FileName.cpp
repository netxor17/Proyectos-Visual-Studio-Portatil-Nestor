

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSol {
    int min, max;
    bool ok;
};
// función que resuelve el problema

tSol resolver(const vector<int> &v, int ini, int fin) {
    if (ini + 1 ==  fin){//vector con 1 elemento
        return { v[ini], v[ini], true };
    }
    else {//vector con 2 elementos o mas
        int m = (ini + fin) / 2;

        tSol izq = resolver(v, ini, m);//resuelvo la izquierda
        tSol der = resolver(v, m, fin);//resuelvo la derecha

        if (izq.ok && der.ok && izq.min <= der.min && der.max >= izq.max) {//miro si cumple las condiciones
            return { der.max, izq.min, true };
        }
        else return { 0,0,false };//si no, malo
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<int> v;

    while (n != 0) {
        v.push_back(n);
        cin >> n;
    }
    tSol solucion;
    solucion = resolver(v, 0,(int)v.size());

    // escribir sol
    if (solucion.ok) {
        cout << "SI \n";
    }
    else {
        cout << "NO \n";
    }

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
