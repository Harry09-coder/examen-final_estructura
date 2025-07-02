#include <iostream>
using namespace std;

// Estructura que tendra en el arbol binario
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
};

// Crear un nuevo nodo
Nodo* nuevoNodo(int valor) {
    Nodo* nodo = new Nodo();
    nodo->dato = valor;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

// Insertar nodo sin duplicados
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return nuevoNodo(valor);
    }
    if (valor < raiz->dato) {
        raiz->izq = insertar(raiz->izq, valor);
    } else if (valor > raiz->dato) {
        raiz->der = insertar(raiz->der, valor);
    } else {
        cout << "El valor ya existe y no se aceptan duplicados.\n";
    }
    return raiz;
}

// Recorridos
void inorden(Nodo* nodo) {
    if (nodo != NULL) {
        inorden(nodo->izq);
        cout << nodo->dato << " ";
        inorden(nodo->der);
    }
}

void preorden(Nodo* nodo) {
    if (nodo != NULL) {
        cout << nodo->dato << " ";
        preorden(nodo->izq);
        preorden(nodo->der);
    }
}

void postorden(Nodo* nodo) {
    if (nodo != NULL) {
        postorden(nodo->izq);
        postorden(nodo->der);
        cout << nodo->dato << " ";
    }
}

// Mostrar mensaje segun valor
void mostrarMensaje(int valor) {
    cout << "Te interesa el deporte\n";
    if (valor == 12 || valor == 8 || valor == 15) {
        cout << "Practica DEPORTES DE EQUIPO\n";
        if (valor == 8) cout << "Practica FUTBOL\n";
        if (valor == 15) cout << "Practica VOLEIBOL\n";
    } else if (valor == 30 || valor == 25 || valor == 35) {
        cout << "Practica DEPORTES INDIVIDUALES\n";
        if (valor == 25) cout << "Practica NATACION\n";
        if (valor == 35) cout << "Practica TENIS\n";
    }
}

// Buscar y decidir
bool buscarYDecidir(Nodo* raiz, int valor) {
    if (raiz == NULL) return false;
    if (raiz->dato == valor) {
        mostrarMensaje(valor);
        return true;
    } else if (valor < raiz->dato) {
        return buscarYDecidir(raiz->izq, valor);
    } else {
        return buscarYDecidir(raiz->der, valor);
    }
}

// Menu principal
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
                cout << "Ingrese el valor del nodo: ";
                cin >> valor;
                raiz = insertar(raiz, valor);
                break;

            case 2:
                cout << "Recorrido inorden: ";
                inorden(raiz);
                cout << endl;
                break;

            case 3:
                cout << "Recorrido preorden: ";
                preorden(raiz);
                cout << endl;
                break;

            case 4:
                cout << "Recorrido postorden: ";
                postorden(raiz);
                cout << endl;
                break;

            case 5:
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                if (!buscarYDecidir(raiz, valor)) {
                    cout << "Valor no encontrado en el arbol." << endl;
                }
                break;

            case 6:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcion != 6);
}

// Funcion principal
int main() {
    menu();  // Llamada al menu
    return 0;
}
