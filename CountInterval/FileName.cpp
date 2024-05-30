//A80
//Néstor Marín Gómez

#include <iostream>
#include <iomanip>
#include <fstream>
#include "set_eda.h"
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numeros, intervalos;
	cin >> numeros >> intervalos;
	set<int>cjto;
	if (!std::cin)
		return false;
	int n;
	for (int i = 0; i < numeros; i++) {
		cin >> n;
		cjto.insert(n);
	}
	int n1, n2;
	for (int i = 0; i < intervalos; i++) {
		cin >> n1 >> n2;
		const auto sol = cjto.interval(n1, n2);
		cout << sol << "\n";
	}
	// escribir sol
	cout << "---\n";
	return true;
}
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.
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