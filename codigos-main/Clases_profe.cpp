#include<iostream>
using namespace std;
class Grupo{
	private:
		int numeroalumnos;
		string nombre;
		int telefono;
		int costo;
	public:
		Grupo(){
			this->nombre="";
			this->telefono=0;
			this->numeroalumnos=0;
			for(int i=0;i<10;i++){
			this->costo=0;
		}
		}
		Grupo(int numeroA,string nombre,int telefono){
			this->numeroalumnos=numeroA;
			this->nombre=nombre;
			this->telefono=telefono;
		}
		void setcosto(){
			if(this->numeroalumnos>=3){
				int nuevo_costo=(10000*this->numeroalumnos)-((10000*this->numeroalumnos)*0.2);
				this->costo= nuevo_costo;
				return;
			}
			this->costo=(10000*this->numeroalumnos);
		}
		int getcosto(){
			return this->costo;
		}
		void imprimir(){
			cout<<"Nombre : "<<this->nombre<<endl;
			cout<<"Telefono : "<<this->telefono<<endl;
			cout<<"Numero de estudiantes : "<<this->numeroalumnos<<endl;
			cout<<"Costo De la clase: "<<this->costo<<endl;
		}
		void setNalumnos(int nalumnos){
			this->numeroalumnos=nalumnos;
		}
		int getNalumnos(){
			return this->numeroalumnos;
		}
		void llenar_datos(){
			int a,b;
			string z;
			cout<<"ingresa el numero de alumnos, telefono y nombre en ese orden"<<endl;
			cin>>a>>b>>z;
			this->numeroalumnos=a;
			this->telefono=b;
			this->nombre=z;
		}
};
class Agenda{
	private:
		Grupo grupos[10];
		bool dispo[10];
	public:
		Agenda(){
			for(int i=0;i<10;i++){
				this->dispo[i]=true;
			}
		}
	bool AgregarGrupo(Grupo *gx){
		for(int i=0;i<10;i++){
			if(this->dispo[i]==true){
				this->grupos[i] = *gx;
				this->dispo[i]= false;
				break;
				return true;
			}
		}	
		return false;
	}
	void imprimir_grupos(){
		for(int i=0;i<10;i++){
			cout<<"Bloque :"<<i+1<<endl;
			grupos[i].setcosto();
			grupos[i].imprimir();
			cout<<"---------------------------------------------"<<endl;
		}
	}
	int recaudacion_diaria(){
		int rec;
		for(int i=0;i<10;i++){
			rec+=this->grupos[i].getcosto();
		}
		return rec;
	}	
};
int main(){
	Grupo desig(3,"Ana",973726113);
	Grupo grupos1[2];
	for(int i=0;i<2;i++){
		grupos1[i].llenar_datos();
	}
	Agenda agendadiaria;
	agendadiaria.AgregarGrupo(&desig);
	for(int i=0;i<2;i++){
		agendadiaria.AgregarGrupo(&grupos1[i]);
	}
	cout<<endl;
	agendadiaria.imprimir_grupos();
	cout<<endl;
	cout<<"la recaudacion diaria es de : "<<agendadiaria.recaudacion_diaria();
	return 0;
}
