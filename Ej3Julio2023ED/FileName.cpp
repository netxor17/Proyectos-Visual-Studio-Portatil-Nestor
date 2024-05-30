// ED Junio 2023
// Ejercicio 3

//**************************************************
//
// IMPORTANTE
//
// Nombre y Apellidos del alumno
// Usuario del juez en la prueba de hoy
//
//***************************************************


#include <iostream> 
#include <fstream> 
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stdexcept>
#include <list>

using namespace std;



class SistemaBatallas {
private:

    struct tV {
        int vida;
        int ataque;
        list<pair<string, int>>::iterator itV;
    };

    struct tH {
        int salud;
        map<string, int> ataques;
        list<pair<string, int>>::iterator itH;
    };
    // Codigo del alumno

    unordered_map<string, tV> villanos;
    unordered_map<string, tH> heroes;
    list<pair<string, int>> personajes;

public:
    void aparece_villano(std::string const& villano, int vida, int ataque) {
        if (villanos.count(villano)) {
            throw std::invalid_argument("Personaje ya existente");
        }
        villanos[villano] = { vida,ataque };
        personajes.push_back({ villano,vida });
        villanos.at(villano).itV = --personajes.end();



        // Codigo del alumno

    }

    void aparece_heroe(std::string const& heroe, int vida) {
        if (heroes.count(heroe)) {
            throw std::invalid_argument("Personaje ya existente");
        }
        map<string, int> ataques;
        heroes[heroe] = { vida, ataques };

        // Codigo del alumno
        personajes.push_back({ heroe,vida });
        heroes.at(heroe).itH = --personajes.end();


    }

    void aprende_ataque(std::string const& heroe, std::string ataque, int valor) {


        // Codigo del alumno
        if (heroes.count(heroe) == 0) {
            throw std::invalid_argument("Heroe inexistente");
        }

        if (heroes.at(heroe).ataques.count(ataque)) {
            throw std::invalid_argument("Ataque Repetido");
        }

        heroes.at(heroe).ataques[ataque] = valor;


    }

    std::vector<std::pair<std::string, int>> mostrar_ataques(std::string const& heroe) {
        if (heroes.count(heroe) == 0) {
            throw std::invalid_argument("Heroe inexistente");
        }

        vector<pair<string, int>> ataquesss;

        // Codigo del alumno
        for (auto ataque : heroes.at(heroe).ataques) {
            ataquesss.push_back({ ataque.first,ataque.second });
        }

        return ataquesss;
    }

    std::vector<std::pair<std::string, int>>  mostrar_turnos() {


        // Codigo del alumno
        vector<pair<string, int>> turnosvec;
        list<pair<string, int>> turnos2;
        // Codigo del alumno
        auto it = personajes.begin();
        while (it != personajes.end()) {
            turnosvec.push_back({ it->first,it->second });
            it++;
        }


        return turnosvec;



    }

    bool villano_ataca(std::string const& villano, std::string const& heroe) {
        bool sol = false;
        if (villanos.count(villano) == 0) {
            throw std::invalid_argument("Villano inexistente");
        }
        if (heroes.count(heroe) == 0) {
            throw std::invalid_argument("Heroe inexistente");
        }
        if (personajes.front().first != villano) {
            throw std::invalid_argument(" No es su turno");
        }
        else {
            heroes.at(heroe).salud -= villanos.at(villano).ataque;
            heroes.at(heroe).itH->second = heroes.at(heroe).salud;
            if (heroes.at(heroe).salud <= 0) {
                auto iterador = heroes.at(heroe).itH;
                personajes.erase(iterador);
                heroes.erase(heroe);
                sol = true;
            }
            pair<string, int> per = personajes.front();
            personajes.push_back(per);
            personajes.pop_front();
            villanos.at(villano).itV = --personajes.end();


        }
        // Codigo del alumno

        return sol;

    }

    bool heroe_ataca(std::string const& heroe, std::string const& ataque, std::string const& villano) {

        // Codigo del alumno
        bool sol = false;
        if (heroes.count(heroe) == 0) {
            throw std::invalid_argument("Heroe inexistente");
        }
        if (villanos.count(villano) == 0) {
            throw std::invalid_argument("Villano inexistente");
        }
        if (personajes.front().first != heroe) {
            throw std::invalid_argument("No es su turno");
        }
        if (heroes.at(heroe).ataques.count(ataque) == 0) {
            throw std::invalid_argument("Ataque no aprendido");
        }
        else {
            villanos.at(villano).vida -= heroes.at(heroe).ataques.at(ataque);
            villanos.at(villano).itV->second = villanos.at(villano).vida;

            if (villanos.at(villano).vida <= 0) {

                auto iterador = villanos.at(villano).itV;
                personajes.erase(iterador);
                villanos.erase(villano);
                sol = true;
            }
            pair<string, int> per = personajes.front();
            personajes.push_back(per);
            personajes.pop_front();
            heroes.at(heroe).itH = --personajes.end();

        }
        // Codigo del alumno
        return sol;
    }
};

bool resuelveCaso() {
    // leer los datos de la entrada

    std::string op;
    std::cin >> op;
    if (!std::cin)
        return false;

    SistemaBatallas sistema;

    while (op != "FIN") {

        try {

            if (op == "aparece_villano") {

                std::string villano; int vida, ataque;
                std::cin >> villano >> vida >> ataque;

                sistema.aparece_villano(villano, vida, ataque);

            }

            else if (op == "aparece_heroe") {

                std::string heroe; int vida;
                std::cin >> heroe >> vida;

                sistema.aparece_heroe(heroe, vida);

            }

            else if (op == "aprende_ataque") {
                std::string heroe; std::string ataque;
                int valor;
                std::cin >> heroe >> ataque >> valor;

                sistema.aprende_ataque(heroe, ataque, valor);
            }

            else if (op == "mostrar_ataques") {
                std::string heroe;
                std::cin >> heroe;
                std::vector<std::pair<std::string, int>> sol = sistema.mostrar_ataques(heroe);
                std::cout << "Ataques de " << heroe << '\n';
                for (int i = 0; i < sol.size(); ++i) {
                    std::cout << sol[i].first << ' ' << sol[i].second << '\n';
                }
            }

            else if (op == "mostrar_turnos") {
                std::vector<std::pair<std::string, int>> sol = sistema.mostrar_turnos();
                std::cout << "Turno:\n";
                for (int i = 0; i < sol.size(); ++i) {
                    std::cout << sol[i].first << ' ' << sol[i].second << '\n';
                }
            }

            else if (op == "villano_ataca") {
                std::string villano, heroe;
                std::cin >> villano >> heroe;
                bool sol = sistema.villano_ataca(villano, heroe);
                std::cout << villano << " ataca a " << heroe << '\n';
                if (sol) std::cout << heroe << " derrotado\n";
            }

            else if (op == "heroe_ataca") {
                std::string villano, ataque, heroe;
                std::cin >> heroe >> ataque >> villano;
                bool sol = sistema.heroe_ataca(heroe, ataque, villano);
                std::cout << heroe << " ataca a " << villano << '\n';
                if (sol) std::cout << villano << " derrotado\n";
            }
        }
        catch (std::invalid_argument& e) {

            std::cout << "ERROR: " << e.what() << "\n";
        }

        std::cin >> op;

    }

    std::cout << "---\n";

    return true;

}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to sample3.txt
#endif

    while (resuelveCaso()) {}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

