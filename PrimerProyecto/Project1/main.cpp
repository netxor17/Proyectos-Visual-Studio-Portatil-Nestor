#include <iostream>
#include <string>

//Ejercicio con linked list simples

using namespace std;


struct Nodo{
	int dato; //dato entero
	Nodo * nodoSiguiente; //puntero al siguiente nodo
};

Nodo* primero = NULL;

void insertaNodoAlPrincipio(int valor) //inserta un nodo al final de la lista
{
	Nodo* nuevo = new Nodo();
	nuevo->dato = valor;

	if(primero->nodoSiguiente==NULL)
	{
		primero = nuevo;
	}
	else
	{
		nuevo->nodoSiguiente = primero;
		primero = nuevo; //indico que el primer nodo de mi lista es el nuevo
	}
}

void insertaNodoAlFinal(int valor)
{
	Nodo* nuevo = new Nodo(); //el nodo nuevo a insertar
	nuevo->dato = valor; //le asigno valor
	nuevo->nodoSiguiente = NULL; //no apunta a nada

	if (primero == NULL) { //si esta la lista vacia
		primero = nuevo; //el primero apunta al nuevo
	}
	else
	{
		Nodo* p = primero; //nodo que va a iterar
		while (p->nodoSiguiente) { //mientras no sea el ultimo nodo
			p = p->nodoSiguiente;
		}
		p->nodoSiguiente = nuevo;
	}
}


void insertaNodoEnPosicion(int valor, int pos)
{
	Nodo* nuevo = new Nodo();
	nuevo->dato = valor;
	int cont = 0;
	Nodo* it = primero; //nodo que va a iterar
	while (cont < pos - 1 && it != NULL) {
		it = it->nodoSiguiente;
		cont++;
	}
	if (it != NULL) {
		Nodo* aux = it->nodoSiguiente;
		it->nodoSiguiente = nuevo;
		nuevo->nodoSiguiente = aux;
	}
}

void mostrarNodos()
{
	Nodo* p = primero;
	while (p->nodoSiguiente != NULL){
		cout << p->dato << "-> ";
		p = p->nodoSiguiente;
	}
	cout<< p->dato << endl;
}

int main() {
	insertaNodoAlFinal(4);
	insertaNodoAlFinal(5);
	insertaNodoAlFinal(3);
	insertaNodoAlPrincipio(41);
	insertaNodoAlPrincipio(57);
	insertaNodoAlPrincipio(1);
	insertaNodoEnPosicion(4000, 3);
	insertaNodoEnPosicion(5, 1);
	insertaNodoAlFinal(10);

	mostrarNodos();
	return 0;
}