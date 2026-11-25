#pragma once
#include"Cliente.h"
#include"ListaEnlazada.h"
class Banco
{
private:
	string nombre;
	string direccion;
	ListaEnlazada<Cliente>clientes;
public:
	Banco(string nombre,string direccion);
	~Banco();
	string getNombre();
	string getDireccion();
	string toJson();
	void registrarCliente(string nombre, int telef);
	void registrarCredito(string nombre, Credito* c);
	void registrarPago(string nombre,int id,int fecha,int monto);
	void registrarPago(string nombre, int id, int fecha);
};

