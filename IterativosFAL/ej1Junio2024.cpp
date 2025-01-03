
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

int resolver(const vector<int>& v, int k) {
    int nSegmentos = 0;  // Contador de subsegmentos v�lidos
    int n = v.size();

    // Revisar si el vector tiene menos de k elementos
    if (n < k) {
        return 0;
    }

    // Inicializar una variable para contar el n�mero de elementos estrictamente crecientes
    int cont = 1;  // Contamos desde el primer elemento
    bool creciente = false;  // Bandera para saber si encontramos tres elementos crecientes consecutivos

    // Recorremos el primer subsegmento de tama�o k
    for (int i = 1; i < k; i++) {
        if (v[i - 1] < v[i]) {
            cont++;
        }
        else {
            cont = 1;  // Reiniciamos el contador si no es creciente
        }
        if (cont >= 3) {
            creciente = true;  // Se encontr� una secuencia creciente de 3 elementos
        }
    }

    // Si el primer subsegmento no tiene tres elementos consecutivos crecientes, lo contamos
    if (!creciente) {
        nSegmentos++;
    }

    // Recorremos el resto del vector, ajustando la ventana de tama�o k
    for (int i = k; i < n; ++i) {
        // Descontamos el primer valor del subsegmento anterior si era creciente
        if (v[i - k] < v[i - k + 1]) {
            cont--;
        }

        // Verificamos el nuevo valor
        if (v[i - 1] < v[i]) {
            cont++;
        }
        else {
            cont = 1;  // Reiniciamos si no es creciente
        }

        // Si encontramos una secuencia creciente de 3 elementos, no contamos este subsegmento
        if (cont >= 3) {
            creciente = true;
        }

        // Si no se encontr� una secuencia creciente, contamos el subsegmento
        if (!creciente) {
            nSegmentos++;
        }

        // Reiniciamos la bandera creciente para el siguiente subsegmento
        creciente = false;
    }

    return nSegmentos;
}



bool resuelveCaso() {

    // leer los datos de la entrada
    int n, k;
    cin >> n;
    if (n == 0)
        return false;
    cin >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // resolver el caso posiblemente llamando a otras funciones
    int sol = resolver(v, k);
    // escribir la soluci�n
    cout << sol << endl;
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("ej1Junio2024.txt");
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
