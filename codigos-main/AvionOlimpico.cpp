#include<iostream>
using namespace std;
class Deportista{
	private:
		string nombre,especialidad;
		int sueldo;
	public:
		Deportista(){
			this->nombre=" ";
			this->especialidad=" ";
			this->sueldo=0;
		}
		Deportista(string nombre,string especialidad,int sueldo){
			this->nombre=nombre;
			this->especialidad=especialidad;
			this->sueldo=sueldo;
		}
		void SetNombre(string name){
			this->nombre=name;
		}
		void SetEspecia(string special){
			this->especialidad=special;
		}
		void SetSueldo(int sueldo){
			this->sueldo=sueldo;
		}
		string GetNombre(){
			return this->nombre;
		}
		string GetEspecia(){
			return this->especialidad;
		}
		int GetSueldo(){
			return this->sueldo;
		}
};
class AvionOlimpico{
	private:
		Deportista deportistas[100];
		bool Asientos[100];
	public:
		AvionOlimpico(){
		for(int i=0;i<100;i++){
			this->Asientos[i]=false;
		}
		}
		void IngresarDeportista(Deportista *dep){
			for(int i=0;i<100;i++){
				if(this->Asientos[i]==false){
					this->deportistas[i]=*dep;
					this->Asientos[i]=true;
					return;
				}
			}
		}
		void ImprimirComitiva(){
			for(int i=0;i<100;i++){
				if(this->Asientos[i]==true){
					cout<<"Asiento :"<<i+1<<" "<<deportistas[i].GetNombre()<<" / "<<deportistas[i].GetEspecia()<<" / "<<deportistas[i].GetSueldo()<<endl;
				}
			}
		}
};
int main(){
	Deportista Federer("Roger Federer","Tenis",200000);
	Deportista CR7("Cristiano Ronaldo","Futbol",120000);
	Deportista Messi("Lionel Messi","Futbol",150000);
	AvionOlimpico Boing771;
	Boing771.IngresarDeportista(&Federer);
	Boing771.IngresarDeportista(&Messi);
	Boing771.IngresarDeportista(&CR7);
	Boing771.ImprimirComitiva();
	return 0;
}

