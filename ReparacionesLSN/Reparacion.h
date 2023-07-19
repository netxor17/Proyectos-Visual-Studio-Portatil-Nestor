
#ifndef REPARACION_H
#define REPARACION_H
#include <string>
#include <vector>

using namespace std;

struct tTecnico
{
	std::string nombre;
	int numReparaciones = 0;
	bool reparaAhora = false;
};

 struct tMovil
{
	string IMEI;
	string fallo;
	string modelo;
};

 struct tReparacion
{
 	string idReparacion;
	tTecnico tecnicoAsociado;
	tMovil movilAsociado;
	float precioPieza;
	float precioReparado;
	string nombreCliente;
};


typedef vector<tReparacion> tListaReparaciones; //vector de reparaciones

typedef vector<tTecnico> tListaTecnicos; // lista de tecnicos (3)





#endif