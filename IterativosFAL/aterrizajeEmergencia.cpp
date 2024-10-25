#include <iostream>
#include <vector>
#include <fstream>

//Nestor Marin Gomez
//Usuario juez: A76

using namespace std;
//Especificacion:
// P: {0 < v.size() && val >= 2}
// resolver(vector<int>const &v,int val) dev vector<int> sol
// Q: {sol: sol.size() = count(zonasPlanas(v))}
// zonasPlanas(v) = {exists ini: ini = sol[k] 
//						&& exists l: l >= val 
//						&& forall m: ini <= m < ini + val -1 -> abs(v[m+1] - v[m]) <= 1}
//
//Invariante del bucle:
// I: {0 <= i < v.size() 
// 		&& forall k: 0 <= k < v2.size() -> exists l: l >= val 
// && forall m : k <= m < i + l -1 -> abs(v[m+1] - v[m]) <= 1} }
// 
//Cota: t = v.size() - i.
// 
//Coste de la solucion: O(n), ya que la funcion resuelve tiene coste O(n).

//Coste de la funcion: O(n), siendo n el numero de elementos del vector que recibo
// ya que el bucle for solamente recorre una vez todas las posiciones del vector
void resolver(vector<int> const& v, int numValMin) {
	vector<int> v2;
	int cont = 1;
	for (int i = 0; i < v.size() - 1; ++i) {
		if (abs(v[i + 1] - v[i]) <= 1) {//si la diferencia es 1 o menos
			cont++; //aumento contador
			if (cont == numValMin) {
				v2.push_back(i - cont + 2);//meto al vector resultante el inicio de la zona casi plana
			}
		}
		else cont = 1; //reseteo el contador
	}
	cout << v2.size() << " ";
	for (int i = 0; i < v2.size(); ++i) {
		cout << v2[i] << " ";
	}
	cout << "\n";
}

bool resuelveCaso() {
	int nDatos, numValMin;
	cin >> nDatos >> numValMin;
	if (nDatos == 0 && numValMin == 0) return false;
	vector<int> v(nDatos);
	for (int i = 0; i < nDatos; ++i) {
		cin >> v[i];
	}
	resolver(v, numValMin);
	return true;
}

int main() {
	//Si no estamos ejecutando en el juez (el DOMJUDGE) el entorno no tendra definido
	//el DOMJUDGE, por lo que cogemos los datos de un fichero y hacemos que el cin entre por ahi
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	while (resuelveCaso());
	//Volvemos a dejar la entrada como estaba y hacemos PAUSE para poder leer la consola sin que se cierre
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}