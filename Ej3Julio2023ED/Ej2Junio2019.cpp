#include<algorithm>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"
using namespace std;

struct tSol {
	int actual = 0;
	int maximo = 0;
};


tSol resolver(const bintree<int>& a) {
	if (a.empty()) {
		return { 0,0 };
	}
	else {
		tSol izq = resolver(a.left());
		tSol der = resolver(a.right());
		tSol final;
		if (a.root() % 2 == 0) { //el padre es par
			final.actual = max(izq.actual, der.actual) + 1;
			final.maximo = max(izq.actual + der.actual + 1, max(izq.maximo, der.maximo));
		}
		else {//no es par, por lo que el actual se reinicia a 0
			final.actual = 0;
			final.maximo = max(izq.maximo, der.maximo);//se decide entre uno de los dos subarboles
		}
		return final;
	}
}


void resuelveCaso() {

	bintree<int> bt = leerArbol(-1);

	tSol s = resolver(bt);

	std::cout << s.maximo << std::endl;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;
	std::cin >> casos;

	for (; casos > 0; --casos)

		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	getchar();
#endif

	return 0;

}