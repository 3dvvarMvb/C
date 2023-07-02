#include<iostream>
using namespace std;
class PuntoMuestreo{
	private:
		string nombre;
		float PH;
		int codigo;
		float tem;
	public:
		PuntoMuestreo(){
		this->codigo=0;
		this->PH=0;
		this->tem=0;
		this->nombre=" ";
		}
		PuntoMuestreo(int codigo,float PH,float tem, string nombre){
			this->codigo=codigo;
			this->PH=PH;
			this->tem=tem;
			this->nombre=nombre;
		}
		void SetNombre(string nombre){this->nombre=nombre;}
		
		void SetPH(float PH){this->PH=PH;}
		
		void SetCodigo(int codigo){this->codigo=codigo;}
		
		void SetTem(float tem){this->tem=tem;}
		
		string GetNombre(){return this->nombre;}
		
		float GetPH(){return this->PH;}
		
		int GetCodigo(){return this->codigo;}
		
		float GetTem(){return this->tem;}
		
		void ImprimirPM(){
			cout<<"Nombre : "<<this->nombre<<endl;
			cout<<"PH : "<<this->PH<<endl;
			cout<<"Temperatura : "<<this->tem<<endl;
			cout<<"Codigo : "<<this->codigo<<endl;
			cout<<"-----------------------------------------"<<endl;
		}
};
class PlantaIndustrial{
	private:
		PuntoMuestreo Puntos[12];
		int codigo[12];
		string nombre[12];
		int NumeroRegion[12];
		bool PMR[12];
	public:	
		PlantaIndustrial(){
			for(int i=0;i<12;i++){
				this->codigo[i]=0;
				this->nombre[i]=" ";
				this->NumeroRegion[i]=0;
				this->PMR[i]=false;
			}
		}
		void AgregarPunto(PuntoMuestreo *Punto){
			for(int i=0;i<12;i++){
				if(this->PMR[i]==false){
					this->Puntos[i]=*Punto;
					this->PMR[i]=true;
					break;
				}
			}
		}
		void SetCodigo(int codigo){
		for(int i=0;i<12;i++){
		if(this->PMR[i]==true){
			this->codigo[i]=codigo;
			break;
		}}
		}
		void SetNombre(string nombre){
		for(int i=0;i<12;i++){
		if(this->PMR[i]==true){
			this->nombre[i]=nombre;
			break;
		}}
		}
		void SetNumeroRegion(int numero){
		for(int i=0;i<12;i++){
		if(this->PMR[i]==true){
			this->NumeroRegion[i]=numero;
			break;
		}}	
		}
		int GetCodigo(int puesto){
		return this->codigo[puesto];	
		}
		string GetNombre(int puesto){
		return this->nombre[puesto];	
		}
		int GetNumeroRegion(int puesto){
		return this->NumeroRegion[puesto];	
		}
		void ImprimirPMR(){
			for(int i=0;i<12;i++){
				if(this->PMR[i]==true){
					Puntos[i].ImprimirPM();
				}
			}
		}
};
int main(){
	PuntoMuestreo puntito1(123,3,40,"Punto 1");
	PuntoMuestreo puntito2(321,8,20,"Punto 2");
	PuntoMuestreo puntito3(987,5,27.5,"Punto 3");
	PlantaIndustrial Planta1;
	Planta1.AgregarPunto(&puntito1);
	Planta1.AgregarPunto(&puntito2);
	Planta1.AgregarPunto(&puntito3);
	Planta1.ImprimirPMR();
	return 0;
}
