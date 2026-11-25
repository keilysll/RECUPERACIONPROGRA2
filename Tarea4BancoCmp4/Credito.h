#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Credito
{
protected:
	int deudaCuota;
public:
	Credito(int deudaCuota);
	~Credito();
	int getDeudaCuota();
	virtual string toJson() = 0;
	static string toJsonPtr(Credito* c);
	void setDeudaCuota(int deudaCuota);

};

