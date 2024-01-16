// Nestor Marin Gomez
// a79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> &datos) {

    sort(datos.begin(), datos.end()); //ordeno el vector

    int maximo = 0, cont = 1, puntoKm = datos[0];

    for (int i = 1; i < datos.size(); ++i) {
        if (datos[i] == datos[i - 1]) {//si son iguales, aumento contador
            cont++;
            if (cont > maximo) {//si el contador supera al maximo, actualizo las cosas
                maximo = cont;//actualizo maximo
                puntoKm = datos[i];//actualizo puntoKm
            }
        }
        else {//si rompo la racha de iguales
            cont = 1;//reseteo contador
        }
    }

    return puntoKm;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == -1)
        return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int sol = resolver(v);

    cout << sol << endl;
    // escribir sol

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
