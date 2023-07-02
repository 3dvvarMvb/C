#include <iostream>
using namespace std;
class MisNotas{
	private:
		float notas[10]={0};
	public:	
		MisNotas(){
		}	
	void AgregarNotas(float nota){
		float tem;
		for(int i=0;i<10;i++){
			for(int j=i+1;j<10;j++){
				if(this->notas[j]<this->notas[i]){
					tem=this->notas[i];
					this->notas[i]=this->notas[j];
					this->notas[j]=tem;
				}
			}
			
		}
		for(int i=0;i<10;i++){
			if(this->notas[i]==0){
				this->notas[i]=nota;
				return;
			}
		}
		this->notas[0] = nota;
	}
	void LlenarNotas(){
		float nota;
		for(int i=0;i<10;i++){
			cin>>nota;
			this->notas[i] = nota;
		}
	}	
	void MostraNotas(){
		for(int i=0;i<10;i++){
			cout<<this->notas[i]<<"  ";
		}
		cout<<endl;
	}
};
int main(){	
	MisNotas Estudiante;
	Estudiante.MostraNotas();
	Estudiante.AgregarNotas(1);
	Estudiante.MostraNotas();
	return 0;
}
