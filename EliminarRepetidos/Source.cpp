// Nestor Marin Gomez .....
// A79 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



// función que resuelve el problema
void resolver(vector<int> &v) {
    sort(v.begin(), v.end());
    int referencia = v[0];
    int i = 1;
    int cont = 1;
    while( i< v.size())
    {
	    if(v[i]!= referencia)
	    {
            v[cont] = v[i];
            ++cont;
            referencia = v[i];
	    }
        i++;
    }
    v.resize(cont);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nElems;
    cin >> nElems;
    if (!std::cin)
        return false;

    vector<int> v(nElems);
    for(int j =0; j < v.size();++j)
    {
        cin >> v[j];
    }

	resolver(v);

    for(int i =0; i < v.size();++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}