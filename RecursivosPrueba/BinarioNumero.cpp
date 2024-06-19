#include <iostream>
#include <fstream>
#include <string>
// Solucion recursiva lineal no final
std::string decimalBinario(int n) {
	if (n == 0) return "0";
	else if (n == 1) return "1";
	else return decimalBinario(n / 2) + char('0' + n % 2);
}
void resuelveCaso() {
	int n;
	std::cin >> n;
	std::cout << decimalBinario(n) << "\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos3.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}