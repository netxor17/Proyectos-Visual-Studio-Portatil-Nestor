// IMPORTANTE
// Nombre del alumno: Néstor Marín Gómez
// Usuario del juez: A80

// Las torres del desierto

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

enum Direccion { Norte, Sur, Este, Oeste };

class Desierto {
private:
    unordered_map<string, pair<int, int>> mapaTorres;
    unordered_map<int, map<int,string >> coordenadasX;//mapas siempre con claves simples
    unordered_map<int, map<int, string >> coordenadasY;//mapas siempre con claves simples

    //Coste constante, solo se inserta 
    void anadir(const string &n, int x, int y) {
        if (mapaTorres.count(n)) {
            throw domain_error("Torre ya existente");
        }
        if((coordenadasX.count(x) && coordenadasX.at(x).count(y)) ||
                (coordenadasY.count(y) && coordenadasY.at(y).count(x))) {
            throw domain_error("Posicion ocupada");
        }
        else {
            mapaTorres.insert({ n, { x,y }});
            coordenadasX[x][y] = n;
            coordenadasY[y][x] = n;
        }
    }

    //Coste log(n) porque llama a erase
    void elimina(const string &nombre) {
        if (mapaTorres.count(nombre) == 0) {
            throw domain_error("Torre no existente");
        }
        else {
            pair<int, int> c = mapaTorres.at(nombre);
            coordenadasX.at(c.first).erase(c.second);
            coordenadasY.at(c.second).erase(c.first);
            mapaTorres.erase(nombre);
        }
    }
    //Coste constante porque solo llamo a at y count
    pair<int, int> pos(const string &n) {
        if (mapaTorres.count(n) == 0) {
            throw domain_error("Torre no existente");
        }
        else {
            return mapaTorres.at(n);
        }
    }

    //Coste O(1) por solo llamar a count y at
    pair<bool, string> en_pos(int x, int y) {
        if (coordenadasX.count(x) && coordenadasX.at(x).count(y)) {
            string n = coordenadasX.at(x).at(y);
            return { true,n };
        }
        else {
            return{ false,""};
        }
    }

    string cercana(const string &n, const Direccion &d) {
        if (mapaTorres.count(n) == 0) {
            throw domain_error("Torre no existente");
        }
        pair<int, int> c = mapaTorres.at(n);
        if (d == Sur || d == Norte) {
            auto& it = coordenadasX.at(c.first);
            if (d == Sur) {
                auto it2 = it.lower_bound(c.second);
                if (it2 != it.begin()) {
                    --it2;
                    return it2->second;
                }
            }
            else{
                auto it3 = it.upper_bound(c.second);
                if (it3 != it.end()) {
                    return it3->second;
                }
            }
        }
        else {
            if (coordenadasY.count(c.second)) {
                auto& itCol = coordenadasY.at(c.second);
                if (d == Oeste) {
                    auto it4 = itCol.lower_bound(c.first);
                    if (it4 != itCol.begin()) {
                        it4--;
                        return it4->second;
                    }
                }
                else {
                    auto it5 = itCol.upper_bound(c.first);
                    if (it5 != itCol.end()) {
                        return it5->second;
                    }
                }
            }
        }
        throw domain_error("No hay torres en esa direccion");
    }

    // Aqui el código del alumno

public:
    void anyadir_torre(const string& n, int x, int y) {
        anadir(n, x, y);
    }
    void eliminar_torre(const string &nombre) {
        elimina(nombre);
    }

    pair<int,int> posicion(const string &nombre) {
        return pos(nombre);
    }
    pair<bool, string> torre_en_posicion(int x, int y) {
        return en_pos(x, y);
    }

    string torre_mas_cercana(string const &nombre, Direccion const &dir) {
        return cercana(nombre, dir);
    }

};

// Transforma un string en el tipo enumerado Direccion
// Para la llamada a la función torre_mas_cercana
Direccion calculaDir(std::string const& d) {
    if (d == "Sur") return Sur;
    else if (d == "Norte") return Norte;
    else if (d == "Este") return Este;
    else return Oeste;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    std::cin >> op; // lectura del nombre de la operacion
    if (!std::cin) return false;
    Desierto d;
    while (op != "FIN") { // Lectura de todas las operaciones
        try {
            if (op == "anyadir_torre") {
                std::string nombre; int x, y;
                std::cin >> nombre >> x >> y;
                d.anyadir_torre(nombre, x, y);
            }
            else if (op == "eliminar_torre") {
                std::string nombre;
                std::cin >> nombre;
                d.eliminar_torre(nombre);
            }
            else if (op == "posicion") {
                std::string nombre;
                std::cin >> nombre;
                std::pair<int, int> sol = d.posicion(nombre);
                std::cout << sol.first << ' ' << sol.second << '\n';
            }
            else if (op == "torre_en_posicion") {
                int x, y; std::cin >> x >> y;
                std::pair<bool, std::string> sol = d.torre_en_posicion(x, y);
                if (sol.first)
                    std::cout << "SI " << sol.second << '\n';
                else std::cout << "NO\n";
            }
            else {
                std::string nombre; std::string dir;
                std::cin >> nombre >> dir;
                std::string sol = d.torre_mas_cercana(nombre, calculaDir(dir));
                std::cout << sol << '\n';
            }
        }
        catch (std::domain_error const& e) {
            std::cout << e.what() << '\n';
        }
        std::cin >> op;
    }
    std::cout << "---\n";
    return true;

}


int main() {

#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso());//Resolvemos todos los casos


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}


