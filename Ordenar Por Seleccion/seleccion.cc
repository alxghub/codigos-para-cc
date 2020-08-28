#include <iostream>
using namespace std;

int main(){
    int nums[]={2,39,17,5,15};
    int min,aux,pasada=0,swap=0,n=5;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(nums[j]<nums[min]){
                min=j;
            }
            pasada++;
        }
        aux=nums[i];
        nums[i]=nums[min];
        nums[min]=aux;
        swap++;
    }
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    cout<<"El numero de pasadas es: "<<pasada<<endl;
    cout<<"El numero de intercambios es: "<<swap<<endl;
    cin.get();
    return 0;
}