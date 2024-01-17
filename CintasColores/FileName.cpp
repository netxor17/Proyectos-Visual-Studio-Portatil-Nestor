// Nestor Marin Gomez
// A79


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct tCinta {
    int l;
    char color;

    bool operator<(const tCinta& other) const {
        return l < other.l;
    }
};

// función que resuelve el problema
void particiones(vector<tCinta>& v, int& p, int& q) {//parametros por referencia a modificar
    p = 0; q = v.size() - 1; int k = 0;
    while (k <= q) {//mientras el iterador no se pase
        if (v[k].color == 'v') ++k;//si es rojo,aumento iterador
        else if (v[k].color == 'a') {//si es azul
            swap(v[p], v[k]);//intercambio
            ++p;
            ++k;
        }
        else {
            swap(v[q], v[k]);//intercambio
            --q;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nCintas;
    cin >> nCintas;
    if (!std::cin)
        return false;

    vector<tCinta> v(nCintas);
    for (int i = 0; i < nCintas; ++i) {
        cin >> v[i].color;
        cin >> v[i].l;
    }

    int p, q;//parametros por referencia para inicios de particiones
    
    particiones(v, p, q);//calculo las particiones

    sort(v.begin(), v.begin() + p);//primer tercio 0 a p
    sort(v.begin() + p, v.begin() + 1 + q);//segundo tercio p a q
    sort(v.begin() + 1 + q, v.end());//tercer tercio q a end


    //Muestro la solucion
    cout << "Azules: ";
    for (int i = 0; i < p; ++i) {
        cout << " "  << v[i].l;
    }
    cout << "\n";

    cout << "Verdes: ";
    for (int i = p; i <= q; ++i) {
        cout << " "  << v[i].l;
    }
    cout << "\n";    
    
    cout << "Rojas: ";
    for (int i = q+1; i < v.size(); ++i) {
        cout << " "  << v[i].l;
    }
    cout << "\n";

    // escribir sol


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