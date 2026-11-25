

/*
* Una empresa de logística (LogiTrans) desea una aplicación para administrar
* su flota de vehículos.
* La aplicación debe permitir:
* - Registrar vehículos (camiones y motocicletas) en la flota.
* - Calcular el costo de mantenimiento de cada vehículo y de la flota.
* - Cargar mercadería en los camiones, validando su capacidad.
*
* Requisitos de diseño:
* - Vehiculo es una clase base abstracta con un método virtual puro
* toJson() y un método virtual puro costoMantenimiento().
* - Camion y Moto heredan de Vehiculo y redefinen ambos métodos.
* - Vehiculo sobrecarga el operador == para comparar dos vehículos
* por su placa.
* - Flota sobrecarga el operador += para agregar un vehículo
* (Flota& operator+=(Vehiculo*)).
* - Flota::cargarCamion(placa, carga) debe usar dynamic_cast para
* verificar que el vehículo encontrado sea un Camion; si no lo es,
* debe lanzar una excepción.
* - Camion::cargar(carga) debe lanzar una excepción si la carga
* supera la capacidad del camión.
*/
#include "Flota.h"
#include<iostream>
using namespace std;

int pregunta1()
{
	cout << "----Pregunta 1----" << endl;
	cout << "Resultado esperado:" << endl;
	cout << "{\"nombre\":\"LogiTrans\",\"vehiculos\":[{\"placa\":\"ABC123\",\"tipo\":\"camion\",\"capacidadCarga\":5000,\"cargaActual\":0,\"numEjes\":3},{\"placa\":\"XYZ789\",\"tipo\":\"moto\",\"cilindrada\":150}]}" << endl;
	// crear flota(nombre)
	Flota flota("LogiTrans");
	// registrar camion(placa, capacidad de carga, numero de ejes) usando operator+=
	flota += new Camion("ABC123", 5000, 3);
	// registrar moto(placa, cilindrada) usando operator+=
	flota += new Moto("XYZ789", 150);

	cout << "Resultado obtenido:" << endl;
	cout << flota.toJson() << endl;

	if (flota.toJson() == "{\"nombre\":\"LogiTrans\",\"vehiculos\":[{\"placa\":\"ABC123\",\"tipo\":\"camion\",\"capacidadCarga\":5000,\"cargaActual\":0,\"numEjes\":3},{\"placa\":\"XYZ789\",\"tipo\":\"moto\",\"cilindrada\":150}]}")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta2()
{
	cout << "----Pregunta 2----" << endl;
	cout << "Resultado esperado:" << endl;
	cout << "r1=1 r2=0" << endl;

	// dos camiones con la misma placa pero distinta capacidad/ejes deben ser == (compara solo placa)
	Camion c1("ABC123", 5000, 3);
	Camion temp1("ABC123", 9999, 1);
	// un camion y una moto con placas distintas no deben ser ==
	Moto m1("XYZ789", 999);

	bool r1 = (c1 == temp1);
	bool r2 = (c1 == m1);

	cout << "Resultado obtenido:" << endl;
	cout << "r1=" << r1 << " r2=" << r2 << endl;

	if (r1 == true && r2 == false)
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta3()
{
	cout << "----Pregunta 3----" << endl;
	cout << "Resultado esperado costoTotalMantenimiento: 195" << endl;
	// costoMantenimiento camion = capacidadCarga*0.01 + numEjes*10
	// costoMantenimiento moto = cilindrada*0.5
	// ABC123: 5000*0.01 + 3*10 = 50 + 30 = 80
	// XYZ789: 150*0.5 = 75
	// DEF456: 2000*0.01 + 2*10 = 20 + 20 = 40
	// total = 80 + 75 + 40 = 195

	Flota flota("LogiTrans");
	flota += new Camion("ABC123", 5000, 3);
	flota += new Moto("XYZ789", 150);
	flota += new Camion("DEF456", 2000, 2);

	cout << "Resultado obtenido costoTotalMantenimiento: " << flota.costoTotalMantenimiento() << endl;

	if (flota.costoTotalMantenimiento() == 195)
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta4()
{
	cout << "----Pregunta 4----" << endl;
	cout << "Resultado esperado:" << endl;
	cout << "{\"nombre\":\"LogiTrans\",\"vehiculos\":[{\"placa\":\"ABC123\",\"tipo\":\"camion\",\"capacidadCarga\":5000,\"cargaActual\":3000,\"numEjes\":3},{\"placa\":\"XYZ789\",\"tipo\":\"moto\",\"cilindrada\":150}]}" << endl;
	cout << "error1: capacidad excedida" << endl;
	cout << "error2: XYZ789 no es un camion" << endl;

	Flota flota("LogiTrans");
	flota += new Camion("ABC123", 5000, 3);
	flota += new Moto("XYZ789", 150);

	string error1, error2;
	try {
		// cargar 3000 (dentro de la capacidad de 5000)
		flota.cargarCamion("ABC123", 3000);
		// cargar otros 3000 (3000+3000=6000 > 5000) -> debe lanzar excepcion
		flota.cargarCamion("ABC123", 3000);
	}
	catch (exception& e) {
		error1 = e.what();
	}

	try {
		// XYZ789 es una moto, no un camion -> debe lanzar excepcion (dynamic_cast)
		flota.cargarCamion("XYZ789", 100);
	}
	catch (exception& e) {
		error2 = e.what();
	}

	cout << "Resultado obtenido:" << endl;
	cout << flota.toJson() << endl;
	cout << "error1: " << error1 << endl;
	cout << "error2: " << error2 << endl;

	if (flota.toJson() == "{\"nombre\":\"LogiTrans\",\"vehiculos\":[{\"placa\":\"ABC123\",\"tipo\":\"camion\",\"capacidadCarga\":5000,\"cargaActual\":3000,\"numEjes\":3},{\"placa\":\"XYZ789\",\"tipo\":\"moto\",\"cilindrada\":150}]}"
		&& error1 == "capacidad excedida"
		&& error2 == "XYZ789 no es un camion")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}

int pregunta5()
{
	cout << "----Pregunta 5----" << endl;
	cout << "Resultado esperado error: vehiculo no encontrado: ZZZ999" << endl;

	Flota flota("LogiTrans");
	flota += new Camion("ABC123", 5000, 3);

	string error;
	try {
		// ZZZ999 no esta registrado en la flota -> debe lanzar excepcion
		flota.cargarCamion("ZZZ999", 100);
	}
	catch (exception& e) {
		error = e.what();
	}

	cout << "Resultado obtenido error: " << error << endl;

	if (error == "vehiculo no encontrado: ZZZ999")
	{
		cout << "Resultado: correcto" << endl;
		return 20;
	}
	cout << "Resultado: incorrecto" << endl;
	return 0;
}
int main()
{
	int nota = pregunta1() +pregunta2() + pregunta3() + pregunta4() + pregunta5();
	cout << endl;
	cout << "====================" << endl;
	cout << "===> NOTA: " << nota << "/100" << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}
