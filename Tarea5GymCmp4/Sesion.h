#pragma once
#include"ListaEnlazada.h"
#include"Socio.h"
class Sesion
{
private:
	int fecha;
	ListaEnlazada<Socio>asistentes;
public:
	Sesion(int fecha);
	~Sesion();
	int getFecha();
	string toString();
	static string toStringPtr(Sesion* s);
	void registrarAsistente(Socio* s);
	bool operator ==(Sesion* s);

};

