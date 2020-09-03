#include<iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void insertarCola(Nodo *&, Nodo *&, int);
void quitarCola(Nodo *&, Nodo *&);
void mostrarCola(Nodo *);
void quitarTodo(Nodo *&, Nodo *&);

int main(){
	Nodo *frente = NULL, *fin = NULL;
	int n, opcion;
	do{
		cout<<"Menu:"<<endl;
		cout<<"1. Agregar Elemento a la Cola"<<endl;
		cout<<"2. Quitar elemento de la Cola"<<endl;
		cout<<"3. Mostrar elementos esperando en la Cola"<<endl;
		cout<<"4. Quitar todos los elementos de la cola"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Opcion -> "; cin>>opcion; cout<<"\n";
		switch(opcion){
			case 1:
				cout<<"Ingrese el numero: "; cin>>n;
				insertarCola(frente, fin, n);
				break;
			case 2:
				quitarCola(frente, fin); break;
			case 3:
				mostrarCola(frente); break;
			case 4:
				quitarTodo(frente, fin); break;
			case 5:
				cout<<"Programa terminado.."<<endl; break;
			default:
				cout<<"Opcion incorrecta.."<<endl;
		}
	}while(opcion!=5);
    cin.ignore();
    cin.get();
	return 0;
}

void insertarCola(Nodo *&frente, Nodo *&fin, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(frente == NULL) frente = nuevo_nodo;
	else fin->siguiente = nuevo_nodo;
	
	fin = nuevo_nodo;
	cout<<"Elemento insertado correctamente"<<endl<<endl;
}

void quitarCola(Nodo *&frente, Nodo *&fin){
	if(frente == NULL) cout<<"No hay elementos en la Cola"<<endl<<endl;
	else{
		//n = frente->dato;
		Nodo *aux = frente;
		if(frente == fin){
			frente = NULL;
			fin = NULL;
		}else frente = frente->siguiente;
		delete aux;
		cout<<"Elemento Quitado de la Cola"<<endl<<endl;
	}
}

void mostrarCola(Nodo *frente){
	if(frente == NULL) cout<<"No hay elementos en la cola para mostrar..";
	else{
		while(frente!=NULL){
		cout<<frente->dato<<" <- ";
		frente = frente->siguiente;
		}
	}
	cout<<endl<<endl;
}

void quitarTodo(Nodo *&frente, Nodo *&fin){
	if(frente == NULL) cout<<"No hay elementos en la cola para quitar..";
	else{
		cout<<"quitando los nodos de la cola"<<endl<<endl;
		while(frente != NULL){
			cout<<frente->dato<<" ";
			Nodo *aux = frente;
			if(frente == fin){
				frente = NULL;
				fin = NULL;
			}else frente = frente->siguiente;
			delete aux;
		}
	}
	cout<<endl<<endl;
}