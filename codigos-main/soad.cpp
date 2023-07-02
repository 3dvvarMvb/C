#include <iostream>
using namespace std;
int main(){
	int arr[6]={6,4,5,2,1,3};
	int *maximo,*minimo;//crean variables especiales que solo guardan direcciones
	minimo=&arr[0];//& = a la direccion de la variable que esta a su derecha 
	maximo=&arr[0];
	for(int i=0;i<6;i++){
		if(*maximo<arr[i]){//si el valor que esta en el puntero maximo es menor a el valor del arr en i entonces cambian
			maximo=&arr[i];
		}
		if(*minimo>arr[i]){//si el valor que esta en el puntero minimo es mayor al valor del arr en i entonces cambian
			minimo=&arr[i];
		}
	}
	cout<<"maximo : "<<*maximo<<endl;//si volvemos a poner * en un puntero va a retornar el valor dentro de la direccion apuntada
	cout<<"minimo : "<<*minimo<<endl;
	return 0;
}
