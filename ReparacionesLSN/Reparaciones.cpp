#include <iostream>
#include <fstream>

#include "Reparacion.h"

// Función para guardar la información actualizada de los técnicos en un archivo de texto
void actualizaTecnicos(tListaTecnicos lista_tecnicos) {
    ofstream archivo("tecnicos.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de técnicos." << endl;
    }
    else {
        for (int i = 0; i < lista_tecnicos.size(); i++) {
            archivo << lista_tecnicos[i].nombre << " " << lista_tecnicos[i].numReparaciones << " " << lista_tecnicos[i].reparaAhora << endl;
        }
        archivo.close();
        cout << "La información de los técnicos ha sido guardada correctamente." << endl;
    }
}

int buscaTecnico(const tListaTecnicos l, string nombre)
{
    int i = 0;
    while (i < l.size() && l[i].nombre != nombre)
    {
        i++;
    }
    return i;
}

void agregarReparacion(tListaReparaciones& listaReparaciones)
{
    cout << "Vas a anadir una nueva reparacion a la lista \n";
    cout << "Estas segur@ de que quieres anadir una nueva reparacion? \n";
    cout << "S/N" << endl;
    char c;
    string numSerie;
    string descripcion;
    string nombreCliente;
    string modeloDispositivo;
    string nombreTecnico;
    tReparacion nuevaReparacion;
    tListaTecnicos tecnicos;


    cin >> c;
    if (c == 'S' || c == 's')
    {
        int opcion;
        do {
            cout << "Introduce los datos de la reparacion: \n";
            cout << "1. Introducir numero de serie" << endl;
            cout << "2. Introducir descripción del problema" << endl;
            cout << "3. Introducir nombre del cliente" << endl;
            cout << "4. Introducir modelo del dispositivo" << endl;
            cout << "5. Introducir nombre del técnico asignado" << endl;
            cout << "6. Guardar reparación y salir" << endl;
            cout << "Seleccione una opción (1-7): ";
            cin >> opcion;
            switch (opcion) {
            case 1:
                cout << "Introduzca el número de serie: ";
                getline(cin >> ws, numSerie);
                if (!listaReparaciones.empty()) { // Verificamos si el vector no está vacío
                    listaReparaciones.back().movilAsociado.IMEI = numSerie;
                }
                else {
                    nuevaReparacion.movilAsociado.IMEI = numSerie; // Inicializamos el nuevo elemento si el vector está vacío
                }
                break;
            case 2:
                cout << "Introduzca la descripción del problema: ";
                getline(cin >> ws, descripcion);
                if (!listaReparaciones.empty()) { // Verificamos si el vector no está vacío
                    listaReparaciones.back().movilAsociado.fallo = descripcion;
                }
                else {
                    nuevaReparacion.movilAsociado.fallo = descripcion; // Inicializamos el nuevo elemento si el vector está vacío
                }
                break;
            case 3:
                cout << "Introduzca el nombre del cliente: ";
                getline(cin >> ws, nombreCliente);
                if (!listaReparaciones.empty()) { // Verificamos si el vector no está vacío
                    listaReparaciones.back().nombreCliente = nombreCliente;
                }
                else {
                    nuevaReparacion.nombreCliente = nombreCliente; // Inicializamos el nuevo elemento si el vector está vacío
                }
                break;
            case 4:
                cout << "Introduzca el modelo del dispositivo: ";
                getline(cin >> ws, modeloDispositivo);
                if (!listaReparaciones.empty()) { // Verificamos si el vector no está vacío
                    listaReparaciones.back().movilAsociado.modelo = modeloDispositivo;
                }
                else {
                    nuevaReparacion.movilAsociado.modelo = modeloDispositivo; // Inicializamos el nuevo elemento si el vector está vacío
                }
                break;
            case 5:
                cout << "Introduzca el nombre del técnico asignado: ";
                getline(cin >> ws, nombreTecnico);
                if (!listaReparaciones.empty()) { // Verificamos si el vector no está vacío
                    int indexTecnico = buscaTecnico(tecnicos, nombreTecnico);
                    listaReparaciones.back().tecnicoAsociado = tecnicos[indexTecnico];
                }
                else {
                    nuevaReparacion.tecnicoAsociado.nombre = nombreTecnico; // Inicializamos el nuevo elemento si el vector está vacío
                }
                break;
            case 6:
                if (!listaReparaciones.empty()) { // Verificamos si el vector no está vacío
                    listaReparaciones.push_back(nuevaReparacion); // Agregamos el nuevo elemento al final del vector
                }
                else {
                    listaReparaciones.push_back(nuevaReparacion); // Agregamos el nuevo elemento al final del vector
                }
                break;
            default:
                cout << "Opción inválida. Seleccione una opción válida (1-7)." << endl;
                break;
            }
        } while (opcion != 7); // Repetimos el bucle mientras no se seleccione la opción 7
        cout << "Reparación guardada. Saliendo del menú." << endl;
    }
    else
    {
        //no hago nada
    }
}



// Función para cargar la información de los técnicos desde un archivo de texto
tListaTecnicos cargaTecnicos() {
    tListaTecnicos lista_tecnicos;
    ifstream archivo("tecnicos.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de técnicos." << endl;
    }
    else {
        string nombre;
        int numReparaciones;
        bool reparaAhora;
        while (archivo >> nombre >> numReparaciones >> reparaAhora) {
            tTecnico tecnico = { nombre, numReparaciones, reparaAhora };
            lista_tecnicos.push_back(tecnico);
        }
        archivo.close();
    }
    return lista_tecnicos;
}

// Función para mostrar los datos de los técnicos
void mostrarTecnicos(tListaTecnicos lista_tecnicos) {
    cout << "Lista de tecnicos:" << endl;
    for (int i = 0; i < lista_tecnicos.size(); i++) {
        cout << "Nombre: " << lista_tecnicos[i].nombre << endl;
        cout << "Reparaciones realizadas: " << lista_tecnicos[i].numReparaciones << endl;
        if (lista_tecnicos[i].reparaAhora) {
            cout << "Disponible para reparar en este momento." << endl;
        }
        else {
            cout << "No disponible para reparar en este momento." << endl;
        }
        cout << endl;
    }
}

void menu(tListaReparaciones &l, const tListaTecnicos t)
{
	int opc;
    do {
        cout << "\n Menu de opciones:" << endl;
        cout << "\n1. Agregar una reparacion" << endl;
        cout << "\n2. Asignar una reparacion a un tecnico" << endl;
        cout << "\n3. Mostrar la lista de reparaciones" << endl;
        cout << "\n4. Mostrar la lista de tecnicos" << endl;
        cout << "\n5. Salir" << endl <<endl;
        cout << "\nIngrese su opcion: ";
        cin >> opc;
        cin.ignore(); // Ignoramos el salto de línea
        switch (opc) {
        case 1:
            agregarReparacion(l);
            break;
        case 2:
            //asignar_tecnico(lista_reparaciones);
            break;
        case 3:
            //mostrar_reparaciones(lista_reparaciones);
            break;
        case 4:
            mostrarTecnicos(t);
            break;
        case 5:
            cout << "Gracias por utilizar el programa." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
        }
    } while (opc != 4);
}


int main()
{
	tListaReparaciones listaReparaciones;
    tListaTecnicos tecnicos = cargaTecnicos();

    menu(listaReparaciones, tecnicos);
	system("pause");
	return 0;
}