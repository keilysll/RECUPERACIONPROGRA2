#include "Vehiculo.h"

Vehiculo::Vehiculo(string placa)
{
	this->placa = placa;
}

Vehiculo::~Vehiculo()
{
}

string Vehiculo::getPlaca()
{
	return placa;
}

string Vehiculo::toJsonPtr(Vehiculo* v)
{
	return v->toJson();
}

bool Vehiculo::operator==(Vehiculo* v)
{
	return placa == v->placa;
}

bool Vehiculo::operator==(Vehiculo& v)
{
	return placa == v.placa;
}


