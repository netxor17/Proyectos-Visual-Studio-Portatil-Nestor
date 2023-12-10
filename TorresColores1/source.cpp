// Nestor Marin Gomez .....
// a79 ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

//typedef enum {azul,rojo,verde} tColores;

//Vector solucion: vector de enteros con tantas posiciones como altura tenga la torre
// y en cada posicion se va introduciendo un color

//Arbol de exploracion:
//  Ramas: colores (azul, rojo, verde)
//  Altura: altura de la torre

//Vector de marcas: vector de enteros que dice cuantas veces se ha puesto un color
 // este vector tendra solamente 3 posiciones, cada posicion es un color.

/*Tercera version*/


typedef enum {azul,rojo,verde} tColores;


struct tSol {
    bool haySolucion;
    std::vector<int> torre;
};


bool esValida(const std::vector<int>& piezasDisponibles, const std::vector<int>& contadorPiezasUsadas, const tSol& sol, int colorActual, int pos) {
    if (piezasDisponibles[colorActual] < 1 || (colorActual == verde && colorActual == sol.torre[pos - 1]) || (colorActual == verde && contadorPiezasUsadas[verde] + 1 > contadorPiezasUsadas[azul])) {
        return false; 

    }
    else {
        return true;

    }
}

// Función para escribir la solución
void escribirSolucion(const std::vector<int>& marcas, tSol& solucion) {
    if (marcas[rojo] > (marcas[azul] + marcas[verde])) {
        solucion.haySolucion = true;
        for (int color : solucion.torre) {
            switch (color) {
            case azul:
                std::cout << "azul ";
                break;
            case rojo:
                std::cout << "rojo ";
                break;
            case verde:
                std::cout << "verde ";
                break;
            }
        }
        std::cout << '\n';
    }
}

// Función principal para resolver el problema usando backtracking
void resolver(int altura, std::vector<int>& piezasDisponibles, int k, std::vector<int>& marcas, tSol& solucion) {
    for (int i = 0; i < 3; ++i) {
        if (esValida(piezasDisponibles, marcas, solucion, i, k)) { //solucion valida
            solucion.torre[k] = i;
            piezasDisponibles[i]--;
            marcas[i]++;//marco
            if (k == altura - 1) {
                escribirSolucion(marcas, solucion);
            }
            else {
                resolver(altura, piezasDisponibles, k + 1, marcas, solucion);
            }
            piezasDisponibles[i]++;//desmarco
            marcas[i]--;//desmarco
        }
    }
}

// Función para manejar un caso de prueba
bool resuelveCaso() {
    int altura;
    std::cin >> altura;

    if (altura == 0)
        return false;

    std::vector<int> piezasDisponibles(3, 0);

    for (int i = 0; i < 3; ++i) {
        std::cin >> piezasDisponibles[i];
    }

    tSol solucion;
    solucion.haySolucion = false;
    solucion.torre.resize(altura, -1);

    std::vector<int> marcas(3, 0);

    // La primera pieza es siempre roja
    solucion.torre[0] = rojo;
    piezasDisponibles[rojo]--;
    marcas[rojo]++;

    resolver(altura, piezasDisponibles, 1, marcas, solucion);

    if (!solucion.haySolucion) {
        std::cout << "SIN SOLUCION\n";
    }

    std::cout << '\n';

    return true;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

