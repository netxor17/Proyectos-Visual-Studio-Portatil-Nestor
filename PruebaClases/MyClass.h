#ifndef MYCLASS_H
#define MYCLASS_H
#include <string>

using namespace std;

class Persona {
public:

	Persona() {}
	Persona(string n, string a1, string a2, int e, int a) : nombre(n), apellido1(a1), apellido2(a2), edad(e), altura(a) {}

	string getNombre() const {
		return this->nombre;
	}

	int getAltura() const {
		return this->altura;
	}

private:
	string nombre, apellido1, apellido2;
	int edad, altura;

};

#endif // !MYCLASS_H




