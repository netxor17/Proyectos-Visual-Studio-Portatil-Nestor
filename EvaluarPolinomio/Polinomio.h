#ifndef  POLINOMIO
#define POLINOMIO

#include <vector>
#include <cstdint>

using namespace std;

class Polinomio {
private:

	vector<pair<int, int>> monomios;

public: 

	Polinomio() {}

	int busquedaBinaria(vector<pair<int, int>> const& monomios, int ini, int fin, const int &exp) {
		while (ini < fin) {
			int mitad = (ini + fin) / 2;
			if (monomios[mitad].second == exp) return mitad;
			else if (monomios[mitad].second > exp) return busquedaBinaria(monomios, ini, mitad, exp);
			else return busquedaBinaria(monomios, mitad+1, fin, exp);
		}
		return -1; //si no lo he encontrado
	}

	void anadirMonomio(const int &coef,const int &exp) {

		if (monomios.empty()) {//vector vacio
			monomios.push_back({ coef,exp });
		}
		else {//no esta vacio
			int index = busquedaBinaria(monomios, 0, monomios.size(), exp);
		
			if (index != -1) {//si he encontrado el indice, actualizo
				monomios[index].first += coef;
			}
			else {
				if (exp < monomios[0].second) {//menor que el primero
					monomios.insert(monomios.begin(), { coef,exp });
				}
				else if (exp >= monomios[monomios.size()-1].second) {//mayor que todos los que hay
					monomios.push_back({ coef, exp });
				}
				else {
					// para encontrar la posición del primer elemento que no es menor que el exponente
					auto it = lower_bound(monomios.begin(), monomios.end(), pair<int, int>{0, exp});
					// Insertar el nuevo monomio en la posición correcta
					monomios.insert(it, { coef, exp });
				}
			}
		}
	}

	int64_t evaluarPolinomio(const int& valor) const {
		int64_t resultado = 0;
		for (const auto& monomio : monomios) {
			int64_t c = monomio.first;
			int64_t e = monomio.second;
			int64_t pot = 1;
			for (int i = 0; i < e; ++i) {
				pot *= valor;
			}
			resultado += c * pot;
		}
		return resultado;
	}

};

#endif // ! POLINOMIO

