#include "Grupo.h"

Grupo::Grupo(string id)
{
	this->id = id;
}

Grupo::~Grupo()
{
}

string Grupo::getId()
{
	return id;
}

string Grupo::toString()
{
	stringstream ss;
	
	ss << "{\"id\":\"" << id << "\",\"inscritos\":" << socios.toJson(Socio::toStringPtr) << "}";
	return ss.str();
}

string Grupo::toStringPtr(Grupo* g)
{
	return g->toString();
}

void Grupo::inscribir(int idSocio)
{
	Socio* s = SingletonSocios::getInst().getSocios()->buscar(new Socio(idSocio));
	socios.registrar(s);
}

