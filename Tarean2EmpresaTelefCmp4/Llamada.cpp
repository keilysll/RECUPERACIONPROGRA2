#include "Llamada.h"

Llamada::Llamada(int id, int fecha, int duracionLlamada):Detalle(id,fecha)
{
	this->duracionLlamada = duracionLlamada;
}

Llamada::~Llamada()
{
}

int Llamada::getDuracion()
{
	return duracionLlamada;
}

string Llamada::toJson()
{
	stringstream ss;
	ss << "{\"id\":"<<id<<",\"fecha\":"<<fecha<<",\"minutos\":"<<duracionLlamada<<",\"tipo\":\"llamada\"}";
	return ss.str();
}

int Llamada::getCantidad()
{
	return duracionLlamada;
}

string Llamada::getTipo()
{
	return "llamada ";
}

