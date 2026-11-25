#include "SingletonSocios.h"

SingletonSocios::SingletonSocios()
{
}

SingletonSocios::~SingletonSocios()
{
}

SingletonSocios& SingletonSocios::getInst()
{
	static SingletonSocios inst;
	return inst;
}

string SingletonSocios::toString()
{
	socios.ordenar(Socio::OrdenarNombre);
	stringstream ss;
	ss << "{\"socios\":"<< socios.toJson(Socio::toStringPtr)<<"}";
	return ss.str();
}

ListaEnlazada<Socio>* SingletonSocios::getSocios()
{
	return &socios;
}

void SingletonSocios::registrar(Socio* s)
{
	socios.registrar(s);
}
