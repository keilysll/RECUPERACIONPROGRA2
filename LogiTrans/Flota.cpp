#include "Flota.h"

Flota::Flota(string nombre)
{
	this->nombre = nombre;
}

Flota::~Flota()
{
}

string Flota::getNombre()
{
	return nombre;
}

string Flota::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"vehiculos\":"<<vehiculos.toJson(Vehiculo::toJsonPtr)<<"}";
	return ss.str();
}

void Flota::operator+=(Vehiculo* v)
{
	vehiculos.registrar(v);
}

int Flota::costoTotalMantenimiento()
{
	int total = 0;
	for (int i = 0; i < vehiculos.getTam(); i++)
	{
		total = total + vehiculos[i]->costoMantenimiento();
	}
	return total;
}

void Flota::cargarCamion(string placa, int kg)
{
	Vehiculo* v = vehiculos.buscar(new Camion(placa));
		if (v == NULL)
			throw exception(("vehiculo no encontrado: " + placa).c_str());
		Camion* c = dynamic_cast<Camion*>(v);
		if (c == NULL)
		{
			throw exception(( placa + " no es un camion").c_str());
		}
		c->cargar(kg);
	
	
}
