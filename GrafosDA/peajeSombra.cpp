/*@ <answer>
 *
 * Nombre y Apellidos: N�stor Mar�n G�mez DA42 y Javier Parra Gonz�lez DA45
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#include "Grafo.h" // o los de las estructuras de datos de clase
#include <climits>
/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 Hemos creado un clase "Peaje" para representar el peaje que tendra que pagar tanto Alex y Lucas para llegar tanto al nodo intermedio y posteriomemte al trabajo.
 Los atributos de esta clase, son s el origen desde donde empezaran, y dem�s vectores dist, ant, visit.
 Utilizamos un recorrido en anchura porque necesitamos encontrar el camino minimo entre todos los vertices empezando en el origen

 Para resolver el ejercicio, en el resuelveCaso leemos todos los datos de entrada, posteriormente creamos el grafo.
 A continuaci�n, calculamos los caminos m�nimos que resultan de hacer el recorrido en anchura desde los siguientes or�genes (Lucas, Alex, Trabajo)
 Una vez consegudio estos valores, procedemos a calcular el m�nimo de la suma de  cada componente i�sima de los 3 vectores(dist1, dist2, tr).
 Y una vez conseguidi el m�nimo,  lo mostramos por pantalla.


 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

class Peaje {
private:
    std::vector<bool> visit; // visit[v] = �hay camino de s a v?
    std::vector<int> ant; // ant[v] = �ltimo v�rtice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s-v m�s corto
    int s;

    void bfs(Grafo const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
                    q.push(w);
                }
            }
        }
    }
public:
    Peaje(const Grafo& g, int s) : visit(g.V(), false),
        ant(g.V()), dist(g.V()), s(s) {
        bfs(g);
    }

    vector<int> distancia() {
        return dist;
    }
};


//Coste O( n + c + (3 * (v + c)) + n ) = O(n + c) = O(max(c,n))
bool resuelveCaso() {

    // leer los datos de la entrada
    int n, c, casa1, casa2, trabajo;
    cin >> n >> c >> casa1 >> casa2 >> trabajo;


    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g(n); //coste O(n)

    //coste O(c) siendo c el numero de aristas
    for (int i = 0; i < c; i++) {
        int ini, fin; cin >> ini >> fin;
        g.ponArista(ini - 1, fin - 1);
    }

    // resolver el caso posiblemente llamando a otras funciones
    //coste O(3 * (v + c)) siendo v en num de vertices y c en num de aristas
    Peaje c1(g, casa1 - 1);
    Peaje c2(g, casa2 - 1);
    Peaje t(g, trabajo - 1);


    vector<int> dist1 = c1.distancia(); // O(1)
    vector<int> dist2 = c2.distancia();// O(1)
    vector<int> tr = t.distancia();// O(1)


    //O(n)
    int mini = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int sum = tr[i] + dist1[i] + dist2[i];
        mini = min(sum, mini);
    }

    // escribir la soluci�n
    cout << mini << "\n";
    return true;
}




//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("peajeSombra.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}

