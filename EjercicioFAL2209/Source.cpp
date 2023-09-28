// Nestor Marin Gomez .....
// A79 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


/*funcion que resuelve el problema
Analisis del coste de la funcion:
La funcion itera en un vector, posicion a posicion, y solamente revisa que valor tiene cada posicion
dentro del bucle, son todo operaciones constantes, ya que son comparaciones y operaciones atitmeticas
por lo que el coste de la funcion es la del bucle, que es lineal en funcion al tamaño del vector
Por lo tanto pertenece al orden O(n), siendo n el numero de elementos (lineal)
*/
pair <long long int,long long int> resolver(const vector<long long int> &v) {
	long long int min = v[0];
    long long int suma = min;
    long long int contMin = 1;
    for (int i = 1; i < v.size(); ++i) { //recorro el vector
        if (v[i] < min) { //si es menor que el minimo, actualizo
            min = v[i];
            contMin = 1; //reinicio el contador de minimos
        }
        else if (v[i] == min) contMin++; //si es igual al minimo, actualizo el contador de minimos
        suma += v[i];//sumo
    }
    suma = suma - contMin*min; //resto los minimos
	long long int cont = v.size() - contMin;
    return { suma, cont }; //retorno los resultados
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numElems;
    cin >> numElems;

    vector <long long int> v(numElems);

    for(int i =0; i < numElems; ++i)
    {
        cin >> v[i];
    }


    pair<long long int,long long int> sol = resolver(v);
    // escribir sol
    cout << sol.first<< " " << sol.second <<endl;


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