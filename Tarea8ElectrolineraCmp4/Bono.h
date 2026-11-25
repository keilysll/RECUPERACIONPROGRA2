#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Bono
{
protected:
	int kwh;
public:
	Bono(int kwh);
	~Bono();
	int getKwh();
	virtual string toJson() = 0;
	static string toJsonPtr(Bono* b);
	void setKwh(int kwh);
};

