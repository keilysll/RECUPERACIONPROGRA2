#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Socio
{
private:
	int ci;
	string nombre;
public:
	Socio(int ci,string nombre);
	Socio(int ci);
	~Socio();
	int getCi();
	string getNombre();
	string toString();
	static string toStringPtr(Socio* s);
	static bool OrdenarNombre(Socio* s1,Socio* s2);
	bool operator ==(Socio* s);

};

