#include "Usuario.h"

Usuario::Usuario(string nombre, int saldo)
{
	this->nombre = nombre;
	this->saldo = saldo;
}

Usuario::Usuario(string nombre)
{
    this->nombre = nombre;
}

Usuario::~Usuario()
{
}

string Usuario::getNombre()
{
	return nombre;
}

int Usuario::getSaldo()
{
	return saldo;
}

ListaEnlazada<Paquete>& Usuario::getPaquetes()
{
	return paquetes;
}

void Usuario::registrar(Paquete* p)
{
	paquetes.registrar(p);
}
void Usuario::ejecutarAccion(Detalle* d)
{
    int cantidadAPagar = d->getCantidad();
    bool esDescarga = dynamic_cast<Descarga*>(d) != NULL;

    Paquete* paqueteUsado = NULL;

    for (int posicion = 0; posicion < paquetes.getTam(); posicion++)
    {
        Paquete* paqueteActual = paquetes.obtener(posicion);

        if (esDescarga)
        {
            if (dynamic_cast<PaqueteMegas*>(paqueteActual) != NULL)
                paqueteUsado = paqueteActual;                              
        }

        else
        { 
            if (dynamic_cast<PaqueteMinutos*>(paqueteActual) != NULL)
            paqueteUsado = paqueteActual;
        }
      
    }

    int PagoConPaquete = 0;   // si no hay paquete, se paga 0 con él

    if (paqueteUsado != NULL)
    {
        int queTieneElPaquete = paqueteUsado->getSaldo();

        if (queTieneElPaquete < cantidadAPagar)
            PagoConPaquete = queTieneElPaquete;   // no alcanza: uso todo
        else
            PagoConPaquete = cantidadAPagar;        

        if (esDescarga && queTieneElPaquete <= cantidadAPagar)   // NUEVO
            PagoConPaquete = 0;
    }

    int PagadoConSaldo = cantidadAPagar - PagoConPaquete;

    if (PagadoConSaldo>saldo)
    {
        throw exception(("saldo insuficiente " + nombre + " no pudo realizar " + d->getTipo() +to_string(d->getId())).c_str());
    }
    
    if (paqueteUsado != NULL)
        paqueteUsado->setSaldo(paqueteUsado->getSaldo() - PagoConPaquete);

    saldo = saldo - PagadoConSaldo;
    
    detalles.registrar(d);
}

string Usuario::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"saldo\":"<<saldo<<",\"paquetes\":"<<paquetes.toJson(Paquete::toJsonPtr)<<",\"detalle\":"<<detalles.toJson(Detalle::toJsonPtr)<<"}";
	return ss.str();
}

string Usuario::toJsonPtr(Usuario* u)
{
    return u->toJson();
}

bool Usuario::operator==(Usuario* u)
{
    return u->nombre == nombre;
}
