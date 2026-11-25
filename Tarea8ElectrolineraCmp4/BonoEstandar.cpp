#include "BonoEstandar.h"

BonoEstandar::BonoEstandar(int kwh):Bono(kwh)
{
}

BonoEstandar::~BonoEstandar()
{
}

string BonoEstandar::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"estandar\",\"kwh\":"<<kwh<<"}";
	return ss.str();
}
