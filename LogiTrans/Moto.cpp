#include "Moto.h"

Moto::Moto(string placa, int cilindrada):Vehiculo(placa)
{
	this->cilindrada = cilindrada;
}

Moto::~Moto()
{
}

int Moto::getCilin()
{
	return cilindrada;
}

string Moto::toJson()
{
	stringstream ss;
	ss << "{\"placa\":\""<<placa<<"\",\"tipo\":\"moto\",\"cilindrada\":"<<cilindrada<<"}";
	return ss.str();
}

int Moto::costoMantenimiento()
{
	return cilindrada * 0.5;
}
