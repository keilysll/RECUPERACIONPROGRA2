#pragma once
#include "Credito.h"
class CreditoCuotaVariable :
    public Credito
{
public:
    CreditoCuotaVariable(int deudaCuota);
    ~CreditoCuotaVariable();
    string toJson();

};

