#include<iostream>
using namespace std;
class Fraccion{
	private:
		int numerador;
		int denominador;
	public:
	Fraccion(){
		this->numerador=0;
		this->denominador=1;
	}
	Fraccion(int numerador,int denominador){
		this->numerador=numerador;
		this->denominador=denominador;
	}	
	void SetNumerador(int numerador){
		this->numerador=numerador;
	}
	void SetDenominador(int denominador){
		this->denominador=denominador;
	}
	int GetNumerador(){return this->numerador;}
	int GetDenominador(){return this->denominador;}
	void Imprimir(){
		cout<<this->numerador<<" / "<<this->denominador<<endl;
	}
	void Simplificar(){
		int min = 2;
    	if (this->denominador > 1) {
        while (min <= this->numerador) {
            if ((this->numerador % min) == 0 && (this->denominador % min) == 0) {
                this->numerador /= min;
                this->denominador /= min;
            	}
            else
                min++;
        	}
    	}
	}
	void SumarFracciones(Fraccion fr1,Fraccion fr2){
		int NuevoNum,NuevoDem;
		NuevoNum=(fr1.GetNumerador()*fr2.GetDenominador())+(fr2.GetNumerador()*fr1.GetDenominador());
		NuevoDem=(fr1.GetDenominador()*fr2.GetDenominador());
		Fraccion Resultado(NuevoNum,NuevoDem);
		Resultado.Simplificar();
		Resultado.Imprimir();
	}
};
int main(){
	Fraccion Fr1(2,4);
	Fraccion Fr2(1,2);
	Fraccion suma;
	suma.SumarFracciones(Fr1,Fr2);
	return 0;
}

