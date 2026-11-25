#include "PaqueteMegas.h"

PaqueteMegas::PaqueteMegas(int saldo):Paquete(saldo)
{
}

PaqueteMegas::~PaqueteMegas()
{
}

string PaqueteMegas::toJson()
{
    stringstream ss;
    ss << "{\"tipo\":\"megas\",\"saldo megas\":"<<saldo<<"}";
    return ss.str();
}
