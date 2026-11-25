#include "Cliente.h"

Cliente::Cliente(string nombre, int saldo)
{
	this->nombre = nombre;
	this->saldo = saldo;
}

Cliente::Cliente(string nombre)
{
	this->nombre = nombre;
}

Cliente::~Cliente()
{
}

string Cliente::getNombre()
{
	return nombre;
}

int Cliente::getSaldo()
{
	return saldo;
}

string Cliente::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"saldo\":" << saldo << ",\"bonos\":" << bonos.toJson(Bono::toJsonPtr) << ",\"cargas\":"<<cargas.toJson(Carga::toJsonPtr)<<"}";
	return ss.str();
}

ListaEnlazada<Bono>& Cliente::getBonos()
{
	return bonos;
}

void Cliente::registrar(Bono* b)
{
	bonos.registrar(b);
}

void Cliente::cargar(Carga* c)
{

	if (c->getKwh() <= 0)
		throw exception(("kwh invalido en la carga " + to_string(c->getId())).c_str());
	
	int KwhPorCubrir = c->getKwh();

	for (int i = 0; i < bonos.getTam(); i++)
	{
		Bono* bono = bonos[i];
		if (dynamic_cast<BonoUniversal*>(bono) != NULL || (dynamic_cast<BonoEstandar*>(bono) != NULL && dynamic_cast<CargaEstandar*>(c) != NULL))
		{
			int cubre = bono->getKwh();
			if (cubre > KwhPorCubrir)
			{
				cubre = KwhPorCubrir;
			}
			KwhPorCubrir = KwhPorCubrir - cubre;
		}
	}
	int costo = KwhPorCubrir * c->getTarifa();

	if (costo > saldo)
		throw exception(("saldo insuficiente " + nombre + " no pudo realizar la carga " + to_string(c->getId())).c_str());

	KwhPorCubrir = c->getKwh();
	for (int i = 0; i < bonos.getTam(); i++)
	{
		Bono* bono = bonos[i];
		if (dynamic_cast<BonoUniversal*>(bono) != NULL || (dynamic_cast<BonoEstandar*>(bono) != NULL && dynamic_cast<CargaEstandar*>(c) != NULL))
		{
			int cubre = bono->getKwh();
			if (cubre > KwhPorCubrir)
				cubre = KwhPorCubrir;
			bono->setKwh(bono->getKwh() - cubre);
			KwhPorCubrir = KwhPorCubrir - cubre;
		}
	}
	c->setCosto(costo);
	saldo = saldo - costo;
	cargas.registrar(c);
}

string Cliente::toJsonPtr(Cliente* c)
{
	return c->toJson();
}

bool Cliente::operator==(Cliente* c)
{
	return nombre == c->nombre;
}

bool Cliente::compararPorNombre(Cliente* a, Cliente* b)
{
	return a->getNombre() > b->getNombre();
}

int Cliente::totalFacturado()
{
	int total = 0;
	for (int i = 0; i < cargas.getTam(); i++)
	{
		total = total + cargas[i]->getCosto();
	}
	return total;
}

int Cliente::cantidadCargasRapidas()
{
	int cont = 0;
	for (int i = 0; i < cargas.getTam(); i++)
	{
		CargaRapida* cr = dynamic_cast<CargaRapida*>(cargas[i]);
		if (cr != NULL)
			cont++;
	}

	return cont;
}

int Cliente::totalKwh()
{
	int total = 0;
	for (int i = 0; i < cargas.getTam(); i++)
	{
		total = total + cargas[i]->getKwh();
	}
	return total;
}
