#pragma once
#include"ListaEnlazada.h"
#include"Socio.h"
class SingletonSocios
{
private:
	ListaEnlazada<Socio>socios;
public:
	~SingletonSocios();
	static SingletonSocios& getInst();
	string toString();
	ListaEnlazada<Socio>* getSocios();
	void registrar(Socio* s);
private:
	SingletonSocios();

};

