#include "Red.h"

Red::Red(string nombre)
{
	this->nombre = nombre;
}

Red::~Red()
{
}

string Red::getNombre()
{
	return nombre;
}

string Red::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"clientes\":"<<clientes.toJson(Cliente::toJsonPtr)<<"}";
	return ss.str();
}

void Red::operator+=(Cliente* c)
{
	Cliente tmp (c->getNombre());
	if (clientes.buscar(&tmp) != NULL)
			throw exception(("el cliente "+ c->getNombre() + " ya esta registrado").c_str());
	clientes.registrar(c);
	clientes.ordenar(Cliente::compararPorNombre);
}

void Red::registrarBono(string nombre, Bono* b)
{
	Cliente* c = clientes.buscar(new Cliente(nombre));
	if (c == NULL)
		throw exception(("cliente "+ nombre + " no encontrado").c_str());
	c->registrar(b);
}

void Red::registrarCarga(string nombre, Carga* c)
{
	Cliente* cl = clientes.buscar(new Cliente(nombre));
	if (cl == NULL)
		throw exception(("cliente " + nombre + " no encontrado").c_str());
	cl->cargar(c);
}

int Red::totalFacturado()
{
	int total = 0;
	for (int i = 0; i < clientes.getTam(); i++)
	{
		total = total + clientes[i]->totalFacturado();
	}
	return total;
}

string Red::clienteMayorConsumo()
{
	Cliente* mayor = clientes[0];
	for (int i = 0; i < clientes.getTam(); i++)
	{
		Cliente* c = clientes[i];
		if (c->totalKwh() > mayor->totalKwh())
		{
			mayor = c;
		}
	}

	return mayor->getNombre();
}

int Red::cantidadCargasRapidas()
{
	int cant = 0;
	for (int i = 0; i < clientes.getTam(); i++)
	{
		cant = cant + clientes[i]->cantidadCargasRapidas();
	}
	return cant;
}
