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
void menu()
Nodo *raiz = NULL;
    int opcion, valor;
    bool salir = false;

    do {
        cout << "\n********************\n";
        cout << "Menu\n";
        cout << "1. Insertar nodo\n";
        cout << "2. Mostrar recorrido inorden\n";
        cout << "3. Mostrar recorrido preorden\n";
        cout << "4. Mostrar recorrido postorden\n";
        cout << "5. Buscar valor y mostrar decision\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                //insertar nodo
                cout << "Ingrese el valor del nodo: ";
                break;

            case 2:
                // recorrido inorden
                cout << " "Recorrido inorden:";
                break;

            case 3:
                //recorrido preorden
                cout << "Recorrido preorden:";
                break;

            case 4:
                //recorrido postorden
                cout << "Recorrido postorden: ";
                break;

            case 5:
                // a busqueda y mostrar decision
                cout << "Ingrese el valor a buscar: ";
                break;

            case 6:
                cout << "Saliendo del programa...\n";
                salir = true;
                break;

            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }

    } while (!salir);
