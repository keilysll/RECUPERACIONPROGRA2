#pragma once
#include "Detalle.h"
class Llamada :
    public Detalle
{
private:
    int duracionLlamada;
public:
    Llamada(int id, int fecha,int duracionLlamada);
    ~Llamada();
    int getDuracion();
    string toJson();
    int getCantidad();
    string getTipo();
};

