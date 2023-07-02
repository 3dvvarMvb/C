#include <iostream>
#include <string>
using namespace std;
class Elefante{
	private:
		string nombre, lugar;
		int edad;
	public:
	Elefante (){}	
	Elefante (string nombre, string lugar, int edad){
		this->edad=edad;
		this->nombre=nombre;
		this->lugar;
	}	
	void setNombre(string nombre){
		this->nombre=nombre;
	}
	void setEdad(int edad){
		this->edad=edad;
	}
	void setLugar(string lugar){
		this->lugar=lugar;
	}
	int getEdad(){
		return this->edad;
	}
	void print_E(){
		cout<<"Este es el elefante : "<<this->nombre<<" Edad: "<<this->edad<<endl;
	}
};
class Leon{
	private:
		string nombre, lugar;
		int edad;
	public:
	Leon (){}	
	Leon (string nombre, string lugar, int edad){
		this->edad=edad;
		this->nombre=nombre;
		this->lugar;
	}	
	void setNombre(string nombre){
		this->nombre=nombre;
	}
	void setEdad(int edad){
		this->edad=edad;
	}
	void setLugar(string lugar){
		this->lugar=lugar;
	}
	int getEdad(){
		return this->edad;
	}
	void print_L(){
		cout<<"Este es el Leon : "<<this->nombre<<" Edad: "<<this->edad<<endl;
	}
};
class Cebra{
	private:
		string nombre, lugar;
		int edad;
	public:
	Cebra (){}	
	Cebra (string nombre, string lugar, int edad){
		this->edad=edad;
		this->nombre=nombre;
		this->lugar;
	}	
	void setNombre(string nombre){
		this->nombre=nombre;
	}
	void setEdad(int edad){
		this->edad=edad;
	}
	void setLugar(string lugar){
		this->lugar=lugar;
	}
	int getEdad(){
		return this->edad;
	}
	void print_C(){
		cout<<"Esta es la Cebra : "<<this->nombre<<" Edad: "<<this->edad<<endl;
	}
};
class Zoo{
	private:
		string nombre;
		Elefante elefantes[20];
		Leon leones[20];
		Cebra cebras[20];
	public:
		Zoo(){}	
		Zoo (Leon leones[20],Elefante elefantes[20],Cebra cebras[20],string nombre){
			this->nombre=nombre;
			this->elefantes[20]=elefantes[20];
			this->leones[20]=leones[20];
			this->cebras[20]=cebras[20];
		}
		void setNombre_Zoo(string nombre_zoo){
			this->nombre=nombre_zoo;
		}
		void setElefantes(){
			for(int i=0;i<20;i++){
				string nombre,lugar;
				int edad;
				cout<<"ingresa el nombre,lugar de origen y edad del animal ;Elefante n: "<<i+1<<endl;
				cin>>nombre>>lugar;
				cin>>edad;
				this->elefantes[i].setNombre(nombre);
				this->elefantes[i].setEdad(edad);
				this->elefantes[i].setLugar(lugar);
			}
		}
		void setLeones(){
			for(int i=0;i<20;i++){
				string nombre,lugar;
				int edad;
				cout<<"ingresa el nombre,lugar de origen y edad del animal ;Leon n: "<<i+1<<endl;
				cin>>nombre>>lugar;
				cin>>edad;
				this->leones[i].setNombre(nombre);
				this->leones[i].setEdad(edad);
				this->leones[i].setLugar(lugar);
			}
		}
		void setCebras(){
			for(int i=0;i<20;i++){
				string nombre,lugar;
				int edad;
				cout<<"ingresa el nombre,lugar de origen y edad del animal ;Cebra n:"<<i+1<<endl;
				cin>>nombre>>lugar;
				cin>>edad;
				this->cebras[i].setNombre(nombre);
				this->cebras[i].setEdad(edad);
				this->cebras[i].setLugar(lugar);
			}
		}
		void print_zoo(){
			for(int i=0;i<20;i++){
				this->elefantes[i].print_E();
				this->leones[i].print_L();
				this->cebras[i].print_C();
			}
		}
		void Sum_edades(int sum1,int sum2,int sum3){
			for(int i=0;i<20;i++){
				sum1+=this->elefantes[i].getEdad();
				sum2+=this->leones[i].getEdad();
				sum3+=this->cebras[i].getEdad();
			}
			cout<<"la suma de las edades de los Elefantes es :"<<sum1<<endl;
			cout<<"la suma de las edades de los Leones es :"<<sum2<<endl;
			cout<<"la suma de las edades de las Cebras es :"<<sum3<<endl;
		}
		
};
int main(){
	Zoo BuinZoo;
	BuinZoo.setNombre_Zoo("Buin Zoo");
	BuinZoo.setElefantes();
	BuinZoo.setLeones();
	BuinZoo.setCebras();
	BuinZoo.print_zoo();
	BuinZoo.Sum_edades(0,0,0);
	
	return 0;
}
