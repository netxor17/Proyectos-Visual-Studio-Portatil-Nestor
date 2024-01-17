//Nestor Marin Gomez
//A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct tSol {
    int rondaAct;
    int contPartidos;
    bool jugado;

};

// función que resuelve el problema
tSol resolver(const vector<string>& v, int ini, int fin, int ronda) {
    
    if (ini + 2 == fin) {//vector dos elementos
        if (v[ini] == "NP" && v[ini + 1] == "NP") {
            return {1,0,false };
        }
        else if (v[ini] == "NP" || v[ini + 1] == "NP") {
            return { 1,0,true };
        }
        else return { 1,1,true };
    }
    else {//vector 3 o mas elementos
        int mitad = (ini + fin) / 2;

        tSol sIzq = resolver(v, ini, mitad, ronda);

        tSol sDer = resolver(v, mitad, fin, ronda);

        if (sIzq.rondaAct +1 <= ronda) {
            return { sIzq.rondaAct + 1, sIzq.contPartidos + sDer.contPartidos + (sIzq.jugado && sDer.jugado), sIzq.jugado || sDer.jugado };
        }
        else {
            return{ sIzq.rondaAct + 1 ,sIzq.contPartidos + sDer.contPartidos,sIzq.jugado || sDer.jugado };
        }

    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, ronda;
    cin >> n;
    if (!std::cin)
        return false;
    cin >> ronda;

    vector<string> v(n);

    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
    int contRondas=0;
    tSol s = resolver(v, 0, v.size(), ronda);
    // escribir sol
    cout << s.contPartidos << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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