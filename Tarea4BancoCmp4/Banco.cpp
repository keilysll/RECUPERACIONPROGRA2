#include "Banco.h"

Banco::Banco(string nombre, string direccion)
{
	this->nombre = nombre;
	this->direccion = direccion;
}

Banco::~Banco()
{
}

string Banco::getNombre()
{
	return nombre;
}

string Banco::getDireccion()
{
	return direccion;
}

string Banco::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"dirreccion\":\"" << direccion << "\",\"clientes\":"<<clientes.toJson(Cliente::toJsonPtr)<<"}";
	return ss.str();
}

void Banco::registrarCliente(string nombre, int telef)
{
	clientes.registrar(new Cliente(nombre,telef));
}

void Banco::registrarCredito(string nombre, Credito* c)
{
	Cliente* cl = clientes.buscar(new Cliente(nombre));
	cl->registrar(c);
}

void Banco::registrarPago(string nombre, int id, int fecha, int monto)
{
	Cliente* cl = clientes.buscar(new Cliente(nombre));
	cl->pagar(new Amortizacion(id, fecha, monto));
}

void Banco::registrarPago(string nombre, int id, int fecha)
{
	Cliente* cl = clientes.buscar(new Cliente(nombre));
	cl->pagar(new CuotaFija(id, fecha));
}
