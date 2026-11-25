#pragma once
#include"Vehiculo.h"
#include"Moto.h"
#include"Camion.h"
#include"ListaEnlazada.h"

class Flota
{
private:
	string nombre;
	ListaEnlazada<Vehiculo> vehiculos;
public:
	Flota(string nombre);
	~Flota();
	string getNombre();
	string toJson();
	void operator+=(Vehiculo* v);
	int costoTotalMantenimiento();
	void cargarCamion(string placa, int kg);
};

