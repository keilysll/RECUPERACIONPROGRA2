#include "Camion.h"

Camion::Camion(string placa, int capac,int nroEjes):Vehiculo(placa)
{
	this->capac = capac;
	this->cargaAct = 0;
	this->nroEjes = nroEjes;
}

Camion::Camion(string placa):Vehiculo(placa)
{
}

Camion::~Camion()
{
}

int Camion::getCapac()
{
	return capac;
}

int Camion::getcargaAct()
{
	return cargaAct;
}

int Camion::getnroEjes()
{
	return nroEjes;
}

string Camion::toJson()
{
	stringstream ss;
	ss << "{\"placa\":\""<<placa<<"\",\"tipo\":\"camion\",\"capacidadCarga\":" << capac << ",\"cargaActual\":" << cargaAct << ",\"numEjes\":" << nroEjes << "}";
	return ss.str();
}

int Camion::costoMantenimiento()
{
	return ((capac * 0.01) +(nroEjes * 10));
}

void Camion::cargar(int kg)
{
	if (cargaAct + kg > capac)
	{
		throw exception("capacidad excedida");
	}
	cargaAct = cargaAct + kg;
}
