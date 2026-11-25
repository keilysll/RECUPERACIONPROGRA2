#include "Descarga.h"

Descarga::Descarga(int id, int megas, int fecha):Detalle(id,fecha)
{
	this->megas = megas;
}

Descarga::~Descarga()
{
}

string Descarga::toJson()
{
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"fecha\":"<<fecha<<",\"tipo\":\"descarga\"}";
	return ss.str();
}

int Descarga::getCantidad()
{
	return megas;
}

string Descarga::getTipo()
{
	return "la descarga ";
}
