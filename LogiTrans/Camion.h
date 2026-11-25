#pragma once
#include "Vehiculo.h"
class Camion :
    public Vehiculo
{
private:
    int capac;
    int cargaAct;
    int nroEjes;
public:
    Camion(string placa,int capac,int nroEjes);
    Camion(string placa);
    ~Camion();
    int getCapac();
    int getcargaAct();
    int getnroEjes();
    string toJson();
    int costoMantenimiento();
    void cargar(int kg);

};

