#include<iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo *izq;
	Nodo *der;
};

Nodo *nuevoNodo(int valor){
	Nodo *nodo=new Nodo();
	nodo->dato=valor;
	nodo->izq=NULL;
	nodo->der=NULL;
	return nodo;
}
void preorden(Nodo *nodo){
	if(nodo!=NULL)
	{
		cout<<nodo->dato<<" ";
		preorden(nodo->izq);
		preorden(nodo->der);
	}
}

void inorden(Nodo *nodo)
{
	if(nodo != NULL)
	{
		inorden(nodo->izq);
		cout<<nodo->dato<<" ";
		inorden(nodo->der);
	}
}

void postorden(Nodo *nodo)
{
	if(nodo != NULL)
	{
		postorden(nodo->izq);
		postorden(nodo->der);
		cout<<nodo->dato<<" ";
	}
}

Nodo *insertar(Nodo *raiz, int valor)
{
	if(raiz==NULL)
	{
		return nuevoNodo(valor);
	}
	if(valor<raiz->dato)
	{
		raiz->izq = insertar(raiz->izq,valor);
	}
	else
	{
		if(valor>raiz->dato)
		{
			raiz->der = insertar(raiz->der, valor);
		}
		else
		{
			cout<<"El valor ya existe y no se aceptan duplicados \n";
		}
	}
return raiz;
}
int main(){
	setlocale(LC_CTYPE,"Spanish");
	Nodo *raiz=NULL;
	int n, valor, i;
	cout<<"Cúantos valores seas insertar: ";
	cin>>n;
	for (i=0;i<n;i++)
	{
		cout<<"Ingrese valor: ";
		cin>>valor;
		raiz=insertar(raiz, valor);
	}
}
int main(){
	Nodo *raiz=NULL;
	int n, valor, i;
	cout<<"Cúantos valores seas insertar: ";
	cin>>n;
	for (i=0;i<n;i++)
	{
		cout<<"Ingrese valor: ";
		cin>>valor;
		raiz=insertar(raiz, valor);
	}
}
