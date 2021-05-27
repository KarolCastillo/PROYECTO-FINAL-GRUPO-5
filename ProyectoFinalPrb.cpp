
//PROYECTO FINAL PROGRAMACION GRUPO NO.5 
//-*-*-*-* AAP VETERINARIA *-*-*-*-

//INTEGRANTES DEL GRUPO:
// KAROL EUNICE CASTILLO RAMIREZ 0909-20-19052
// MYNOR IVAN ALDANA MARIN 0909-20-5400
// ANGEL FABRIZIO MENENDEZ SOLORZANO 0909-20-10024
// DARLYN ANDREA FAJARDO AROCHE 0909-19-9118

// Declaracion de librerias 

#include <string>
#include<fstream>
#include <iostream>
#include<stdio.h>

//para poder incluir palabras reservadas 
using namespace std;

const int maxrow = 10;

// el string nos sirve para guardar cadenas de texto, indicamos donde aguardaremos los datos
string EmpName[maxrow] = {};
string EmpID[maxrow] = {};
string EmpNameMasc[maxrow] = {};
string EmpNoTelf[maxrow] = {};
string EmpRaza[maxrow] = {};
string EmpDesHisCli[maxrow] = {};


// procedimiento de la funcion crear nuevo registro
void AddRecoord()
{
	//declaracion variables
	char name[50];
	char id[10];
	char namemasc[50];
	char telf[10];
	char raza[50];
	char descrip[200];

	//Ignorar el primer enter y asi no salte de una a la lectura de datos
	cin.ignore();

	//preguntar registros al cliente y llenar

	cout << " ID de registro. "; // mensaje en pantalla
	cin.getline(id, 10);// aqui indica donde almacenara el dato y la cantidad de valores que se le puede ingresar
	cout << " Nombre del propietario. ";
	cin.getline(name, 50);
	cout << " Numero celular. ";
	cin.getline(telf, 10);
	cout << " Nombre de la mascota. ";
	cin.getline(namemasc, 50);
	cout << " Tipo de raza de la mascota. ";
	cin.getline(raza, 50);
	cout << " Servicio clinico. ";
	cin.getline(descrip, 200);

	for (int x = 0; x < maxrow; x++)
	{
		if (EmpID[x] == "\0")
		{
			//guardar los datos de las variabl
			EmpID[x] = id;
			EmpName[x] = name;
			EmpNoTelf[x] = telf;
			EmpNameMasc[x] = namemasc;
			EmpRaza[x] = raza;
			EmpDesHisCli[x] = descrip;

			break;
		}
	}

}

// procedimiento de la funcion visualizar  todos los registros
void ListRecord()
{
	//limpiamos pantalla
	system("cls");
	//imprimimos texto en pantalla como titulo de la funcion (opcion)
	cout << " " << endl;
	cout << "====================================================================================================================== " << endl;
	cout << "                                  REGISTRROS ACTUALES DE MASCOTAS EN LA VETERINARIA" << endl;
	cout << "====================================================================================================================== " << endl;

	int counter = 0;

	//imprimimos todos los registros, esta es la estructura para identificar que dato pertenece al campo
	cout << " No.  |   ID   |   Nombre del propietario   |     Celular     |      Mascota      |          Raza           |      Descripccion   " << endl << "-------------------------------------------------------------------------------------------------------------------\n";
	for (int x = 0; x < maxrow; x++)
	{
		if (EmpID[x] != "\0")
		{
			counter++;
			cout << "   " << counter << "     " << EmpID[x] << "       " << EmpName[x] << "                 " << EmpNoTelf[x] << "        " << EmpNameMasc[x] << "                " << EmpRaza[x] << "               " << EmpDesHisCli[x] << endl;

		}
	}
	if (counter == 0)
	{
		//si no hay registro ingresados nos da un aviso con un mensaje 
		cout << " NINGUN REGISTRO FUE ENCONTRADO!" << endl;
		cout << "" << endl;
	}
	//relleno
	cout << "====================================== " << endl;
	cout << "" << endl;
	cout << "" << endl;
}

// procedimiento de la funcion buscar un registro segun ID
void SearchRecord(string search)

{
	//limpiamos pantalla
	system("CLS");

	//Escribimos mensaje
	cout << "                                                     REGISTROS ACTUALES" << endl;
	cout << "====================================================================================================================== " << endl;


	//limpiamos pantlla
	system("CLS");

	//imprimimos un relleno que nos rive como separador
	cout << "====================================================================================================================== " << endl;

	int counter = 0;
	for (int x = 0; x < maxrow; x++)
	{

		if (EmpID[x] == search)
		{
			//posicionamos el registro segun el ID, si existe!
			counter++;
			cout << " No.  |   ID   |   Nombre del propietario   |     Celular     |      Mascota      |          Raza             |     Descripccion   " << endl << "-------------------------------------------------------------------------------------------------------------------\n";
			cout << "   " << counter << "     " << EmpID[x] << "       " << EmpName[x] << "                 " << EmpNoTelf[x] << "         " << EmpNameMasc[x] << "                " << EmpRaza[x] << "          " << EmpDesHisCli[x] << endl;

			//detenemos
			break;
		}

	}
	// si no hay ningun registro nos da un mensaje de aviso
	if (counter == 0)
	{
		cout << "NO SE ENCONTRARON REGISTROS DEL ID!" << endl;
	}

	cout << "====================================================================================================================== " << endl;

}


