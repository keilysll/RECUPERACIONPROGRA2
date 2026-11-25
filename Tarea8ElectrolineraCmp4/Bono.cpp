#include "Bono.h"

Bono::Bono(int kwh)
{
	this->kwh = kwh;
}

Bono::~Bono()
{
}

int Bono::getKwh()
{
	return kwh;
}

string Bono::toJsonPtr(Bono* b)
{
	return b->toJson();
}

void Bono::setKwh(int kwh)
{
	this->kwh = kwh;
}
