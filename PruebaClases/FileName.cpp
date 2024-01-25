#include <iostream>
#include <fstream>
#include "MyClass.h"
using namespace std;

int main(){
	Persona persona1("Nestor", "Marin", "Gomez", 26, 174);

	persona1.getNombre();

	cout << persona1.getNombre() << "\n";
	cout << persona1.getAltura() << "\n";
	
	system("pause");
	return 0;
}