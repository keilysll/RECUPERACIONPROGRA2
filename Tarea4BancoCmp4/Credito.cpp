#include "Credito.h"

Credito::Credito(int deudaCuota)
{
	this->deudaCuota = deudaCuota;
}

Credito::~Credito()
{
}

int Credito::getDeudaCuota()
{
	return deudaCuota;
}

string Credito::toJsonPtr(Credito* c)
{
	return c->toJson();
}

void Credito::setDeudaCuota(int deudaCuota)
{
	this->deudaCuota = deudaCuota;
}
