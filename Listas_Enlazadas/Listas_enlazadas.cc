#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

//Declaración de funciones:
void agregarElemento(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarElemento(Nodo *, int);
void eliminarElemento(Nodo *&);
void mostrarInformacionDeElementos(Nodo *);
void vaciarLista(Nodo *&);
void sumarElementos(Nodo *);
//void editarElemento(Nodo *&);

int main(){
    Nodo *lista = NULL;
    int opcion, n;
    do{
        cout<<".............:Menu:..............."<<endl;
        cout<<"1. Agregar un elemento a la lista."<<endl;
        cout<<"2. Mostrar elementos de la lista"<<endl;
        cout<<"3. Buscar Elemento en la lista"<<endl;
        cout<<"4. Eliminar elemento de la lista."<<endl;
        cout<<"5. Mostrar informacion de los elementos de la lista."<<endl;
        cout<<"6. Vaciar toda la lista."<<endl;
        cout<<"7. Sumar elementos de la lista"<<endl;
        //cout<<"8. Editar elemento de la lista"<<endl;
        cout<<"9. Salir."<<endl;
        cout<<"Opcion -> "; cin>>opcion;
        switch (opcion)
        {
        case 1:
            cout<<"Inserte un numero: "; cin>>n;
            agregarElemento(lista,n);
            break;
        case 2:
            mostrarLista(lista);
            break;
        case 3:
            cout<<"Que numero desea buscar?: "; cin>>n;
            buscarElemento(lista, n);
            break;
        case 4:
            eliminarElemento(lista);
            break;
        case 5:
            mostrarInformacionDeElementos(lista);
            break;
        case 6:
            vaciarLista(lista);
            break;
        case 7:
            sumarElementos(lista);
            break;
        /*case 8:
            editarElemento(lista);
            break;*/
        case 9:
            cout<<"Programa Terminado.."<<endl;
            break;
        default:
            cout<<"Opcion no Valida"<<endl;
            break;
        }
    }while(opcion != 9);
    cin.ignore();
    cin.get();
    return 0;
}

void agregarElemento(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    
    Nodo *aux1 = lista, *aux2;
    
    while(aux1 != NULL and aux1->dato < n){     //busca agregar los numeros en orden ascendente..
    	aux2 = aux1;
    	aux1 = aux1->siguiente;
    }
    if(lista == aux1) lista = nuevo_nodo;
    else aux2->siguiente = nuevo_nodo;
    nuevo_nodo->siguiente = aux1;
    cout<<"\nElemento agregado correctamente"<<endl<<endl;
}

void mostrarLista(Nodo *lista){
    cout<<endl;
    if (lista == NULL) cout<<"No hay elementos en la lista";
    else {
        while(lista != NULL){
        cout<<lista->dato<<" -> ";
        lista = lista->siguiente;
        }
    }
    cout<<endl<<endl;
}

void buscarElemento(Nodo *lista, int n){
    if (lista == NULL) cout<<"\nNo hay elementos en la lista";
    else{
        bool f=false;
        while(lista != NULL){
            if(lista->dato == n){
                f=true;
                cout<<"\nElemento "<<n<<" encontrado en la posicion de memoria: "<<lista<<endl;
            }
        lista = lista->siguiente;
        }
        if (f==false) cout<<"\nElemento no encontrado en la lista.";
    }
    cout<<endl<<endl;
}

void eliminarElemento(Nodo *&lista){
    if(lista == NULL) cout<<"\nLa lista esta vacia"<<endl<<endl;
    else{
        Nodo *aux_borrar, *anterior = NULL;
        aux_borrar = lista;
        int n;
        cout<<"\nQue elemento desea eliminar?: "; cin>>n;
        while(aux_borrar != NULL and aux_borrar->dato != n){
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if(aux_borrar == NULL) cout<<"El elemento no existe"<<endl;
        else if(anterior == NULL){
            lista = lista->siguiente;
            delete aux_borrar;
            cout<<"elemento eliminado.."<<endl; //si acaso era primero de la lista
        }else{
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
            cout<<"elemento eliminado.."<<endl; //si no era primero de lista
        }
        cout<<endl;
    }
}

void mostrarInformacionDeElementos(Nodo *lista){
    if(lista == NULL) cout<<"\nNo hay elementos en la lista."<<endl;
    else{
        cout<<"\n    POSICION DE MEMORIA          ||        DATOS        ||        PUNTEROS  "<<endl;
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        while(lista != NULL){
            cout<<"Posicion de Memoria: "<<lista<<" ||     lista->dato: "<<lista->dato<<" || lista->siguiente: "<<lista->siguiente<<endl;
            lista = lista->siguiente;
        }
    }
    cout<<endl;
}

void vaciarLista(Nodo *&lista){
    if(lista == NULL) cout<<"\nNo hay elementos en la lista."<<endl;
    else{
        cout<<"\nSacando todos los elementos de la lista.."<<endl;
        while(lista != NULL){
            Nodo *aux = lista;
            cout<<lista->dato<<" -> ";
            lista = aux->siguiente;
            delete aux;
        }
        cout<<"\nLa lista ha quedado vacia.";
    }
    cout<<endl<<endl;
}

void sumarElementos(Nodo *lista){
    if(lista == NULL) cout<<"\nNo hay elementos en la lista."<<endl;
    else{
        int sum = 0;
        while(lista != NULL){
            sum = sum + lista->dato;
            lista = lista->siguiente;
        }
        cout<<"\nLa suma de los elementos de la lista es: "<<sum<<endl<<endl;
    }
}

/*void editarElemento(Nodo *&lista){
    if (lista == NULL) cout<<"\nNo hay elementos en la lista";
    else{
        int n, nv;
        Nodo *aux = lista, *aux1 = lista, *aux3=lista, *aux2 = NULL, *aux4 = NULL;
        cout<<"Que elemento desea editar?: "; cin>>n;
        bool f=false;
        while(aux != NULL){
            if(aux->dato == n){
                cout<<"\nElemento encontrado en la posicion "<<aux<<endl;
                cout<<"Nuevo valor: "; cin>>nv;
                while(aux1->dato<nv and  aux1 !=NULL){
                    cout<<"aux2-> "<<aux2<<" ";
                    aux2 = aux1;
                    aux1 = aux1->siguiente;
                }
                while(aux3->dato<n){
                    aux4 = aux3;
                    aux3 = aux3->siguiente;
                }
                if(aux4->dato<nv and aux1->dato>nv){
                    aux->dato = nv;
                }
                else{
                    aux4->siguiente = aux->siguiente;
                    aux->dato = nv;
                    aux->siguiente = aux1;
                    //aux4->siguiente = aux3->siguiente;
                    aux2->siguiente = aux;
                }
                cout<<"Elemento editado satisfactoriamente.."<<endl;
                f=true;
                break;
            }
            aux = aux->siguiente;
        }
        if (f==false) cout<<"\nElemento no encontrado en la lista.";
    }
    cout<<endl<<endl;
}*/