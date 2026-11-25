#pragma once
#include "Vehiculo.h"
class Moto :
    public Vehiculo
{
private:
    int cilindrada;
public:
    Moto(string placa,int cilindrada);
    ~Moto();
    int getCilin();
    string toJson();
    int costoMantenimiento();

};

