#include <iostream>
using namespace std;
class Alcancia{
	private:
	int monto, ngiro, ndepo;
	public:
		Alcancia (){ 
		this->monto=0;
		this->ngiro=0;
		this->ndepo=0;
		}
		bool setMonto(int monto){
			if(monto>0){
				this->monto=monto;
				return 1;
			}
			return 0;
		}
		int getMonto(){
			return this->monto;
		}
		int getGiro(){
			return this->ngiro;
		}
		int getDepo(){
			return this->ndepo;
		}
		void Guardar(){
			int monto;
			cin>>monto;
			if(monto>0){
				this->monto+=monto;
				this->ndepo++;
			}
			else cout<<"Monto erroneo"<<endl;
		}
		void Sacar(){
			int monto;
			cin>>monto;
			int res=this->monto-monto;
			if(res>0){
				this->monto=res;
				this->ngiro++;
			}
			else cout<<"saldo insuficiente"<<endl;
		}
};
int main(){
	bool opcion=0;
	Alcancia mialcancia;
	while(opcion==0){
		char a;
		cout<<"A)Depositar en la alcancia"<<endl;
		cout<<"B)Sacar de la alcancia"<<endl;
		cout<<"C)Ver datos de la alcancia"<<endl;
		cout<<"D)Numero de giros y depositos"<<endl;
		cout<<"E)Salir del sistema"<<endl;
		cin>>a;
		if(a=='A'){
			mialcancia.Guardar();
		}
		else if(a=='B'){
			mialcancia.Sacar();
		}
		else if(a=='C'){
			cout<<"Monto: "<<mialcancia.getMonto()<<endl;
		}
		else if(a=='D'){
			cout<<"Numero de depositos: "<<mialcancia.getDepo()<<endl;
			cout<<"Numero de giros: "<<mialcancia.getGiro()<<endl;
		}
		else if(a=='E'){
			opcion=1;
		}
	}
	return 0;
}
