#pragma once
#include"Grupo.h"
#include"Controlado.h"
#include"ListaEnlazada.h"
class Disciplina
{
private:
	string nombre;
	ListaEnlazada<Grupo>grupos;
public:
	Disciplina(string nombre);
	~Disciplina();
	ListaEnlazada<Grupo>* getGrupos();
	void registrar(Grupo* g);
	string getNombre();
	string toString();

};

