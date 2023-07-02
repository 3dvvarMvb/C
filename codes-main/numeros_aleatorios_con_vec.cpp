#include <iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>
using namespace std;
void mostrar_valores_extremos(vector<int>O){
	int max,min;
	max=O[0];
	min=O[0];
	for(int i=0;i<O.size();i++){
		if(O[i]<min){
			min=O[i];
		}
	}
	for(int i=0;i<O.size();i++){
		if(O[i]>max){
			max=O[i];
		}
	}
	cout<<"minimo : "<<min<<endl;
	cout<<"maximo : "<<max<<endl;
}
int main(){
	vector<int>NM(10);
	srand(time(NULL));
	for(int i=0;i<NM.size();i++){
		NM[i]=rand()%101;
	}
	for(int i=0;i<NM.size();i++){
		cout<<NM[i]<<endl;
	}
	mostrar_valores_extremos(NM);
	cout<<endl;
	NM.push_back(300);
	cout<<"-----------------------------------------"<<endl;
	cout<<"con el nuevo valor agregado"<<endl;
	mostrar_valores_extremos(NM);
	return 0;
}
