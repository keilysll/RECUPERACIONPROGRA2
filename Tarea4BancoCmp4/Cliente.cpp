#include "Cliente.h"

Cliente::Cliente(string nombre, int telef)
{
	this->nombre = nombre;
	this->telef = telef;
}

Cliente::Cliente(string nombre)
{
	this->nombre = nombre;
}

Cliente::~Cliente()
{
}

ListaEnlazada<Credito>& Cliente::getCreditos()
{
	return creditos;
}

void Cliente::registrar(Credito* c)
{
	creditos.registrar(c);
}

void Cliente::pagar(Pago* p)
{
	const int cuota = 10;
	Amortizacion* amortizacion = dynamic_cast<Amortizacion*>(p);
	Credito* creditoUsado = NULL;
	for(int i = 0; i<creditos.getTam();i++)
	{ 
		Credito* actual = creditos[i];
		if (amortizacion != NULL)
		{
			if (dynamic_cast<CreditoCuotaVariable*>(actual)!=NULL)
			{
				creditoUsado = actual;
			}
		}
		else
		{
			if (dynamic_cast<CreditoCuotaFija*>(actual) != NULL)
			{
				creditoUsado = actual;
			}
		}

	}
	int monto = 0;
	if (amortizacion != NULL)
	{
		monto = amortizacion->getMonto();
	}
	else
	{
		monto = cuota;
	}

	if (monto > creditoUsado->getDeudaCuota())
	{
		throw exception(("El monto que desea pagar "+nombre+" es mayor a la deuda").c_str());
	}
	if (creditoUsado != NULL)
	{
		creditoUsado->setDeudaCuota(creditoUsado->getDeudaCuota() - monto);
	}

	pagos.registrar(p);
}

string Cliente::getNombre()
{
	return nombre;
}

string Cliente::toJson()
{
	stringstream ss;
	ss << "{\"nombre\":\""<<nombre<<"\",\"fono\":"<<telef<<",\"creditos\":"<<creditos.toJson(Credito::toJsonPtr)<<",\"pagos\":"<<pagos.toJson(Pago::toJsonPtr)<<"}";
	return ss.str();
}

string Cliente::toJsonPtr(Cliente* c)
{
	return c->toJson();
}

bool Cliente::operator==(Cliente* c)
{
	return c->nombre == nombre;
}
