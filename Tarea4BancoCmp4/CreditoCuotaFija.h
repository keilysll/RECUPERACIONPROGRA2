#pragma once
#include "Credito.h"
class CreditoCuotaFija :
    public Credito
{
public:
    CreditoCuotaFija(int deudaCuota);
    ~CreditoCuotaFija();
    string toJson();
};

