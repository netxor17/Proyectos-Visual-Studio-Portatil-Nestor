#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Solucion recursiva lineal no final
// Funcion utilizando expresion condicional
int transformadoNoFinal1(int n) {
	if (n < 10) return ((n % 2 == 1) ? (n % 10 - 1) : (n % 10 + 1));
	else {
		return transformadoNoFinal1(n / 10) * 10 + ((n % 2 == 1) ? (n % 10 - 1) : (n % 10 + 1));
	}
}
// Solucion utilizando instrucciones condicionales
int transformadoNoFinal2(int n) {
	if (n < 10) {
		if (n % 2 == 0) return (n % 10 + 1);
		else return n % 10 - 1;
	}
	else {
		int digito;
		if (n % 2 == 0) digito = n % 10 + 1;
		else digito = n % 10 - 1;
		return transformadoNoFinal2(n / 10) * 10 + digito;
	}
}

void resuelveCaso() {
	int a;
	std::cin >> a;
	std::cout << transformadoNoFinal2(a) << endl ;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos1.txt");
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