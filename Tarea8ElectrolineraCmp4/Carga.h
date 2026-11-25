#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Carga
{
protected:
	int id;
	int fecha;
	int kwh;
	int costo;
public:
	Carga(int id,int fecha,int kwh);
	~Carga();
	int getId();
	int getFecha();
	int getKwh();
	virtual string toJson() = 0;
	int getCosto();
	virtual int getTarifa() = 0;
	void setCosto(int costo);
	static string toJsonPtr(Carga* c);

};

