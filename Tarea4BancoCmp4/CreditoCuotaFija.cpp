#include "CreditoCuotaFija.h"

CreditoCuotaFija::CreditoCuotaFija(int deudaCuota):Credito(deudaCuota)
{
}

CreditoCuotaFija::~CreditoCuotaFija()
{
}

string CreditoCuotaFija::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"CreditoCuotaFija\",\"deuda cuota fija\":"<<deudaCuota<<"}";
	return ss.str();
}
