// Nestor Marin Gomez
// FAL-A76

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//Arbol de exploracion:
// Ramas: cada color
// Altura: el numero de bombillas de la tira
//Vector solucion:
// El vector solucion tiene tamaño la altura del arbol, que es el numero de bombillas que cabe en la tira
// y en cada posicion, guardo la bombilla seleccionada


bool esValida(const vector <int> &v, const vector<int> &tira, const vector <int> &marca, int i, int bombillas, int max_consumo, int consumo) {
	bool ok = true;
	int mi_color = marca[i];
	int resto_colores = bombillas - mi_color;

	if ((mi_color - resto_colores) > 0) { 
		ok = false; 
	}
	if (max_consumo < (consumo + v[i])) { 
		ok = false; 
	}
	if ((bombillas >= 2) && (tira[bombillas - 2] == i) && (tira[bombillas - 1] == i)) {
		ok = false;
	}
	return ok;
}


void resuelveVA(const vector <int> &v, vector<int> &tira, vector <int> &marca, int longi, int colores, int max_consumo, int &combinaciones, int k, int consumo) {
	for (int i = 0; i < colores; i++) { //recorro las ramas (colores)
		tira[k] = i;
		if (esValida(v, tira, marca, i, k, max_consumo, consumo)) { // comprobacion de si es valida 
			++marca[i]; //marco
			if (longi == (k + 1)) { 
				++combinaciones; //aumento las combinaciones
			}
			else {
				resuelveVA(v, tira, marca, longi, colores, max_consumo, combinaciones, k + 1, consumo + v[i]); //siguiente etapa
			}
			--marca[i]; //desmarco
		}
	}
}

bool resuelveCaso() {
	int tam, colores, max_consumo;
	cin >> tam;
	if (tam == 0) { 
		return false;
	}
	cin >> colores >> max_consumo;

	vector <int> v_costes(colores);
	vector <int> marca(colores);
	vector <int> tira(tam);

	for (int i = 0; i < colores; ++i) {
		cin >> v_costes[i];
	}
	int nCombinaciones = 0;
	resuelveVA(v_costes, tira, marca, tam, colores, max_consumo, nCombinaciones, 0, 0);
	cout << nCombinaciones << endl;
	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("lucesNavidad.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso()) {}
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif

	return 0;
}