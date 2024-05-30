//******************************************************
// IMPORTANTE
// NOMBRE Y APELLIDOS DEL ALUMNO:
// USUARIO DEL JUEZ DE ESTE EXAMEN:
// LABORATORIO Y PUESTO:
//******************************************************

// Explicaci�n de la representaci�n empleada. 






// Indicar el coste de cada m�todo en un comentario al principio del m�todo.



#include <iostream>
#include <fstream>
#include <string> 
#include <stdexcept>
#include <vector> 
#include <list>

using namespace std;
// a�ade las librer�as de la STL que necesites

using mesa = int;
using plato = std::string;

// Elige el tipo representante adecuado para el TAD restaurante e
// implementa sus operaciones. Puedes a�adir m�todos o funciones privadas
// si lo consideras conveniente. Justifica la elecci�n de los tipos y el
// coste de las operaciones.

class restaurante {
    struct infoMesa{
        list<plato> listaPlatos;

    };
    // escribe aqu� los atributos privados


public:
    restaurante() {}

    void nueva_mesa(int num) {



    }

    void nuevo_pedido(int mesa, const std::string& plato) {




    }

    void cancelar_pedido(int mesa, const std::string& plato) {





    }

    std::pair<int, std::string> servir() {






    }

    std::vector<std::string> que_falta(int mesa) const {







    }
};


// No modificar el c�digo a partir de aqui.
// Entrada y salida de datos

bool resuelveCaso() {

    restaurante r;
    std::string op;
    std::cin >> op;
    if (!std::cin) return false;

    while (op != "FIN") {
        try {
            if (op == "nueva_mesa") {
                int num;
                std::cin >> num;
                r.nueva_mesa(num);
            }
            else if (op == "nuevo_pedido") {
                int mesa;
                std::string plato;
                std::cin >> mesa >> plato;
                r.nuevo_pedido(mesa, plato);

            }
            else if (op == "cancelar_pedido") {
                int mesa;
                std::string plato;
                std::cin >> mesa >> plato;
                r.cancelar_pedido(mesa, plato);
            }
            else if (op == "servir") {
                auto [mesa, plato] = r.servir();
                std::cout << plato << ' ' << mesa << '\n';
            }
            else if (op == "que_falta") {
                int mesa;
                std::cin >> mesa;
                std::vector<std::string> sol = r.que_falta(mesa);
                std::cout << "En la mesa " << mesa << " falta:\n";
                if (sol.size() > 0) {
                    std::cout << "  " << sol[0] << '\n';
                    for (int i = 1; i < sol.size(); ++i)
                        std::cout << "  " << sol[i] << '\n';
                }
            }
        }
        catch (std::domain_error& e) {
            std::cout << "ERROR: " << e.what() << "\n";
        }

        std::cin >> op;
    }
    std::cout << "---\n";

    return true;
}


int main() {

#ifndef DOMJUDGE
    std::ifstream in("sample3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    while (resuelveCaso());

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

