// Nestor Marin Gomez .....
// A79 ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct tZona //estructura para cada zona de playa
{
    string idEdificio;
    int alturaEdificio;
    int alturaPisoEnVenta;
};

/* función que resuelve el problema
 * Especificacion:
 
	P: {datos.size() > 0}

	resolver(const vector<tZona> &datos) dev vector<string> solucion

	Q: { solucion = Paratodo w: 0 <= w < solucion.size: solucion[w] = (Existe k: 0 <= k < v.size: v[k])
	^ Paratodo j : 0 <= j < datos.size ^ tieneVista(datos,j): datos[j];
	}

    donde tieneVista(datos,i): Paratodo  k : i < k < v.size: datos[i].alturaPisoEnVenta > datos[k].alturaEdificio
    
	Coste de la funcion:
		El coste de la funcion es lineal en el numero de elementos del vector.
		Dentro del while se compararian en el caso peor n veces si los pisos en venta son mayor que el maximo, y si el edificio es mayor que el maximo
		por lo que el coste es de O(n)
*/
vector<string> resolver(const vector<tZona> &datos) {
    vector<string> solucion;
    int primeraLinea = datos.size() - 1; //primera linea de playa
	int max = datos[primeraLinea].alturaEdificio;//edificio con altura maxima inicial

    if (datos[primeraLinea].alturaPisoEnVenta >= 0) solucion.push_back(datos[primeraLinea].idEdificio); //el piso de la primera linea de playa es positivo

    int interior = primeraLinea - 1; //me meto hacia el interior
    
    while(interior >= 0) //siga habiendo 
    {
        if (datos[interior].alturaPisoEnVenta > max) solucion.push_back(datos[interior].idEdificio);//el piso en venta tiene vistas al mar

        if(datos[interior].alturaEdificio > max) //si el edificio es mas alto
        {
            max = datos[interior].alturaEdificio; //actualizo
        }
        --interior; //me meto mas al interior
    }
        
        
        return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nCasos;
    string idEdificio;
    int alturaEdificio;
    int alturaPiso;
    cin >> nCasos;
    if (nCasos ==0)
        return false;

    vector<tZona> v(nCasos);

    for (int i = 0; i < v.size(); ++i) {
        cin >> idEdificio;
        v[i].idEdificio = idEdificio;
        cin >> alturaEdificio;
        v[i].alturaEdificio = alturaEdificio;
        cin >> alturaPiso;
        v[i].alturaPisoEnVenta = alturaPiso;
    }

    vector <string> sol;
	sol = resolver(v);

    // escribir sol
    if (sol.size() == 0) {
        cout << "Ninguno";
    }
    else
    {
        cout << sol.size() << endl;
        for (int i = 0; i < sol.size(); ++i)
        {
            cout << sol[i] << " ";
        }
    }
    cout << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
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
