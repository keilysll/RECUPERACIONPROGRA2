#include "Paquete.h"

Paquete::Paquete(int saldo)
{
	this->saldo = saldo;
}

Paquete::~Paquete()
{
}

int Paquete::getSaldo()
{
	return saldo;
}

string Paquete::toJsonPtr(Paquete* p)
{
	return p->toJson();
}

void Paquete::setSaldo(int saldo)
{
	this->saldo = saldo;
}
