#include <iostream>
#include <vector>
using namespace std;
class Empleado{
	protected:
		string nombre,ID;
		int sueldo,Rut;	
	public:
		Empleado(){
			nombre="";
			ID="";
			sueldo=0;
			Rut=0;
		}
		Empleado(string nombre,string ID,int sueldo,int Rut){
			this->nombre=nombre;
			this->ID=ID;
			this->sueldo=sueldo;
			this->Rut=Rut;
		}
		void Datos(){
			cout<<"Nombre : "<<this->nombre<<endl;
			cout<<"ID : "<<this->ID<<endl;
			cout<<"Sueldo : "<<this->sueldo<<endl;
			cout<<"Rut : "<<this->Rut<<endl;
		}
		void Cambiar_Sueldo(int sueldo){
			this->sueldo=sueldo;
		}
		void Info(){
			cout<<nombre<<endl;
			cout<<ID<<endl;
			cout<<sueldo<<endl;
			cout<<Rut<<endl;
		}
		int GetSueldo(){
			return this->sueldo;
		}
		string GetNombre(){
			return this->nombre;
		}
};
class Piloto : public Empleado{
		private:
			int anos_experiencia;
			bool licencia;
		public:
			Piloto() : Empleado(){
				anos_experiencia=0;
				licencia = NULL;
			}
			Piloto(string nombre,string ID,int sueldo,int Rut,int anos_experiencia,bool licencia) : Empleado(nombre,ID,sueldo,Rut){
				this->anos_experiencia = anos_experiencia;
				this->licencia = licencia;
			}
		void Obtener_datos(){
			cout<<nombre<<endl;
			cout<<ID<<endl;
			cout<<sueldo<<endl;
			cout<<Rut<<endl;
			cout<<anos_experiencia<<endl;
			if(licencia == true){
				cout<<"licencia vigente"<<endl;
				return;
			}
			cout<<"licencia vencida"<<endl;
			return;
		}	
		void Actualizar_anos(int anos){
			this->anos_experiencia=anos;
		}
		void Actualizar_licencia(bool licencia){
			this->licencia=licencia;
		}
		bool GetVigencia(){
			return this->licencia;
		}
};
class Tecnico : public Empleado{
	private:
		string titulo;
	public:
		Tecnico() : Empleado(){
			titulo=" ";
		}
		Tecnico(string titulo,string nombre,string ID,int sueldo,int rut) : Empleado(nombre,ID,sueldo,Rut){
			this->titulo=titulo;
		}	
	void Obtener_Datos_Tecnico(){
			cout<<nombre<<endl;
			cout<<ID<<endl;
			cout<<sueldo<<endl;
			cout<<Rut<<endl;
			cout<<titulo<<endl;
	}		
	string GetTitulo(){
		return this->titulo;
	}
};
string P_A(vector<Piloto>p){
	int mayor;
	string mayor1;
	for(int i=0;i<p.size();i++){
		if((p[i]).GetSueldo()>mayor){
			mayor1=(p[i]).GetNombre();
		}
	}
	return mayor1;
}
int L_V(vector<Piloto>p){
	int contador=0;
	for(int i=0;i<p.size();i++){
		if((p[i]).GetVigencia()==true){
			contador++;
		}
	}
	return contador;
}
void Best_Tc(vector<Tecnico>T){
	int ma=(T[0]).GetSueldo();
	int me=(T[0]).GetSueldo();
	string may=(T[0]).GetNombre();
	string men=(T[0]).GetNombre();
	for(int i=0;i<T.size();i++){
		if((T[i]).GetSueldo()>ma){
			may=(T[i]).GetNombre();
		}
	}
	for(int i=0;i<T.size();i++){
		if((T[i]).GetSueldo()<me){
			men=(T[i]).GetNombre();
		}
	}
	for(int i=0;i<T.size();i++){
		if(may == (T[i]).GetNombre()){
			cout<<"Mayor sueldo"<<endl;
			cout<<"Nombre : "<<may<<endl;
			cout<<"Titulo : "<<(T[i]).GetTitulo()<<endl;
		}
	}
	for(int i=0;i<T.size();i++){
		if(men == (T[i]).GetNombre()){
			cout<<"Menor sueldo"<<endl;
			cout<<"Nombre : "<<men<<endl;
			cout<<"Titulo : "<<(T[i]).GetTitulo()<<endl;
		}
	}
}
int main()
{
    vector<Piloto>Pilotos;
    vector<Tecnico>Tecnicos;
    Piloto P1("juan","KUWAYD72",1000000,125478722,6,true);
    Piloto P2("juanito","SNLAKD71",1250000,155428721,3,false);
    Piloto P3("pepa","POSAYEA77",1520000,101488712,10,true);
    Tecnico T1("tens","coscu","POSAPEA77",600000,151488712);
    Tecnico T2("opa","ivbai","POZAJEA30",700000,181488712);
    Tecnico T3("weaman","vladimir","POTAYEA55",800000,171488712);
    Pilotos.push_back(P1);
    Pilotos.push_back(P2);
    Pilotos.push_back(P3);
    Tecnicos.push_back(T1);
    Tecnicos.push_back(T2);
    Tecnicos.push_back(T3);
    cout<<"Piloto de mejor sueldo : "<<P_A(Pilotos)<<endl;
    cout<<"Pilotos con licencia vidente : "<<L_V(Pilotos)<<endl;
    Best_Tc(Tecnicos);
    return 0;
}
