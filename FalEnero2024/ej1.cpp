#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct tSol {
	int pos;
	bool ok;
};


tSol menorPico(vector<int> const& v) {
	int menorPico = INT_MAX;
	int menor = 0;
	bool ok = false;
	if (v.size() > 3) {
		int a = 1;
		int b = a + 1;
		while (a < v.size() - 1) {
			if (v[a] > v[a - 1] && v[a] > v[b]) {
				menor = v[a];
				if (menor < menorPico) {
					ok = true;
					menorPico = menor;
				}
			}
			a++;
			b++;
		}
		return { menorPico, ok };
	}
	else {
		return { -1,false };
	}
}



bool resuelveCaso() {
	// Lectura de datos
	int n; std::cin >> n;
	if (n == 0) return false;
	std::vector<int> v(n);
	for (int& i : v) std::cin >> i;
	// LLamada a la funcion que resuelve el problema y escribir el resultado
	tSol sol = menorPico(v);
	if (sol.ok) cout << sol.pos << endl;
	else cout << "no hay" <<endl;
		return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}