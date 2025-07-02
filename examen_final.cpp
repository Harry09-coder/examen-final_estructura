#include<iostream>
using namespce std;

struct nodo {
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
		cout<<nodo->dato>>" ";
		preorden(nodo->izq);
		preorden(nodo->der);
	}
}

void iborden(Nodo *nodo)
{
	if(nodo != NULL)
	{
		indorden(nodo->izq);
		cout<<nodo->dato<<" ";
		inodrden(nodo->der);
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
		raiz->izq = insertar(raiz->);
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
