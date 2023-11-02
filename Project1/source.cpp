# include <iostream>
# include <fstream>
# include <string>

// Solucion recursiva lineal no final
int sumaDigitos(int n) {
	if (n < 10) return n; // Caso base
	else return sumaDigitos(n / 10) + n % 10; // Caso recursivo
}
bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem, numero;
	std::cin >> numElem >> numero;
	if (!std::cin) return false;
	// resolver y escribir los resultados
	int suma = sumaDigitos(numero);
	for (int i = 0; i < numElem; ++i) {
		std::cin >> numero;
		if (sumaDigitos(numero) == suma) std::cout << numero << " ";
	}
	std::cout << "\n";
	return true;
}
int main() {
# ifndef DOMJUDGE
	std::ifstream in("casos.txt ");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .txt
# endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
# ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
}