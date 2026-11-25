#pragma once
#include "Carga.h"
class CargaRapida :
    public Carga
{
public:
    CargaRapida(int id, int fecha, int kwh);
    ~CargaRapida();
    string toJson();
    int getTarifa();
};