// procedimiento de la funcion actualizar un registro (SE TIENEN QUE LLENAR TODOS LOS CAMPOS NUEVAMENTE)
void UpdateRecord(string search)
{
	//campos que actualiza enla misma linea del ID, si un campos e deja vacio asi lo imprime en la visualizacion
	char name[50];
	char namemasc[50];
	char telf[10];
	char raza[50];
	char descrip[200];

	int counter = 0;

	for (int x = 0; x < maxrow; x++)
	{
		if (EmpID[x] == search)
		{
			counter++;

			//el programa preguna ta los datos para actualizar y los vuelve a almacenar remplazando los datos anteriores por los nuevos
			cout << " Nombre del propietario. ";
			cin.getline(name, 50);
			EmpName[x] = name;
			cout << " Numero celular. ";
			cin.getline(telf, 10);
			EmpNoTelf[x] = telf;
			cout << " Nombre de la mascota. ";
			cin.getline(namemasc, 50);
			EmpNameMasc[x] = namemasc;
			cout << " Tipo de raza de la mascota. ";
			cin.getline(raza, 50);
			EmpRaza[x] = raza;
			cout << " Servicio clinico. ";
			cin.getline(descrip, 200);
			EmpDesHisCli[x] = descrip;



			//detener
			break;

			//mensake 
			cout << "ACTUALIZACION EXITOSA" << endl;


		}
	}

	//si el ID que ingresan no existe, no podemos actualizar ningun registro entonces mandamos un mesaje de aviso
	if (counter == 0)
	{
		cout << "EL ID NO EXISTE" << endl;
	}
}

// procedimiento de la funcion eliminar un registro segun ID
void DeleteRecord(string search)
{
	int counter = 0;

	for (int x = 0; x < maxrow; x++)
	{
		//si el ID existe en nuestro registro hace esto, elimina todo el registro
		if (EmpID[x] == search)
		{
			//indica la posicion (instuccion  pointer)
			counter++;
			EmpName[x] = "";
			EmpID[x] = "";

			EmpNoTelf[x] = "";
			EmpNameMasc[x] = "";
			EmpRaza[x] = "";
			EmpDesHisCli[x] = "";

			//imprimimos mensaje
			cout << "REGISTRO ELIMINADO CON EXITO!" << endl;

			//detener
			break;
		}
	}

	// si el ID no existe manda un mensaje de que no existe
	if (counter == 0)
	{
		cout << "EL NUMERO DE ID NO EXISTE!" << endl;

	}
}

//inicio de ejecucion del programa
int main()
{
	std::cout << "MENU DE OPCIONES\n";

	//declaramos la variable con la que elegimos nuestra opcion en el menu
	int option;
	string EmpID;

	//limpiamos pantalla
	system("CLS");

	// empezamos un ciclo condicional
	do {
		system("color 71");
		//imprimimos titulo
		cout << "                                                      PROYECTO FINAL GRUPO #5  " << endl;
		cout << "                                                      ******VETERINARIA******  " << endl;
		cout << "" << endl; //lineas en blanco
		cout << "" << endl;//lineas en blanco

			//imprimimos menu de las opciones del programa
		cout << " 1 - CREAR NUEVO REGISTRO DE MASCOTA" << endl;
		cout << " 2 - ACTUALIZAR REGISTRO DE MASCOTA (SE ACTUALIZAN TODOS LOS CAMPOS, LLENAR TODOS LOS CAMPOS)" << endl;
		cout << " 3 - ELIMINAR REGISTRO DE MASCOTA" << endl;
		cout << " 4 - BUSCAR POR ID EL REGISTRO DE MASCOTA" << endl;
		cout << " 5 - VISUALIZAR TODOS LOS REGISTROS DE MASCOTAS" << endl;
		cout << " 6 - SALIR Y GUARDAR REGISTROS DE VETERINARIA" << endl;
		cout << "*******************************************************" << endl;

		//imprimimos mensaje ingrseo de opcion
		cout << " SELECCIONAR SU OPCION (INGRESE NUMERO)  >> ";

		// almacenamos la opcion en la variablr option
		cin >> option;

		//iniciamos nuestra estructura de condiciones, segun el caso hacer esto.... el caso se almacena en variable option
		switch (option)
		{
		case 1:
			//llamamos la funcion de crear un nuevo registro
			AddRecoord();
			//limpiamos pantalla
			system("CLS");
			//detenemos o finalizamos el case 1
			break;

		case 2:
			cin.ignore();
			cout << "BUSCAR POR EL ID DEL REGISTRO>>";
			//funcion que lee una linea entera
			getline(cin, EmpID);
			//llamamos a la funcion de actualizar
			UpdateRecord(EmpID);
			//limpiamos
			system("CLS");
			//detenemos o finalizamos la ejecucion del case 2
			break;

		case 3:
			//al dar enter nos salta a la siguiente linea y asi no perdemos la opcion
			cin.ignore();
			//titulo de la opcion (funcion)
			cout << " ELIMINAR REGISTRO SEGUN ID >> ";
			//funcion que lee una linea entera
			getline(cin, EmpID);

			//llamamos a lafuncion
			DeleteRecord(EmpID);

			//al dar enter nos salta a la siguiente linea y asi no perdemos la opcion
			cin.ignore();

			//limpiamos pantalla
			system("CLS");

			//detenemos el case 3
			break;

		case 4:
			//al dar enter nos salta a la siguiente linea y asi no perdemos la opcion
			cin.ignore();

			//titulo opcion (funcion)
			cout << "BUSCAR POR EL ID DEL REGISTRO>>";

			//funcion que lee una linea entera
			getline(cin, EmpID);

			//llamamos a la funcion
			SearchRecord(EmpID);

			//detenemos el case 4
			break;


		case 5:

			//llamamos a la funcion visualizar los registros
			ListRecord();

			//detenemos
			break;
		}

		//fin del ciclo y decimos que al precionar el "6" saldremos del programa
	} while (option != 6);
}


