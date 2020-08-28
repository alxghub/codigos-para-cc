//Programa Burbuja 6 procedimientos(burbuja clasica, burbuja clasica hasta j=n-i, burbuja con bandera, selección, inserción y QuickSort).
//arreglo dinámico o aleatorio.
//Reporte al final, debe mostrar al final el numero de iteraciones(pasadas) e intercambios con cada método.
//El tiempo solo funciona para windows :?..
//credit: DJS
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void burbujaClasica(int numeros[], int n){
	int aux,cont=0,c=0;
	cout<<"\n1. Burbuja Clasica:"<<endl;
	cout<<"Procedimiento de pasadas: "<<endl<<endl;
	clock_t t;
	t=clock();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(numeros[j]>numeros[j+1]){
				aux=numeros[j];
				numeros[j]=numeros[j+1];
				numeros[j+1]=aux;
				if(numeros[j]!=numeros[j+1]) c++;		
			}
			for(int z=0;z<n;z++) cout<<numeros[z]<<" ";
			
			cont=cont+1;
			cout<<endl;
		}
		cout<<endl;
	}
	t=clock()-t;
	cout<<"El numero de iteraciones fue: "<<cont<<endl;
	cout<<"Numero de intercambios: "<<c<<endl;
	cout<<"Tiempo en segundos: "<<float(t)/CLOCKS_PER_SEC<<endl;
	cout<<"-----------------------"<<endl<<endl;
	
}

void burbujaMejorada(int numeros[], int n){
	int aux,cont=0,c=0;
	cout<<"\n2. Burbuja Clasica hasta j=n-i:"<<endl;
	cout<<"Procedimiento de pasadas: "<<endl<<endl;
	clock_t t;
	t=clock();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(numeros[j]>numeros[j+1]){
				aux=numeros[j];
				numeros[j]=numeros[j+1];
				numeros[j+1]=aux;
				if(numeros[j]!=numeros[j+1]) c++;
			}
			for(int z=0;z<n;z++) cout<<numeros[z]<<" ";
			cont=cont+1;
			cout<<endl;
		}
		cout<<endl;
	}
	t=clock()-t;
	cout<<"El numero de iteraciones fue: "<<cont<<endl;
	cout<<"Numero de intercambios: "<<c<<endl;
	cout<<"Tiempo en segundos: "<<float(t)/CLOCKS_PER_SEC<<endl;
	cout<<"-----------------------"<<endl<<endl;
}

void burbujaConBandera(int numeros[], int n){
	int aux,flag,cont=0,c=0;
	clock_t t;
	t=clock();
	cout<<"\n3. Burbuja con bandera:"<<endl<<endl;
	cout<<"Procedimiento de pasadas: "<<endl<<endl;
	for(int i=0;i<n-1;i++){
		flag=0;
		for(int j=0;j<n-i-1;j++){
			if(numeros[j]>numeros[j+1]){
				aux=numeros[j];
				numeros[j]=numeros[j+1];
				numeros[j+1]=aux;
				flag=1;
				if(numeros[j]!=numeros[j+1]) c++;
			}
			for(int z=0;z<n;z++) cout<<numeros[z]<<" ";
			cont++;
			cout<<endl;
		}
		if (flag==0) break;
		cout<<endl;
	}
	t=clock()-t;
	cout<<"\nEl numero de iteraciones fue: "<<cont<<endl;
	cout<<"Numero de intercambios: "<<c<<endl;
	cout<<"Tiempo en segundos: "<<float(t)/CLOCKS_PER_SEC<<endl;
	cout<<"-----------------------"<<endl<<endl;
}

void seleccion(int numeros[], int n){
	int min,aux,i=0,p=0;
	cout<<"\n4. Seleccion:"<<endl;
	cout<<"Procedimiento de pasadas: "<<endl<<endl;
	clock_t t;
	t=clock();
	for(int c=0;c<n-1;c++){
		min=c;
		for(int j=c+1;j<n;j++){
			if(numeros[j]<numeros[min]){
				min=j;
			}
			for(int z=0;z<n;z++) cout<<numeros[z]<<" ";
			cout<<endl;
			p++;
		}
		cout<<endl;
		aux=numeros[c];
		numeros[c]=numeros[min];
		numeros[min]=aux;
		
		if(numeros[c]!=numeros[min]) i++;
	}
	t=clock()-t;
	cout<<"El numero de iteraciones fue: "<<p<<endl;
	cout<<"Numero de intercambios: "<<i<<endl;
	cout<<"Tiempo en segundos: "<<float(t)/CLOCKS_PER_SEC<<endl;
	cout<<"-----------------------"<<endl<<endl;
}

void insercion(int numeros[],int n){
	int aux,pos,p=0,i=0;
	cout<<"\n5. Insercion: "<<endl;
	cout<<"Procedimiento de pasadas: "<<endl<<endl;
	clock_t t;
	t=clock();
	for(int c=0;c<n;c++){
		pos=c;
		aux=numeros[c]; 						
		while(pos>0 and numeros[pos-1]>aux){ 	
			numeros[pos]=numeros[pos-1];
			pos--;	
			for(int z=0;z<n;z++) cout<<numeros[z]<<" ";
			cout<<endl;
			p++;					
		}
		numeros[pos]=aux;
		for(int z=0;z<n;z++) cout<<numeros[z]<<" ";	
		cout<<endl;
		p++;
		if(numeros[c]!=numeros[pos]) i++;
	}	
	t=clock()-t;
	cout<<"\nEl numero de iteraciones fue: "<<p<<endl;
	cout<<"Numero de intercambios: "<<i<<endl;
	cout<<"Tiempo en segundos: "<<float(t)/CLOCKS_PER_SEC<<endl;
	cout<<"-----------------------"<<endl<<endl;
}

