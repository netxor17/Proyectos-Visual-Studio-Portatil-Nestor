#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

//Nestor Marin Gomez
//FAL-A76

/*
* Arbol de exploracion:
*   Ramas: las ramas son los los supermercados
*
*   Altura: el numero de productos que hay que comprar
* 
*   Vector solucion: vector con tamaño el numero de productos que hay que comprar, y cada elemento es un supermercado.
* 
* Tamaño de la solucion: 
*   El tamaño en este caso es la altura del arbol, que son el numero de productos que hay que comprar.
* 
*   En el caso peor el coste de la solucion es del orden de O(ramas^altura) = O(supermercados^productos) 
 */

void poda(const vector<vector<int>>& v, vector<int>&sumaMinimaProductos, int supermercados , int productos) {
    vector<int> minimosPrecios(v[0].size());
    for (int i = 0; i < productos; i++) {
        int min = v[0][i];
        for (int j = 0; j < supermercados; j++) {
            if (v[j][i] < min) {
                min = v[j][i];
            }
        }
        minimosPrecios[i] = min;
    }
    sumaMinimaProductos[productos - 1] = 0;
    for (int i = productos - 2; i > -1; i--) {
        sumaMinimaProductos[i] = sumaMinimaProductos[i + 1] + minimosPrecios[i + 1];
    }
}

// función que resuelve el problema
void resolverVA(const vector<vector<int>>& precios, int k, int& valorMejor, vector<int>& productosPorSupermercado, vector<int>& solMejor, vector<int>& sol, int supermercados, int productos, int coste, int min, const vector<int>& sumaMinimaProductos) {
    for (int i = 0; i < supermercados; i++) { //recorro las ramas (los supermercados) 
        sol[k] = i; //añado ese supermercado a la solucion
        if (productosPorSupermercado[i] < 3) { //si no he comprado mas de 3 veces
            //marco
            productosPorSupermercado[i]++;
            coste += precios[i][k];
            int estimacionCoste = coste + sumaMinimaProductos[k];
            if (estimacionCoste < valorMejor) {
                if (k == sol.size() - 1 && coste < valorMejor) {//si es el final y es mejor que la solucion actual, la cambio
                    valorMejor = coste;
                    solMejor = sol;
                }
                else {//si no 
                    if (valorMejor > estimacionCoste) {//veo si es viable seguir 
                        resolverVA(precios, k + 1, valorMejor, productosPorSupermercado, solMejor, sol, supermercados, productos, coste, min, sumaMinimaProductos); //aumento etapa
                    }
                }
            }
            //desmarco
            productosPorSupermercado[i]--;
            coste -= precios[i][k];
        }
    }

}

int minValor(const vector<vector<int>>& v, int productos, int supermercados, int sumaTotal, int minimo) {

    vector<int> sol(productos);//vector solucion
    vector<int> solMejor(productos);//vector con la solucion mejor
    vector<int> prodsPorSuper(supermercados);
    int coste = 0;
    int valorMejor = sumaTotal;
    vector<int> sumaMinimaProductos(productos);
    poda(v, sumaMinimaProductos, supermercados, productos);
    resolverVA(v, 0, valorMejor, prodsPorSuper, solMejor, sol, supermercados, productos, 0, minimo, sumaMinimaProductos);
    return valorMejor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int supermercados, productosuctos;
    cin >> supermercados >> productosuctos;
    vector<vector<int>> v(supermercados, vector<int>(productosuctos));
    int minimo = v[0][0];
    int suma = 0;
    for (int i = 0; i < supermercados; i++) {
        for (int j = 0; j < productosuctos; j++) {
            cin >> v[i][j];
            suma += v[i][j];
            if (v[i][j] < minimo) {
                minimo = v[i][j];
            }
        }
    }
    int sol = minValor(v, productosuctos, supermercados, suma, minimo);
    // escribir sol
    cout << sol << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("compraSemana.txt");
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