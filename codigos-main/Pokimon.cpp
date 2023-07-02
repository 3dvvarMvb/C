#include <iostream>
using namespace std;
class Pokemon{
	private:
		string nombre;
		string tipo;
		int nivel;
	public:
	Pokemon(){}
	Pokemon(string nombre,string tipo,int nivel){
		this->nombre = nombre;
		this->tipo = tipo;
		this->nivel = nivel;
	}
	void SetNombre(){
		string Nombre;
		cin>>Nombre;
		this->nombre = Nombre;
	}	
	void SetTipo(){
		string Tipo;
		cin>>Tipo;
		this->tipo = Tipo;
	}
	void SetNivel(){
		int x;
		cin>>x;
		this->nivel = x;
	}
	string GetNombre(){
		return this->nombre;
	}	
	string GetTipo(){
		return this->tipo;
	}
	int GetNivel(){
		return this->nivel;
	}
	void CarameloRaro(){
		this->nivel++;
	}
	void GetDatos(){
		cout<<"Nombre : "<<this->nombre<<endl;
		cout<<"Tipo : "<<this->tipo<<endl;
		cout<<"Nivel : "<<this->nivel<<endl;
	}
};
void SubirDeNivel(Pokemon Pokemon[],int tamanio){
	for(int i=0;i<tamanio;i++){
		Pokemon[i].CarameloRaro();
	}
}
int main(){
	Pokemon Equipo[3];
	for(int i=0;i<3;i++){
		cout<<"Pokemon n° : "<<i+1<<endl;
		Equipo[i].SetNombre();
		Equipo[i].SetTipo();
		Equipo[i].SetNivel();
	}
	cout<<endl;
	for(int i=0;i<3;i++){
		cout<<"Pokemon n° : "<<i+1<<endl;
		cout<<Equipo[i].GetNombre()<<endl;
		cout<<Equipo[i].GetTipo()<<endl;
		cout<<Equipo[i].GetNivel()<<endl;
	}
	cout<<"Se ha consumido un caramelo en todos tus pokemon"<<endl;
	SubirDeNivel(Equipo,3);
	cout<<endl;
	for(int i=0;i<3;i++){
		cout<<"Pokemon n° : "<<i+1<<endl;
		cout<<Equipo[i].GetNombre()<<endl;
		cout<<Equipo[i].GetTipo()<<endl;
		cout<<Equipo[i].GetNivel()<<endl;
	}
	return 0;
}
