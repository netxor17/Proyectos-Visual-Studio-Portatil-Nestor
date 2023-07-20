
#ifndef REPARACION_H
#define REPARACION_H
#include <string>
#include <vector>

struct tReparacion;
struct tTecnico;

using namespace std;

typedef vector<tReparacion> tListaReparaciones; //vector de reparaciones

typedef vector<tTecnico> tListaTecnicos; // lista de tecnicos (3)

struct tTecnico
{
	std::string nombre;
	int numReparaciones = 0;
	bool reparaAhora = false;
	tListaReparaciones reparaciones;
};

 struct tMovil
{
	string IMEI;
	string fallo;
	string modelo;
};

 struct tReparacion
{
 	long int idReparacion;
	tTecnico tecnicoAsociado;
	tMovil movilAsociado;
	float precioPieza;
	float precioReparado;
	string nombreCliente;
};










#endif