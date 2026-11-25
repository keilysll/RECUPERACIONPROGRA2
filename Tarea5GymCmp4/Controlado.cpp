#include "Controlado.h"

Controlado::Controlado(string id):Grupo(id)
{
}

Controlado::~Controlado()
{
}

string Controlado::toString()
{
	stringstream ss;
	ss << "{\"id\":\"" << id << "\",\"inscritos\":" << socios.toJson(Socio::toStringPtr);
	if (sesiones.getTam() > 0)
		ss << ",\"sesiones\":" << sesiones.toJson(Sesion::toStringPtr);
	ss <<"}";
	return ss.str();
}

void Controlado::registrarAsistente(int ci, int fecha)
{
	Sesion* s = sesiones.buscar(new Sesion(fecha));
	Socio* socio = socios.buscar(new Socio(ci));
	if (socio == NULL)
	{
		Socio* so = SingletonSocios::getInst().getSocios()->buscar(new Socio(ci));
		throw exception(("El socio " + so->getNombre() + " no esta inscrito").c_str());
	}
	s->registrarAsistente(socio);
	
}

void Controlado::registrarSesion(int fecha)
{
	sesiones.registrar(new Sesion(fecha));
}
