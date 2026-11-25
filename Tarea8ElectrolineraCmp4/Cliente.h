#pragma once
#include"Bono.h"
#include"Carga.h"
#include"BonoEstandar.h"
#include"BonoUniversal.h"
#include"CargaEstandar.h"
#include"ListaEnlazada.h"
#include"CargaRapida.h"

class Cliente
{
private:
	string nombre;
	int saldo;
	ListaEnlazada<Bono>bonos;
	ListaEnlazada<Carga>cargas;
public:
	Cliente(string nombre,int saldo);
	Cliente(string nombre);
	~Cliente();
	string getNombre();
	int getSaldo();
	string toJson();
	ListaEnlazada<Bono>& getBonos();
	void registrar(Bono* b);
	void cargar(Carga* c);
	static string toJsonPtr(Cliente* c);
	bool operator ==(Cliente* c);
	static bool compararPorNombre(Cliente* a, Cliente* b);
	int totalFacturado();
	int cantidadCargasRapidas();
	int totalKwh();
};

