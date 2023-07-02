#include<iostream>
using namespace std;
class Deposito{
	private:
		string cliente;
		int dinero;
		int plazo;
		int retiro;
	public:
		Deposito(){
			this->cliente=" ";
			this->dinero=0;
			this->plazo=0;
			this->retiro=0;
		}
		Deposito(string nombre,int dinero,int plazo){
			this->cliente=nombre;
			this->dinero=dinero;
			this->plazo=plazo;
			this->retiro=0;
		}
	int RetirarPlazoCumplido(){
		 if(this->plazo == 30){
		 	this->retiro = this->dinero + this->dinero*0.05;
		 	this->dinero = 0;
		 	return this->retiro;
		 }
		 if(this->plazo == 60){
		 	this->retiro = this->dinero + this->dinero*0.1;
		 	this->dinero = 0;
		 	return this->retiro;
		 }
		 if(this->plazo == 90){
		 	this->retiro = this->dinero + this->dinero*0.2;
		 	this->dinero = 0;
		 	return this->retiro;
		 }
	}
	void RenovarDeposito(){
		this->dinero = this->retiro;
		int a;
		bool prendido=true;
		cout<<"Ingrese el plazo que desea"<<endl;
		while(prendido=true){
		cin>>a;
		if(a==30){
			this->plazo=a;
			prendido=false;
			return;
		}
		if(a==60){
			this->plazo=a;
			prendido=false;
			return;
		}
		if(a==90){
			this->plazo=a;
			prendido=false;
			return;
		}
		cout<<"Elija un plazo correcto."<<endl;
		}
	}
	int RetiroAnticipado(){
		this->retiro = this->dinero - (this->dinero*0.01);
		this->dinero = 0;
		return this->retiro;
	}
};
int main(){
	Deposito Cliente1("Eduardo",125000,30);
	cout<<"Has podido retirar : "<<Cliente1.RetiroAnticipado()<<endl;
	Cliente1.RenovarDeposito();
	cout<<"Con la renovacion has retirado: "<<Cliente1.RetirarPlazoCumplido()<<endl;
	
	return 0;
}
