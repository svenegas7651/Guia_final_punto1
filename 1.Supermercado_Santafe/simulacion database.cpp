#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class empleado
{
	public:
		empleado()
		{
		nombre = '0';
		servicio = '0';
		salario = '0';
		}
		empleado(string n, string m, int j);

		friend ostream & operator <<(ostream &os, const empleado& stu)
		{
			os << "Nombre: " << stu.nombre << "\n" << "Servicio: " << stu.servicio;
			return os;
		}

		string nombre;
		string servicio;
		int salario;
};

empleado::empleado(string n, string m, int j)
{
	nombre = n;
	servicio = m;
	salario = j;
}


int main(void)
{	

	cout << "Por favor ponga el numero de empleados en la base de datos: ";
	int size;
	cin >> size;
	size = size+1;
	empleado *a;
	a = new empleado[size];
	int i = 1;
	for(i=1;i<size;i++)
	{
		cout << "Escriba un nombre, servicio y salario..." << endl;
		string snombre;
		string sservicio;
		int ssalario;
		cin >> snombre >> sservicio >> ssalario;
		empleado test(snombre, sservicio, ssalario);
		a[i] = test;
	}
	cout << "Quiere editar algo:? (si o no): ";
	string si = "si";
	string te;
	cin >> te;
	string no = "no";
	if(te == si)
	{
		cout << endl << "¿Le gustaria buscar por el nombre del empleado en lugar del servicio? (si o no): ";
		string fat;
		cin >> fat;
		if(fat == si)
		{
			string ttname;
			cout << endl << "Cual es el nombre del empleado?: " << endl;
			cin >> ttname;
			int j = 1;
			for(j=1;j<size;j++)
			{
				empleado temp2;
				temp2 = a[j];
				if(temp2.nombre == ttname)
				{
					cout << "¿Quiere editarlo?: " << endl << temp2 << endl;
					cout << "Cual es el nuevo salario?: ";
						int neww;
						cin >> neww;
						temp2.salario = neww;
						a[j] = temp2;
						cout << "Asi se ve el nuevo archivo..." << endl;
						cout << temp2;
				}
			}
	}
	if(fat == no)
	{
		cout << "Cual es el servicio del empleado que quiere editar?: ";
		int tem;
		cin >> tem;
		cout << "Le gustaria editarlo: " << endl << a[tem];
		cout << endl;
		cout << "Cual es el nuevo salario?: ";
		int newm;
		cin >> newm;
		empleado tempp;
		tempp = a[tem];
		tempp.salario = newm;
		a[tem] = tempp;
		cout << "Asi se ve el nuevo archivo..." << endl;
		cout << tempp;
	}
}

cout << endl << "Le gustaria mostrar los datos del empleado? (si o no): ";
	string response;
	cin >> response;
	if(response == si)
	{
		string tempname;
		cout << endl << "Cual es el nombre: " << endl;
		cin >> tempname;
		int j = 1;
		for(j = 1;j<size;j++)
		{
			empleado temp1;
			temp1 = a[j];
			if(temp1.nombre == tempname)
			{
				cout<<temp1<<endl;
			}
		}
	}
	cout << endl << "¿Quiere mostrar los datos de la base de datos? (si o no): ";
	string testing;
	cin >> testing;
	if(testing == si)
	{
		int k = 0;
		for(k = 1;k<size;k++)
		{
			cout << k << ".)" << endl << a[k] << endl;
		}
	}
delete a;

system("PAUSE");
return 0;
}

