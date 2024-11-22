//Nestor Marin Gomez
//FAL-A76

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

//Recurrencia: 
// T(n) = C0 si n == 1
// T(n) = T(n/2) + n si n > 1
// 
//Desplegado:
// T(n) = T(n/2) + n = T(n/2^2) + n/2 + n = 
// = T(n/2^3) + n/2^2 + n/2 + n = .... = T(n/2^k) + 2n = 
// = T(1) + 2n perteneciente a O(n)
// 
//Coste de la solucion: 
// O(n), tras desplegar la recurrencia. 
// La recurrencia es T(n/2) + n cuando n >1, porque divido el problema a la mitad, y llamo una funcion que tiene coste O(n).

bool contarParadas(const vector<int>& v, const int &parada, const int &x) {//coste de la funcion: O(n), siendo n el numero de elementos, ya que se recorre el vector una vez
    int suma = 0;
    int cont = 0;
    for (int i = 0; i < v.size(); i++) {
        if (suma + v[i] > x) {
            suma = v[i];
            cont++;
        }
        else {
            suma += v[i];
        }
    }
    return cont <= parada;
}


int sol(int ini, int fin, const vector<int>& v, int parada) {
    if (ini == fin) {
        return ini;
    }
    else {
        int m = (fin + ini) / 2; //mitad
        if (contarParadas(v, parada, m)) {
            return sol(ini, m, v, parada); //parte izquierda
        }
        else {
            return sol(m + 1, fin, v, parada); //parte derecha
        }
    }
}


bool resuelveCaso() {

    int nTramos, nParadas;
    cin >> nTramos >> nParadas;
    if (nTramos == 0 && nParadas == 0)
        return false;

    vector<int>v(nTramos);

    for (int i = 0; i < nTramos; i++) {
        cin >> v[i];
    }

    int maximoTiempo = v[0];
    int suma = 0;

    for (int i = 0; i < v.size(); i++) {
        suma += v[i];
        if (v[i] > maximoTiempo) {
            maximoTiempo = v[i];
        }
    }
    cout << sol(maximoTiempo, suma, v, nParadas) << endl;
    // escribir sol

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casosAbuelo.txt");
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