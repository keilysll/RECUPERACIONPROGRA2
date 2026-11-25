#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Paquete
{
protected:
	int saldo;
public:
	Paquete(int saldo);
	~Paquete();
	int getSaldo();
	virtual string toJson() = 0;
	static string toJsonPtr(Paquete* p);
	void setSaldo(int saldo);
	
};

