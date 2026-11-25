#pragma once
#include"ListaEnlazada.h"
#include"Credito.h"
#include"CreditoCuotaFija.h"
#include"CreditoCuotaVariable.h"
#include"Amortizacion.h"
#include"Pago.h"
#include"CuotaFija.h"
class Cliente
{
private:
	string nombre;
	int telef;
	ListaEnlazada<Credito> creditos;
	ListaEnlazada<Pago>pagos;
public:
	Cliente(string nombre, int telef);
	Cliente(string nombre);
	~Cliente();
	ListaEnlazada<Credito>& getCreditos();
	void registrar(Credito* c);
	void pagar(Pago* p);
	string getNombre();
	string toJson();
	static string toJsonPtr(Cliente* c);
	bool operator==(Cliente* c);
};

