#include "Telefonica.h"

Telefonica::Telefonica(string nombre, string direc)
{
	this->nombre = nombre;
	this->direc = direc;
}

Telefonica::~Telefonica()
{
}

string Telefonica::getNombre()
{
	return nombre;
}

string Telefonica::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"dirreccion\":\"" << direc << "\",\"clientes\":"<<usuarios.toJson(Usuario::toJsonPtr)<<"}";
	return ss.str();
}

void Telefonica::registrarCliente(string nombre, int saldo)
{
	usuarios.registrar(new Usuario(nombre, saldo));
}

void Telefonica::registrarPaquete(string nombre, Paquete* p)
{
	Usuario* u = usuarios.buscar(new Usuario(nombre));
	u->registrar(p);
}

void Telefonica::registrarLlamada(string nombre, int id, int fecha, int duracion)
{
	Usuario* u = usuarios.buscar(new Usuario(nombre));
	u->ejecutarAccion(new Llamada(id,fecha,duracion));
}

void Telefonica::registrarSMS(string nombre, int id, int fecha, int megas)
{
	Usuario* u = usuarios.buscar(new Usuario(nombre));
	u->ejecutarAccion(new Descarga(id, megas,fecha));
}
