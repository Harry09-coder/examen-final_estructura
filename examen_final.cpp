#include<iostream>
using namespace std;
#include <windows.h>
//estructura que tendra en la estructura
struct Nodo {
	int dato;
	Nodo *izq;
	Nodo *der;
};
//cramos un nuevo nodo
Nodo *nuevoNodo(int valor){
	Nodo *nodo=new Nodo();
	nodo->dato=valor;
	nodo->izq=NULL;
	nodo->der=NULL;
	return nodo;
}

//función para limpiar
void limpiarConsola() {
    system("cls");
}

//funcion de preorden
void preorden(Nodo *nodo){
	if(nodo!=NULL)
	{
		cout<<nodo->dato<<" ";
		preorden(nodo->izq);
		preorden(nodo->der);
	}
}

//funcion de inorden
void inorden(Nodo *nodo)
{
	if(nodo != NULL)
	{
		inorden(nodo->izq);
		cout<<nodo->dato<<" ";
		inorden(nodo->der);
	}
}

//funcion postorden
void postorden(Nodo *nodo)
{
	if(nodo != NULL)
	{
		postorden(nodo->izq);
		postorden(nodo->der);
		cout<<nodo->dato<<" ";
	}
}

//funcion para mostrar inorden, postorden y preorden
void mostrarInorden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    } else {
        mostrarInorden(arbol->izquierdo);
        cout << arbol->dato << " ";
        mostrarInorden(arbol->derecho);
    }
}

void mostrarPreorden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    } else {
        cout << arbol->dato << " ";
        mostrarPreorden(arbol->izquierdo);
        mostrarPreorden(arbol->derecho);
    }
}

void mostrarPostorden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    } else {
        mostrarPostorden(arbol->izquierdo);
        mostrarPostorden(arbol->derecho);
        cout << arbol->dato << " ";
    }
}
//funcion para que el usuario ingrese los valores y no sean repetidos
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

//desicion o Realizar la búsqueda y mostrar el mensaje correspondiente (decisión).

void mostrarMensaje(int valor){
	cout<<"te interesa el deporte\n";
	if (valor == 12 || valor == 8 || valor == 15){
		cout <<"Practica DEPORTES DE EQUIPO\n";
		if (valor == 8)
		cout<<"Practica FÚTBOL\n";
		if (valor == 15)
		cout<<"Practica VOLEIBOL\n";
	} else if (valor == 30 || valor == 25 || valor == 35){
		cout<<"Practica DEPORTES INDIVIDUALES\n";
		if (valor == 25)
		cout<<"Practica NATACIÓN\n";
		if(valor == 35)
		cout<<"Practica TENIS\n";
	}
}

//BUSCAR NODO Y MOSTRAR DECISION
bool buscarYDecidir(Nodo* raiz, int valor)
{
	if(raiz == null) return false;
	if(raiz->valor == valor){
		mostrarMensaje(valor);
		return true;
	}else if (valor < raiz -> valor){
		return buscarYDecidir(raiz->izq, valor);
	} else {
		return buscarYDecidir(raiz->der, valor);
	}
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
return 0;
}
// Funcion menu
void menu() {
    Nodo* raiz = NULL;
    int opcion, valor;

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
                case 1:
                cout << "Ingrese el valor del nodo: ";
                cin >> valor;
                
                break;

            case 2:
                cout << "Recorrido inorden: ";
                
                cout << endl;
                break;
            case 3:
                  cout << "Recorrido preorden: ";
                
                cout << endl;
                break;

            case 4:
                 cout << "Recorrido postorden: ";
                
                cout << endl;
                break;

            case 5:
                 cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                
                    cout << "Valor no encontrado en el arbol." << endl;
                break;

            case 6:
                cout << "Saliendo del programa...\n";
                  cin >> valor;
                
                
                break;
    } while (opcion != 6);

    return 0;
}
