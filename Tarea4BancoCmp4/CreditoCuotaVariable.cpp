#include "CreditoCuotaVariable.h"

CreditoCuotaVariable::CreditoCuotaVariable(int deudaCuota):Credito(deudaCuota)
{
}

CreditoCuotaVariable::~CreditoCuotaVariable()
{
}

string CreditoCuotaVariable::toJson()
{
	stringstream ss;
	ss << "{\"tipo\":\"CreditoCuotaVariable\",\"deuda cuota variable\":"<<deudaCuota<<"}";
	return ss.str();
}
