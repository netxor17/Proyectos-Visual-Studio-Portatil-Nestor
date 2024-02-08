#ifndef  FECHA
#define FECHA


#include <iostream>
#include <array>
#include <stdexcept>
#include <iomanip>


using namespace std;


class Fecha {
public:
	// Constructores
	Fecha() {}

	Fecha(int h, int m, int s) : horas(h), minutos(m), segundos(s) {
		if (h < 0 || h > HORAS_DIA) throw std::invalid_argument("Hora invalidas");
		else if (m < 0 || m > MINUTOS_SEGUNDOS || s<0 || s > MINUTOS_SEGUNDOS)
			throw std::invalid_argument("Hora invalida");
	}

	// operador de asignacion
	Fecha& operator =(Fecha const& other) {
		if (this != &other) {
			horas = other.horas; minutos = other.minutos; segundos = other.segundos;
		}
		return *this;
	}
	// consultoras
	int get_horas() const { return horas; }
	int get_minutos() const { return minutos; }
	int get_segundos() const { return segundos; }

	// operadores de comparacion
	bool operator<(Fecha const& f) const {
		if (horas < f.horas) return true;
		else if (horas == f.horas && minutos < f.minutos) return true;
		else if (horas == f.horas && minutos == f.minutos && segundos < f.segundos) return true;
		else return false;
	}
	bool operator==(Fecha const& f) const {
		return horas == f.horas && minutos == f.minutos && segundos == f.segundos;
	}
	bool operator<=(Fecha const& f) const {
		return *this < f || *this == f;
	}
	bool operator>(Fecha const& f) const {
		return !(*this <= f);
	}
	bool operator >= (Fecha const& f) const {
		return !(*this < f);
	}
private:
	const int HORAS_DIA = 24;
	const int MINUTOS_SEGUNDOS = 60;
	int horas, minutos, segundos;

};


inline std::ostream& operator<<(std::ostream& out, Fecha const& f) {
	out << setfill('0') << setw(2) << f.get_horas() << ':' << setfill('0') << setw(2)  << f.get_minutos() << ':' << setfill('0') << setw(2) << f.get_segundos();
	return out;
}

inline std::istream& operator >>(std::istream& in, Fecha& f) {
	int h, m, s;
	in >> h >> m >> s;
	f = Fecha(h, m, s);
	return in;
}

#endif // ! 
