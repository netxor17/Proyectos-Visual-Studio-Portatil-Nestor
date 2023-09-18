// Nestor Marin Gomez .....
// A79 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


// función que resuelve el problema
string resolver(const vector<int> &datos, int pos) {
    string sol;
    int mayor = datos[0]; //el maximo es el primer elemento
    int i = 1; //variable para iterar en el vector
    for(; i <pos+1; ++i) //para determinar la temperatura maxima a la izquierda de la posicion de referencia
    {
        if (datos[i] > mayor) mayor = datos[i]; 
    }
    while (i < datos.size() && datos[i] > mayor) i++; //itero en el vector desde la posicion p
    if (i == datos.size()) sol = "SI"; //si he llegado a la ultima posicion del vector
    else sol = "NO";
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numElem, pos;
    cin >> numElem;
    cin >> pos;

    vector <int> v(numElem);
    for (int i = 0; i < numElem; ++i) {
        cin >> v[i];
    }

    string sol = resolver(v, pos);
    // escribir sol
    cout << sol << endl;

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
