#include <iostream>
using namespace std;
class Reloj{
	private:
		int hora,minutos,segundos;
	public:
		Reloj(){}
		Reloj(int hora,int min,int segu){
			this->hora=hora;
			this->minutos=min;
			this->segundos=segu;
		}
		void setHora(){
			int hora;
			cout<<"Ingresa la hora de tu reloj : "<<endl;
			cin>>hora;
			this->hora=hora;
		}
		void setMin(){
			int min;
			cout<<"Ingresa los minutos de tu reloj :"<<endl;
			cin>>min;
			this->minutos=min;
		}
		void setSegu(){
			int segundos;
			cout<<"Ingresa los segundos de tu reloj : "<<endl;
			cin>>segundos;
			this->segundos=segundos;
		}
		int getHora(){
			return this->hora;
		}
		int getMin(){
			return this->minutos;
		}
		int getSegu(){
			return this->segundos;
		}
		void print(){
			cout<<this->hora<<" : "<<this->minutos<<" : "<<this->segundos<<endl;
		}
		void Sincronizar(Reloj R){
			cout<<"Tu reloj Sincronizado : ";
			this->hora=R.getHora();
			this->minutos=R.getMin();
			this->segundos=R.getSegu();
		}
		void Comparar(Reloj R){
			int sum1 = (this->hora*3600)+(this->minutos*60)+(this->segundos);
			int sum2 = (R.getHora()*3600)+(R.getMin()*60)+(R.getSegu());
			if(this->hora!=R.getHora() || this->minutos!=R.getMin() || this->segundos!=R.getSegu()){
				if(sum1>sum2){
					cout<<"Tu reloj esta adelantado"<<endl;
					return;
				}
				else if (sum1<sum2){
					cout<<"Tu reloj esta atrasado"<<endl;
					return;
				}
			}
			cout<<"tu Reloj esta sincronizado"<<endl;	
		}
		
};
int main(){
	Reloj Sincronizado(12,03,40);
	Reloj Mireloj;
	Mireloj.setHora();
	Mireloj.setMin();
	Mireloj.setSegu();
	cout<<"Tu reloj: "<<endl;
	Mireloj.print();
	cout<<"Reloj de tu zona: "<<endl;
	Sincronizado.print();
	Mireloj.Comparar(Sincronizado);
	Mireloj.Sincronizar(Sincronizado);
	Mireloj.print();
	
	return 0;
}
