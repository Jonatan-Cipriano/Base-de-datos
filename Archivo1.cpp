#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Datos{
	int codigo;
	int telefono;
	char Nombre[99];
	char Apellido[99];
	char Direccion[99];
};
void crear();
void leer();
void actualizar();
main(){
	char op;
	leer();
	crear();
	cout<<"Desea actualizar algun dato? (s/n)"<<endl;
	cin>>op;
	if(op=='s'){
	actualizar();
	} else{
	
	system("pause");
	}
}
void leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	Datos datos;
	int id=0;
	fread(&datos,sizeof(datos),1,archivo);

	do{
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<id<<" | "<<datos.codigo<<" | "<<datos.Nombre<<" | "<<datos.Apellido<<" | "<<datos.Direccion<<" | "<<datos.telefono<<endl; 
		
	fread(&datos,sizeof(datos),1,archivo);
	
	id=id+1;
	}while(feof(archivo)==0);
	fclose(archivo);
}
void crear(){
	FILE* archivo = fopen(nombre_archivo,"ab");
	
	Datos datos;
	char cont;
	string nombre,apellido,direccion;
	do{ 
		cout<<"Ingrese codigo"<<endl;
		cin>>datos.codigo;
		cin.ignore();
		cout<<"Ingrese nombres del estudiante"<<endl;
		getline(cin,nombre);
		strcpy(datos.Nombre,nombre.c_str());
		
		cout<<"Ingrese apellido del estudiante"<<endl;
		getline(cin,apellido);
		strcpy(datos.Apellido,apellido.c_str());
		cout<<"Ingrese Direccion del estudiante"<<endl;
		getline(cin,direccion);
		strcpy(datos.Direccion,direccion.c_str());
		cout<<"Ingrese numero de telefono del estudiante"<<endl;
		cin>>datos.telefono;
		
		fwrite(&datos,sizeof(datos),1,archivo);
		
		fflush(stdin);
		cout<<"¿Desea ingresar mas datos (s/n)?"<<endl;
		cin>>cont;
	}while(cont=='s');
	fclose(archivo);
	leer();
	
}

void actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	
	Datos datos;
	char cont;
	string nombre,apellido,direccion;
	int id=0;
	
	cout<<"Ingrese id a modificar"<<endl;
	cin>>id;
	fseek(archivo,id *sizeof(datos),SEEK_SET);
	
	cout<<"Ingrese codigo"<<endl;
		cin>>datos.codigo;
		cin.ignore();
		cout<<"Ingrese nombres del estudiante"<<endl;
		getline(cin,nombre);
		strcpy(datos.Nombre,nombre.c_str());
		
		cout<<"Ingrese apellido del estudiante"<<endl;
		getline(cin,apellido);
		strcpy(datos.Apellido,apellido.c_str());
		cout<<"Ingrese Direccion del estudiante"<<endl;
		getline(cin,direccion);
		strcpy(datos.Direccion,direccion.c_str());
		cout<<"Ingrese numero de telefono del estudiante"<<endl;
		cin>>datos.telefono;
		fwrite(&datos,sizeof(datos),1,archivo);
		fclose(archivo);
		leer();
		
}
