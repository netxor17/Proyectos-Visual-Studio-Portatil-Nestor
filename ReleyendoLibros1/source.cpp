#include <iostream>
#include <fstream>
#include <vector>
int resolver(std::vector <int> const& v, int L) {
	// Primer intervalo
	int sumaMax = 0; int sumaAct = 0; int posIni;
	for (int i = 0; i < L; ++i) {
		sumaAct += v[i];
	}
	sumaMax = sumaAct; posIni = 0;
	// Resto del vector
	for (int i = L; i < v.size(); ++i) {
		sumaAct -= v[i - L];
		sumaAct += v[i];
		if (sumaAct >= sumaMax) { // El intervalo es mejor
			posIni = i - L + 1;
			sumaMax = sumaAct;
		}
	}
return posIni;
}
// Resuelve un caso de prueba .
bool resuelveCaso() {
	// Lectura de los datos
	int numElem, L;
	std::cin >> numElem >> L;
	if (numElem == 0 && L == 0) return false;
	std::vector <int> v(numElem);
	for (int& i : v) std::cin >> i;
	// Resolver el problema
	int pos = resolver(v, L);
	// Escribir la solucion
	std::cout << pos << '\n';
	return true;
}
int main() {
	// Para la entrada por fichero .
# ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
# endif
	// Entrada con centinela
	while (resuelveCaso())
		;
	// Para restablecer entrada .
# ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
# endif
	return 0;
}