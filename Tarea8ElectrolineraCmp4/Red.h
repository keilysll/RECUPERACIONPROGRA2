#pragma once
#include"Cliente.h"
#include"ListaEnlazada.h"
class Red
{
private:
	string nombre;
	ListaEnlazada<Cliente>clientes;
public:
	Red(string nombre);
	~Red();
	string getNombre();
	string toJson();
	void operator+=(Cliente* c);
	void registrarBono(string nombre,Bono* b);
	void registrarCarga(string nombre, Carga* c);
	int totalFacturado();
	string clienteMayorConsumo();
	int cantidadCargasRapidas();
};

