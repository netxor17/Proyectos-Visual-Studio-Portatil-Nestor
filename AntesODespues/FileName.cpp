#include < iostream >
#include < fstream >
#include <string>
#include "Fecha.h"


bool resuelveCaso()
{

	unsigned int h1, m1, s1, h2, m2, s2;
	char aux;


	std::cin >> h1 >> aux >> m1 >> aux >> s1;
	std::cin >> h2 >> aux >> m2 >> aux >> s2;

	try {
		Fecha hora1(h1, m1, s1);
		Fecha hora2(h2, m2, s2);
		if (hora1 == hora2) std::cout << "IGUALES \n";
		else if (hora1 < hora2) std::cout << hora1 << " " << hora2 << "\n";
		else std::cout << hora2 << " " << hora1 << "\n";
	}
	catch (std::invalid_argument& ia) {
		std::cout << ia.what() << '\n';
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


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
