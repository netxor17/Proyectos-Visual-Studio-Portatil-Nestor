// Nestor Marin Gomez .....
// A79 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;




// función que resuelve el problema
string resolver(const vector<long long int> &datos, long long int d) {
    long long int i = 1;
    long long int acum = 0;
    string sol = "APTA";
    while(i < datos.size())
    {
        if (datos[i] > datos[i-1])
        {
            acum += datos[i] - datos[i-1];
        }
        else
        {
            acum = 0;
        }
        //ahora miro el desnivel
        if (acum > d)
        {
            return "NO APTA";
        }
    	++i;
    }
    return sol;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int desnivel, nElems;
    while(cin >> desnivel)
    {
        cin >> nElems;
        vector<long long int> v(nElems);

        for (long long int i = 0; i < nElems; ++i) {
            cin >> v[i];
        }

        if (!std::cin)
            return false;

        string sol = resolver(v, desnivel);

        // escribir sol
        cout << sol << endl;
    }
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