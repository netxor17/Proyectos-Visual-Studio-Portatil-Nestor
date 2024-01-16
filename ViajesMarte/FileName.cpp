// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct tPersona {
    string nombre;
    int altura;
    bool operator<(const tPersona& p2)  const{
        return nombre < p2.nombre;
    }
};

// función que resuelve el problema
int particion(vector<tPersona>& v, int altura) {//para hacer dos partes un vector
    int p = 0, q = v.size() - 1;
    while (p <= q) {
        if (v[p].altura <= altura) ++p; //bajos
        else if (v[q].altura > altura) --q; //altos
        else {
            swap(v[p], v[q]);//intercambio
            ++p;
            --q;
        }
    }
    return p;//devuelvo donde empieza la segunda mitad
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, altura;
    cin >> n;
    if (!std::cin)
        return false;
    cin >> altura;
    vector<tPersona> personas(n);

    for (int i = 0; i < n; ++i) {
       cin >>  personas[i].nombre;
       cin >> personas[i].altura;
    }

    int p = particion(personas, altura);//quiero saber por donde he partido

    //ordeno cada parte de la salida de datos
    sort(personas.begin(), personas.begin()+p);//de inicio a mitad
    sort(personas.begin()+p, personas.end());//de mitad a fin


    // escribir sol
    cout << "Bajos: ";
    if (p > 0) cout << personas[0].nombre;
    for (int i = 1; i < p; ++i) {
        cout << " " << personas[i].nombre;
    }
    cout << "\n";

    cout << "Altos: ";
    if (p < personas.size()) cout << personas[p].nombre;
    for (int i = p+1; i < personas.size(); ++i) {
        cout << " " << personas[i].nombre;
    }
    cout << "\n";
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