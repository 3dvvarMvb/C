#include <iostream>
#include <vector>
using namespace std;
//VECTORES
/* 
vector<int> numeros;
vector<int> numeros(tamaño);
vector<int> numeros(tamaño,valor_inicial);
.push_back(elemento)->inserta un elemento al final del vector
.size()->retorna el tamaño del vector
.[n]->accede a la posicion n del vecto
.erase[n]->elimina el valor de la posicion n
.erase[n,n+3]->elimina los valores de la posicion n y n+3
.empy()-> retorna true si el vector esta vacio
.resize()->cambia el tamaño del vector
.back()->Retorna el ultimo valor del vector
.front()->retorna el primer elemento del vector
todos los metodos https://cplusplus.com/reference/vector/vector
*/
int main(){
	vector<int>numeros(5,0);
	for(int i=0;i<5;i++){
		numeros[i]=10;
	}
	for(int i=0;i<5;i++){
		cout<<numeros[i]<<" ";;
	}
	cout<<endl;
	cout<<"----------------------------"<<endl;
	numeros.push_back(4);
	for(int i=0;i<6;i++){
		cout<<numeros[i]<<" ";
	}
	return 0;
}
