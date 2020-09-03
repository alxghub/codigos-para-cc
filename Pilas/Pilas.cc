#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo *next;
};

void agregarPila(Nodo *&, int);
void quitarPila(Nodo *&);
void mostrarPila(Nodo *);
void quitarTodo(Nodo *&);

Nodo *pila = NULL;

int main(){
	int opcion, n;
	do{
		cout<<"Menu:"<<endl;
		cout<<"1. Agregar Elemento a la Pila"<<endl;
		cout<<"2. Quitar Ultimo elemento de la pila"<<endl;
		cout<<"3. Mostrar Pila Completa"<<endl;
		cout<<"4. Quitar todos los elementos de la pila"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Opcion -> "; cin>>opcion; cout<<"\n";
		switch(opcion){
			case 1:
				cout<<"Ingrese el numero: "; cin>>n;
				agregarPila(pila,n);
				break;
			case 2:
				quitarPila(pila);
				break;
			case 3:
				mostrarPila(pila);
				break;
			case 4:
				quitarTodo(pila);
				break;
			case 5:
				cout<<"Programa Terminado.."<<endl;
				break;
			default:
				cout<<"Opcion incorrecta.."<<endl;
		}	
	}while(opcion!=5);
    cin.ignore();
    cin.get();
	return 0;
}

void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->next = pila;
	pila = nuevo_nodo;
	cout<<"\nElemento "<<n<<" agregado correctamente."<<endl<<endl;
}

void quitarPila(Nodo *&pila){
	if(pila == NULL) cout<<"\nNo hay mas elemento en la pila"<<endl<<endl;
	else{
		Nodo *aux = pila;
		pila = aux->next;
		delete aux;
		cout<<"\nElemento eliminado de la pila."<<endl<<endl;
	}
}

void mostrarPila(Nodo *pila){
	cout<<endl;
	if(pila == NULL) cout<<"No hay elementos en la pila..";
	else{
		while(pila != NULL){
		cout<<pila->dato<<" -> ";
		pila = pila->next;
		}
	}
	cout<<endl<<endl;
}

void quitarTodo(Nodo *&pila){
	while(pila != NULL){
		cout<<pila->dato<<" ";
		Nodo *aux = pila;
		pila = aux->next;
		delete aux;
	}
	cout<<endl<<"\nElementos eliminados de la pila."<<endl<<endl;
}