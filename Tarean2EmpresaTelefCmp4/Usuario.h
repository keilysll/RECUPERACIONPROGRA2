#pragma once
#include"Llamada.h"
#include"Detalle.h"
#include"Paquete.h"
#include"PaqueteMegas.h"
#include"PaqueteMinutos.h"
#include"Descarga.h"
#include"ListaEnlazada.h"
class Usuario
{
private:
	string nombre;
	int saldo;
	ListaEnlazada<Paquete>paquetes;
	ListaEnlazada<Detalle> detalles;
public:
	Usuario(string nombre,int saldo);
	Usuario(string nombre);
	~Usuario();
	string getNombre();
	int getSaldo();
	ListaEnlazada<Paquete>& getPaquetes();
	void registrar(Paquete* p);
	void ejecutarAccion(Detalle* d);
	string toJson();
	static 	string toJsonPtr(Usuario * u);
	bool operator == (Usuario* u);
	

};

