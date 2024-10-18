#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//Nombre alumno: Nestor Marin Gomez
//Usuario juez: A76

//Coste final de la solucion: O(n log n), ya que se usa la funcion sort, que tiene coste O(n log n).

vector<int> resolver(vector<int> const& v1, vector<int> const& v2) {
	vector<int> sol;
	int i = 0;
	int j = 0;
	while (i < v1.size() && j < v2.size()) {
		if (v1[i] == v2[j]) {
			sol.push_back(v1[i]);
			++i;
			++j;
		}
		else if (v1[i] > v2[j])
			++j;
		else
			++i;
	}
	return sol;
}

//coste de la funcion leerVector: O(n log n), ya que se hace uso de la funcion sort, que tiene coste O(n log n)
void leerVector(vector<int>& vector) {
	int dato;
	cin >> dato;
	while (dato != 0) {
		//introduzco datos leidos
		vector.push_back(dato);
		cin >> dato;
	}
	//lo ordeno despues de leerlo
	sort(vector.begin(), vector.end());
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	vector<int> v1, v2;

	leerVector(v1);
	leerVector(v2);

	vector<int> sol = resolver(v1, v2);
	// escribir sol
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << " ";
	}
	cout << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos_interseccion.txt");
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