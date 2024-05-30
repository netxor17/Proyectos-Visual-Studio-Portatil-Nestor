//******************************************************
// Galeria de arte

#include <iomanip>
#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map> 
#include <list> 
#include <vector> 
#include <set> 
#include <assert.h>
#include <fstream>

using namespace std;

// Se utiliza un tipo artista y un tipo obra
using artista = std::string;
using obra = std::string;

// En una lista se guardan las obras en el orden en que van llegando a la galería, para poder resolver el metodo obras_por_antiguedad
// En un unordered_map con clave obra se guarda la informacion relativa a 
// las obras: artista, precio y un iterador de la posicion de la obra en la
// lista de obras. El iterador se utiliza para poder eliminar la obra de la lista de obras en tiempo constante cuando se realiza la venta.
// En un unordered_map con clave artista se guarda el total de las ventas del artista.
// Para obtener los artistas que han vendido obras por una cantidad mayor se
// guardan los artistas con el número máximo de ventas en un set y en un
// entero la cantidad mayor vendida por ellos. Cuando un artista vende obras
// por un importe mayor al máximo, este se modifica y se eliminan del
// conjunto todos los artistas que hubiese, ya que habrán vendido obras por
// una cantidad menor. Se utiliza un conjunto con orden porque el método
// mas_vendidos indica que los artistas que mas han vendido se deben mostrar
// por orden alfabetico
class galeriaArte {
    std::list<obra> t_lista_obras; // lista de las obras de la galeria por antiguedad
    struct info_obras{
        int precio;
        artista pintor;
        std::list<obra>::iterator it_lista;
    };
    std::unordered_map<obra, info_obras> t_obras; // obras y su informacion
    std::unordered_map<artista,int> t_artistas; // Nombre del artista y precio total vendido
    std::set<artista> mas_vendido; // artistas que han vendido por un importe mayor
    int cant_mas_vendida; // Cantidad vendida por los artistas que mas han vendido
public:
    galeriaArte():cant_mas_vendida(0) {} // Inicializa la cantdad mas vendida
    
    // Da de alta una obra en la galeria
    // Coste constante, ya que los metodos count e insert sobre tablas no
    // ordenadas tienen coste constante y añadir a una lista por el final
    // tiene coste constante
    void nueva_obra(obra const& c, artista const& a, int p) {
        if (t_obras.count(c) == 0) { // la obra no esta dada de alta
            // La añado a la lista por antiguedad
            t_lista_obras.push_back(c);
            // Lo añado a la tabla de obras y artistas
            t_obras.insert({c,{p,a,--t_lista_obras.end()}});
            // Añado a la tabla de artistas si no está
            t_artistas.insert({a,0});
        }
        else throw std::invalid_argument("Obra ya en la galeria");
    }
    
    // Venta de una obra
    // Coste lineal en el numero de artistas que han vendido el valor maximo
    //(en el caso peor todos los artistas) 
    // si se encuentra un artista que ha vendido por un importe mayor, debido
    // a la operación clear sobre el conjunto.
    // Si se encuentra un artista que ha vendido la cantidad máxima el coste
    // es logarítmico en el número de artistas que han vendido la cantidad máxima debido a la operación de añadir al conjunto el artista.
    // Coste constante en los otros casos.
    void venta_obra (obra const& c) {
        // Busca la obra en la tabla de obras, y obtiene un iterador
        auto it_obras = t_obras.find(c);
        if (it_obras == t_obras.end()) throw std::invalid_argument("Obra no existente");
        else {
            // elimina la obra de la lista usando el iterador de la tabla de obras
            t_lista_obras.erase(it_obras->second.it_lista);
            // suma el importe vendido al artista
            auto artist = t_artistas.find(it_obras->second.pintor);
            artist->second += it_obras->second.precio;
            // Comprueba si pasa a ser el mas vendido
            if (mas_vendido.empty() || artist->second > cant_mas_vendida) { 
                mas_vendido.clear(); // Un artista ha vendido mas que los que ya había, se eliminan
                mas_vendido.insert(artist->first); // Se añade el artista al conjunto
                cant_mas_vendida = artist->second; // Se actualiza la cantidad mas vendida
            }
            else if (artist->second == cant_mas_vendida){
                // El artista ha vendido el mismo importe que otros, se añade al conjunto
                mas_vendido.insert(artist->first);
            }
            // elimina la obra de la tabla de obras, ya que se ha vendido
            t_obras.erase(it_obras);
        }
    }
    
    // Obtiene un vector con los artistas que mas han vendido. 
    // Coste lineal en el número de artistas que han vendido por un importe 
    // maximo, debido a que se copian dichos artistas en el vector
    std::vector<artista> mas_vendidos() {
        std::vector<artista> v;
        for (auto n : mas_vendido) 
            v.push_back(n);
        return v;
    }
    
    // Obtiene un vector con las k obras que llevan mas tiempo en la galeria
    // Coste el minimo entre las k obras pedidas y el número de obras de la galeria, debido a que se copian dichas obras en el vector
    std::vector<obra> obras_por_antiguedad(int k) {
        std::vector<obra> sol;
        int i = 0; 
        std::list<obra>::iterator it = t_lista_obras.begin(); // Se recorre la lista de obras por antiguedad. Las mas antiguas se encuentran al comienzo de la lista
        while (i < k && it != t_lista_obras.end()) { // minimo entre el valor de k y el número de obras de la lista
            sol.push_back(*it);
            ++i; ++it;
        }
        return sol;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada    
    std::string op;
    std::cin >> op;
    if (!std::cin)
        return false;
    
    galeriaArte galeria;
    
    while (op != "FIN") {
        try {
            if (op == "nueva_obra") {
                obra c; artista a; int p;
                std::cin >> c >> a >> p;
                assert(p > 0);
                galeria.nueva_obra(c,a,p);
            }
            else if (op == "venta_obra") {
                obra c; 
                std::cin >> c;
                galeria.venta_obra(c);
            }
            else if (op == "mas_vendidos") {
                std::vector<artista> sol = galeria.mas_vendidos();
                std::cout << "Los artistas que mas han vendido son:\n";
                for (auto n : sol) 
                    std::cout << n << '\n';
            }
            else if (op == "obras_por_antiguedad") {
                int k; 
                std::cin >> k;
                assert (k > 0);
                std::vector<obra> v = galeria.obras_por_antiguedad(k);
                std::cout << "Obras mas antiguas en la galeria:\n";
                for (obra o : v) std::cout  << o << '\n';
            }
        }
        catch(std::invalid_argument& e) {
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
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    while (resuelveCaso());

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
