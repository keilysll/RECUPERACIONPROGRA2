#pragma once
#include"ListaEnlazada.h"
#include"Usuario.h"
class Telefonica
{
private:
	string nombre;
	string direc;
	ListaEnlazada<Usuario>usuarios;
public:
	Telefonica(string nombre,string direc);
	~Telefonica();
	string getNombre();
	string toJson();
	void registrarCliente(string nombre, int saldo);
	void registrarPaquete(string nombre, Paquete*p);
	void registrarLlamada(string nombre,int id,int fecha,int duracion);
	void registrarSMS(string nombre, int id, int fecha, int megas);


};

