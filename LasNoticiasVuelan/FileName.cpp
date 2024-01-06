
/*@ <answer>
 *
 * Nombre y Apellidos: N�stor Mar�n Gomez DA42
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Grafo.h"
using namespace std;


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

class RedSocial {
private:
    vector<int> gruposAmigos;//vector de grupos de amigos
    vector<int> tamanos;//tama�os de los grupos
    vector <bool> visitados;//vector de booleanos

    int dfs(Grafo const &g, int v, int nGrupo) {
        visitados[v] = true;
        gruposAmigos[v] = nGrupo;
        int tamGrupo = 1;
        for (int w : g.ady(v)) {
            if (!visitados[w]) {
                tamGrupo += dfs(g, w, nGrupo);
            }
        }
        return tamGrupo;
    }

public: 
    RedSocial(Grafo const& g) : visitados(g.V(), false), gruposAmigos(g.V(), -1), tamanos(g.V(), -1)
    {
        int nGrupo = 0;
        for (int i = 0; i < g.V(); ++i) {
            if (!visitados[i]) {
                tamanos[nGrupo] = dfs(g, i, nGrupo);
                nGrupo++;
            }
        }
    }

    int amigosPersona(int persona) {
        return tamanos[gruposAmigos[persona]];
    }

};

bool resuelveCaso() {

    // leer los datos de la entrada
    int n, m;

    cin >> n;

    if (!std::cin)  // fin de la entrada
        return false;
    cin >> m;

    Grafo g(n);
    int nPersonas;

    for (int i = 0; i < m; i++)
    {
        cin >> nPersonas;
        if (nPersonas > 0) {
            int a1, a2;
            cin >> a1;
            for (int j = 0; j < nPersonas - 1; j++)
            {
                cin >> a2;
                g.ponArista(a1 - 1, a2 - 1);
            }
        }
    }

    RedSocial red(g);

    for (int i = 0; i < n; i++)
    {
        cout << red.amigosPersona(i) << " ";
    }
    cout << "\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
