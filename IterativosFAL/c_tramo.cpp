
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

bool resuelve(const vector<int>& v, const int& numero) {
    int i = 0;
    int j = 0;
    int sumaAcum = 0;
    while (i < v.size() && j < v.size()) {
        sumaAcum += v[j];
        if (sumaAcum == numero) {
            return true;
        }
        else if (sumaAcum < numero) {
            j++;
        }
        else {
            sumaAcum = 0;
            j = i + 1;
            i++;
        }
    }
    return false;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == -1)
        return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int num;
    cin >> num;
    // resolver el caso posiblemente llamando a otras funciones
    bool sol = resuelve(v, num);
    // escribir la soluci�n
    if (sol) {
        cout << "SI\n";
    }
    else cout << "NO\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("c_tramo.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
