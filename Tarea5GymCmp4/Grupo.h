#pragma once
#include"ListaEnlazada.h"
#include"SingletonSocios.h"
#include"Sesion.h"
#include"Socio.h"
class Grupo
{
protected:
	string id;
	ListaEnlazada<Socio>socios;
	ListaEnlazada<Sesion> sesiones;
public:
	Grupo(string id);
	~Grupo();
	string getId();
	virtual string toString();
	static string toStringPtr(Grupo* g);
	void inscribir(int idSocio);

};

