#include<iostream>
using namespace std;
class Hamburguesa{
	private:
		bool vegetariana=0;
		bool lechuga=0;
		bool queso=0;
		bool tomate=0;
		bool pepinillos=0;
		bool beacon=0;
		bool cebolla=0;
		int precio=0;
	public:
	Hamburguesa(){}
	Hamburguesa(bool vegetariana,bool lechuga,bool queso,bool tomate,bool pepinillos,bool beacon,bool cebolla,int precio){
		this->vegetariana = vegetariana;
		this->lechuga = lechuga;
		this->queso = queso;
		this->tomate = tomate;
		this->pepinillos = pepinillos;
		this->beacon = beacon;
		this->cebolla = cebolla;
		this->precio = precio;
	}
	void setvege(){
		this->vegetariana=!this->vegetariana;
	}	
	void setlechuga(){
		this->lechuga=!this->lechuga;
	}
	void setqueso(){
		this->queso=!this->queso;
	}
	void settomate(){
		this->tomate=!this->tomate;
	}
	void setpepinillos(){
		this->pepinillos=!this->pepinillos;
	}
	void setbeacon(){
		if(this->vegetariana==1){
			cout<<"lo lamentamos pero no puedes agregar este ingrediente";
			return;
		}
		this->beacon=!this->beacon;
	}
	void setcebolla(){
		this->cebolla=!this->cebolla;
	}
	void setprecio(){
		if(this->vegetariana==1){
			(this->precio)+=2500;
		}
		this->precio+=2000;
		if(this->lechuga==1){
			this->precio+=500;
		}
		if(this->queso==1){
			this->precio+=400;
		}
		if(this->tomate==1){
			this->precio+=400;
		}
		if(this->pepinillos==1){
			this->precio+=600;
		}
		if(this->beacon==1){
			this->precio+=1200;
		}
		if(this->cebolla==1){
			this->precio+=400;
		}
	}
	void getinfo(){
		if(this->vegetariana==1){
			cout<<"tu base es vegetariana"<<endl;
		}
		else cout<<"tu base es de vacuno"<<endl;
		if(this->lechuga==1){
			cout<<"Ingrediente Lechuga+1"<<endl;
		}
		if(this->queso==1){
			cout<<"Ingrediente Queso+1"<<endl;
		}
		if(this->tomate==1){
			cout<<"Ingrediente Tomate+1"<<endl;
		}
		if(this->pepinillos==1){
			cout<<"Ingrediente Pepinillos+1"<<endl;
		}
		if(this->beacon==1){
			cout<<"Ingrediente Beacon+1"<<endl;
		}
		if(this->cebolla==1){
			cout<<"Ingrediente Cebolla+1"<<endl;
		}
	}
	int getPrecio(){
		return this->precio;
	}
	
};
int main(){
	char a,b,c,d;
	bool wea=0;
	Hamburguesa McWea(0,0,1,0,0,0,0,2500);
	Hamburguesa McWeaPlus(0,1,1,1,1,1,1,5850);
	Hamburguesa McWeaVeggie(1,1,1,1,1,0,1,4650);
	Hamburguesa Perso;
	cout<<"Bienvenido a McWeas"<<endl;
	cout<<"a)Menu"<<endl;
	cout<<"b)Hamburguesa a tu medida"<<endl;
	cin>>a;
	if(a=='a'){
		cout<<"a)McWea"<<endl;
		cout<<"b)McWeaPlus"<<endl;
		cout<<"c)McWeaVeggie"<<endl;
		cin>>b;
		if(b =='a'){
			McWea.getinfo();
		}
		else if(b =='b'){
			McWeaPlus.getinfo();
		}
		else if(b =='c'){
			McWeaVeggie.getinfo();
		}
		else cout<<"ingresa una opcion valida"<<endl;
	}
	else if(a=='b'){
		cout<<"Base de vacuno"<<endl;
		cin>>c;
		if(c=='y'){
			while(wea==0){
				cout<<"a)lechuga"<<endl;
				cout<<"b)tomate"<<endl;
				cout<<"c)queso"<<endl;
				cout<<"d)pepinillos"<<endl;
				cout<<"e)cebolla"<<endl;
				cout<<"f)beacon"<<endl;
				cout<<"g)no deseo agregar nada mas"<<endl;
				cin>>d;
				if(d=='a'){
					Perso.setlechuga();
				}
				else if(d=='b'){
					Perso.settomate();
				}
				else if(d=='c'){
					Perso.setqueso();
				}
				else if(d=='d'){
					Perso.setpepinillos();
				}
				else if(d=='e'){
					Perso.setcebolla();
				}
				else if(d=='f'){
					Perso.setbeacon();
				}
				else if(d=='g'){
					wea=1;
				}
				Perso.getinfo();
				cout<<endl;
			}
			Perso.setprecio();
			cout<<Perso.getPrecio();
		}
		else{
			while(wea==0){
				cout<<"a)lechuga"<<endl;
				cout<<"b)tomate"<<endl;
				cout<<"c)queso"<<endl;
				cout<<"d)pepinillos"<<endl;
				cout<<"e)cebolla"<<endl;
				cout<<"f)no deseo agregar nada mas"<<endl;
				cin>>d;
				if(d=='a'){
					Perso.setlechuga();
					Perso.setprecio();
				}
				else if(d=='b'){
					Perso.settomate();
					Perso.setprecio();
				}
				else if(d=='c'){
					Perso.setqueso();
					Perso.setprecio();
				}
				else if(d=='d'){
					Perso.setpepinillos();
					Perso.setprecio();
				}
				else if(d=='e'){
					Perso.setcebolla();
					Perso.setprecio();
				}
				else if(d=='f'){
					wea=1;
				}
				Perso.getinfo();
				cout<<endl;
			}
			Perso.setprecio();
			Perso.getPrecio();
		}
	}
	else cout<<"lo lamentamos opcion incorrecta"<<endl;
	return 0;
}
