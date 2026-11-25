#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Vehiculo
{
protected:
	string placa;
public:
	Vehiculo(string placa);
	~Vehiculo();
	string getPlaca();
	virtual string toJson() = 0;
	virtual int costoMantenimiento() = 0;
	static string toJsonPtr(Vehiculo* v);
	bool operator==(Vehiculo* v);
	bool operator==(Vehiculo& v);
};

