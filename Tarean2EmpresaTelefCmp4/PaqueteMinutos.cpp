#include "PaqueteMinutos.h"

PaqueteMinutos::PaqueteMinutos(int saldo):Paquete(saldo)
{
}

PaqueteMinutos::~PaqueteMinutos()
{
}

string PaqueteMinutos::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"minutos\",\"saldo minutos\":"<<saldo<<"}";
	return ss.str();
}
