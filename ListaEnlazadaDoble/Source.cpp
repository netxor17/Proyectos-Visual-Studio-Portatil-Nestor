#include <iostream>
#include <string>

using namespace std;

//Las listas enlazadas dobles tienen punteros al siguiente y al anterior nodo
//El primer nodo, su anterior es NULL, y el ultimo nodo, su siguiente es NULL

struct Nodo
{
	int dato; //dato entero
	Nodo* sig; //nodo siguiente
	Nodo* ant; //nodo anterior
};

Nodo* primero = NULL;


void mostrarNodos()
{
	if (primero == NULL)
	{
		cout << "La lista esta vacia" << endl;
		return;
	}
	Nodo* it = primero; //itero desde el primero
	while(it->sig) //mientras no sea el ultimo
	{
		cout << it->dato << " <-> ";
		it = it->sig;
	}
	cout << it->dato << endl; //muestro el ultimo

}

void insertarAlPrincipio(int valor)
{
	Nodo* nuevo = new Nodo();
	if (nuevo == NULL)
	{
		cout << "No se pudo crear el nuevo nodo" << endl;
		return;
	}
	nuevo->dato = valor;
	if(primero == NULL) //lista vacia
	{
		primero = nuevo; //el puntero del principio apunta al nuevo nodo
	}
	else
	{
		nuevo->sig = primero; 
		nuevo->ant = NULL;
		primero = nuevo; //actualizo el puntero de la primera pos
	}
}


void insertarAlFinal(int valor)
{
	Nodo* nuevo = new Nodo();
	nuevo->dato = valor;
	if (primero == NULL) //lista vacia
	{
		primero = nuevo; //el puntero del principio apunta al nuevo nodo
	}
	else
	{
		Nodo* it = primero;
		while(it->sig)
		{
			it = it->sig;
		}
		it->sig = nuevo;
		nuevo->ant = it;
	}
}


void insertaNodoEnPosicion(int valor, int pos)
{
	Nodo* nuevo = new Nodo();
	nuevo->dato = valor;

	if (pos <= 0) {
		// Insertar al principio de la lista sin eliminar el primer nodo
		insertarAlPrincipio(valor);
	}
	else {
		int cont = 0;
		Nodo* it = primero;

		while (cont < pos - 1 && it != NULL) {
			it = it->sig;
			cont++;
		}

		if (it == NULL) {
			cout << "La posicion no es valida" << endl;
			return;
		}

		Nodo* aux = it->sig;
		nuevo->sig = aux;
		nuevo->ant = it;
		it->sig = nuevo;

		if (aux != NULL) {
			aux->ant = nuevo;
		}
	}
}

int main()
{
	// Insertamos los nodos al principio y al final de la lista
	insertarAlPrincipio(30); // 30
	insertarAlPrincipio(2); // 2 -> 30
	insertarAlFinal(10); // 2 -> 30 -> 10
	insertarAlFinal(1000); // 2 -> 30 -> 10 -> 1000
	insertarAlFinal(500); // 2 -> 30 -> 10 -> 1000 -> 500


	// Insertamos el nodo con valor 5 en la primera posición de la lista
	insertaNodoEnPosicion(5, 0); // 5 -> 2 -> 30 -> 10 -> 1000 -> 500
	// Insertamos el nodo con valor 4000 en la tercera posición de la lista
	insertaNodoEnPosicion(4000, 2); // 5 -> 2 -> 4000 -> 30 -> 10 -> 1000 -> 500

	// Insertamos el nodo con valor 15 al principio de la lista
	insertarAlPrincipio(15); // 15 -> 5 -> 2 -> 4000 -> 30 -> 10 -> 1000 -> 500

	// Mostramos la lista resultante
	mostrarNodos(); // 15 <-> 5 <-> 2 <-> 4000 <-> 30 <-> 10 <-> 1000 <-> 500



	system("pause");
	return 0;
}