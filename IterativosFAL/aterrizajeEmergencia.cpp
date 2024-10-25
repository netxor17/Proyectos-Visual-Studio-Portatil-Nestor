#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void resolver(vector<int> const& fotos, int numValoresCasiIguales) {
	vector<int> solucion;
	int contadorActual = 1;
	for (int i = 0; i < fotos.size() - 1; ++i) {
		if (std::abs(fotos[i + 1] - fotos[i]) <= 1) {
			++contadorActual;
			if (contadorActual == numValoresCasiIguales) solucion.push_back(i - contadorActual + 2);
		}
		else contadorActual = 1;
	}
	cout << solucion.size() << " ";
	for (int i = 0; i < solucion.size(); ++i)
		cout << solucion[i] << " ";
	cout << "\n";
}
bool resuelveCaso() {
	int numDatos, numValoresCasiIguales;
	cin >> numDatos >> numValoresCasiIguales;
	if (numDatos == 0 && numValoresCasiIguales == 0) return false;
	vector<int> fotos(numDatos);
	for (int i = 0; i < numDatos; ++i)
		cin >> fotos[i];
	resolver(fotos, numValoresCasiIguales);
	return true;
}

int main() {
	//Si no estamos ejecutando en el juez (el DOMJUDGE) el entorno no tendra definido
	//el DOMJUDGE, por lo que cogemos los datos de un fichero y hacemos que el cin entre por ahi
#ifndef DOMJUDGE
	std::ifstream in("casos_aterrizaje.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	while (resuelveCaso());
	//Volvemos a dejar la entrada como estaba y hacemos PAUSE para poder leer la consola sin que se cierre
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}