void QuickSort(int*numeros,int low,int high,int top,int&p,int&k){
    int i=low,j=high,pivot=numeros[(i+j)/2],temp;
    while (i<=j){
        while(numeros[i]<pivot)
            i++;
        while(numeros[j]>pivot)
            j--;
        if (i<=j){
            temp=numeros[i];
            numeros[i]=numeros[j];
            numeros[j]=temp;
            if(numeros[i]!=numeros[j]) k++;
            i++;
            j--;
			cout<<endl;
			for(int c=0;c<top;c++) cout<<numeros[c]<<" ";
			p++;
        }
    }
    if (j>low) QuickSort(numeros,low,j,top,p,k);
    if (i<high) QuickSort(numeros,i,high,top,p,k);	
}

int main(){
	srand(time(0));
	int n,opc1=0,opc2=0,p=0,k=0;
	cout<<"Cantidad de elementos del arreglo: "; cin>>n;
	int numeros[n],numeros2[n],numeros3[n],numeros4[n],numeros5[n],numeros6[n];
	clock_t s;
	while(opc1!=3 and (opc1<1 or opc1>2)){
		//system("pause");
		//system("cls");
		cout<<"1. Ingresar elementos manualmente"<<endl;
		cout<<"2. Ingresar elementos aleatorios"<<endl;
		cout<<"3. SALIR"<<endl;
		cout<<"Elija una opcion: ";cin>>opc1;
		switch(opc1){
			case 1:
				for(int i=0; i<n;i++){
					cout<<"Ingrese un numero: ";cin>>numeros[i];
					numeros2[i]=numeros[i];
					numeros3[i]=numeros[i];
					numeros4[i]=numeros[i];
					numeros5[i]=numeros[i];
					numeros6[i]=numeros[i];
				}
			break;
			case 2:
				for(int i=0;i<n;i++){
					numeros[i]=1+rand()%200;
					numeros2[i]=numeros[i];
					numeros3[i]=numeros[i];
					numeros4[i]=numeros[i];
					numeros5[i]=numeros[i];
					numeros6[i]=numeros[i];	
				}
			break;
			case 3: cout<<"\nSaliendo..."<<endl;break;
			default: cout<<"Opcion no encontrada, intente de nuevo..."<<endl;	
			break;
		}
	}
	
	while((opc1==1 or opc1==2) and (opc2!=8 and opc2<1 or opc2>8)){
		//system("pause");
		//system("cls");	
		cout<<"\nNumeros que se van a ordenar:"<<endl;
		for(int i=0;i<n;i++){
			cout<<numeros[i]<<" ";
		}	
		cout<<"\n\nMetodos de ordenamiento para elegir:"<<endl;
		cout<<"------------------------------------"<<endl;
		cout<<"1. Burbuja Clasica"<<endl;
		cout<<"2. Burbuja Clasica hasta j=n-i"<<endl;
		cout<<"3. Burbuja Clasica con bandera"<<endl;
		cout<<"4. Seleccion"<<endl;
		cout<<"5. Insercion"<<endl;
		cout<<"6. QuickSort"<<endl;
		cout<<"7. TODOS LOS METODOS"<<endl;
		cout<<"8. SALIR"<<endl;
		cout<<"Elija una opcion: ";cin>>opc2;
		//system("pause");
		//system("cls");
		if(opc2>=1 and opc2<=7){
			cout<<"Antes:"<<endl;
			for(int i=0;i<n;i++) cout<<numeros[i]<<" ";
		} 
		cout<<endl;
		switch(opc2){
			case 1: burbujaClasica(numeros,n);break;
			case 2: burbujaMejorada(numeros2,n);break;
			case 3:	burbujaConBandera(numeros3,n);break;
			case 4:seleccion(numeros4,n);break;
			case 5:insercion(numeros5,n);break;
			case 6:
				cout<<"\n6. QuickSort: "<<endl;
				s=clock();
				QuickSort(numeros6,0,n-1,n,p,k);
				s=clock()-s;
				cout<<"\n\nNumero de iteracciones:"<<p<<endl;
				cout<<"Numero de intercambios: "<<k<<endl;
				cout<<"Tiempo en segundos: "<<float(s)/CLOCKS_PER_SEC<<endl;
				cout<<"-----------------------"<<endl;
			break;
			case 7:
				cout<<"TODOS LOS METODOS:"<<endl;
				cout<<"------------------"<<endl<<endl;
				burbujaClasica(numeros,n);
				burbujaMejorada(numeros2,n);
				burbujaConBandera(numeros3,n);
				seleccion(numeros4,n);
				insercion(numeros5,n);
				cout<<"\n6. QuickSort: "<<endl;
				s=clock();
				QuickSort(numeros6,0,n-1,n,p,k);
				s=clock()-s;
				cout<<"\n\nNumero de iteracciones:"<<p<<endl;
				cout<<"Numero de intercambios: "<<k<<endl;
				cout<<"Tiempo en segundos: "<<float(s)/CLOCKS_PER_SEC<<endl;
				cout<<"-----------------------"<<endl;
			break;
			case 8: cout<<"Saliendo..."<<endl;break;
			default: cout<<"Opcion no encontrada, intente de nuevo..."<<endl;break;	
		}	
	}
    cin.ignore();
    cin.get();
	return 0;
}