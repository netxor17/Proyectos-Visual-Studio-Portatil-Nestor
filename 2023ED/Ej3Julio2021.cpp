#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <map>
#include <list>
#include <vector>
#include <set>

//#include "Juego.h"
using namespace std;
bool resuelveCaso();
int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
		while (resuelveCaso());
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
using jugador = string;
using puntos = int;
using region = string;
using numCaballeros = int;
struct tInfo {
	string predominante;
	unordered_map<jugador, numCaballeros> jugadores;
	int maxcaballeros = 0;

};

class Juego {
private:

	unordered_map<jugador,puntos> jugadores;
	unordered_map<region,tInfo> regiones;
	set<region> disputa;
	

	public:
			void anyadir_jugador(jugador jug) {
				if (jugadores.count(jug)) {
					throw domain_error("Jugador existente");

				}
				jugadores[jug] = 0;
			}

			void colocar_caballero(jugador jug, region reg) {
				if (!jugadores.count(jug)) {
					throw domain_error("Jugador inexistente");

				}
				if (!regiones.count(reg)) {
					regiones[reg].jugadores[jug]++;
					regiones[reg].predominante = jug;
					regiones[reg].maxcaballeros = 1;
					jugadores[jug]++;
				}
				else {
					regiones[reg].jugadores[jug]++;
					int caballeros = regiones[reg].jugadores[jug];
					if (regiones[reg].maxcaballeros < caballeros) {
						if (!disputa.count(reg)) {
							jugadores[regiones[reg].predominante]--;
						}
						disputa.erase(reg);
						regiones[reg].predominante = jug;
						regiones[reg].maxcaballeros = caballeros;
						jugadores.at(jug)++;
					}
					else if(caballeros == regiones[reg].maxcaballeros) {
						if (!disputa.count(reg)) {
							disputa.insert(reg);
							jugadores[regiones[reg].predominante]--;
						}
					}
				}
				
			}

			int puntuacion(jugador jug) {
				if (!jugadores.count(jug)) {
					throw domain_error("Jugador inexistente");

				}
				return jugadores.at(jug);
				
			}

			vector<region> regiones_en_disputa() {
				vector<region> qf;
				for (auto region : disputa) {
					qf.push_back(region);
				}
				return qf;
			}
			
			void expulsar_caballeros(region reg) {
				if (regiones.count(reg) && regiones[reg].jugadores.size() > 0) {
					if (!disputa.count(reg)) {
						jugadores[regiones[reg].predominante]--;
					}
					regiones[reg].jugadores.clear();
				}else{
					throw domain_error("Region vacia");
				}
			}
};
// Resuelve un caso
// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso() {
	string orden, jug, region;
	cin >> orden;
	if(!std::cin)
		return false;
	Juego g;
	while (orden != "FIN") {
		try
		{
			if (orden == "anyadir_jugador") {
				cin >> jug;
				g.anyadir_jugador(jug);
			}
			else if (orden == "colocar_caballero") {

				cin >> jug >> region;
				g.colocar_caballero(jug, region);
			}
			else if (orden == "puntuacion") {
				cin >> jug;
				int punt = g.puntuacion(jug);
				cout << "Puntuacion de " << jug << ": " << punt <<
				"\n";
			}
			else if (orden == "regiones_en_disputa") {
				vector<string> v = g.regiones_en_disputa();
				cout << "Regiones en disputa:\n";
				for (string s : v) {
					cout << s << "\n";
				}
			}
			else if (orden == "expulsar_caballeros") {
				cin >> region;
				g.expulsar_caballeros(region);
			}
			else
				std::cout << "OPERACION DESCONOCIDA\n";
			}
		catch (std::domain_error e) {
			std::cout << "ERROR: " << e.what() << "\n";
		}
			std::cin >> orden;
	}
		std::cout << "---\n";
	return true;
}
