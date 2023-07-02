#include <iostream>
using namespace std;
class Grupo{
	private:
		string nombre;
		int integrantes;
		int cobro;
	public:
		Grupo(){
			this->nombre="";
			this->integrantes=0;
			this->cobro=10000;
		}
		Grupo(string nombre,int integrantes){
			this->nombre=nombre;
			this->integrantes=integrantes;
			this->cobro=10000;
		}		
		void SetCobro(){
			if(this->integrantes>=3){
				this->cobro = (this->cobro*this->integrantes)- (this->cobro*this->integrantes)*0.10;
			}	
		}
		void MostrarGrupo(){
			cout<<"Nombre del Representante : "<<this->nombre<<endl;
			cout<<"Numero de integrantes : "<<this->integrantes<<endl;
			cout<<"Precio del bloque : "<<this->cobro<<endl;
		}
};
class Agenda{
	private:
		Grupo *Grupos[10];
	public:
		Agenda(){
			for(int i=0;i<10;i++){
				Grupos[i]=NULL;
			}
		}
		void LlenarBloque(Grupo *O,int n){
			if(Grupos[n] == NULL){
				this->Grupos[n]=O;
				cout<<"Bloque Elegido correctamente"<<endl;
				return;
			}
			cout<<"Lo lamentamos pero ese bloque esta en uso"<<endl;
		}
		void Llenar(Grupo *G){
			for(int i=0;i<10;i++){
				if(Grupos[i] == NULL){
					Grupos[i]=G;
					cout<<"Grupo agregado con exito"<<endl;
					return;
				}	
			}
		}
		void ImprimirGrupos(){
			for(int i=0;i<10;i++){
				if(this->Grupos[i]!=NULL){
					cout<<"Bloque numero : "<<i<<endl;
					this->Grupos[i]->MostrarGrupo();
					cout<<endl;
					cout<<"-----------------------------------------"<<endl;
				}
			}
		}	
};
int main(){
	Grupo *grupito1 = new Grupo("Juan",4);
	grupito1->SetCobro();
	Agenda *Profe=new Agenda;
	Profe->LlenarBloque(grupito1,3);
	Profe->ImprimirGrupos();
	return 0;
}