#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
/*
 * Complejidad: O(n)
 *
 * Coste:
 *
 * 		T(n) = {
 *
 * 			c 				Si (left==right) v (left+1==right)
 *
 * 			2 * T(n/2) + c 	En cualquier otro caso.
 *
 * 		}
 *
 */


int resolver(const vector<int> &v, const int& ini, const int& fin) {

	if (ini == fin) {//vector con un elemento
		return (v[ini] % 2 == 0);
	}
	else if (ini + 1 == fin) {
		//vector con dos elementos
		if ((v[ini] % 2 == 0) || ((v[fin] % 2 == 0))) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {
		int middle = (ini + fin) / 2;
		int l = resolver(v, ini, middle);
		int r = resolver(v, middle + 1, fin);
		return (l != -1 && r != -1 && std::abs(l - r) <= 2) ? (l + r) : -1;
	}

}

bool resuelveCaso() {

	int nElems;
	std::cin >> nElems;
	if (nElems == 0)
		return false;

	vector<int> v(nElems);
	for (int& i : v)
		std::cin >> i;

	std::cout << ((resolver(v, 0, v.size() - 1) != -1) ? "SI" : "NO") << std::endl;

	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("numerosCaucasicos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	// getchar();
#endif

	return 0;

}