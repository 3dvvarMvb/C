#include <iostream>
#include <vector>
using namespace std;
class Libro{
	private:
		string nombre;
		int pag;
	public:
		Libro(){
			nombre=" ";
			pag=0;
		}	
		Libro(string nombre,int pag){
			this->nombre=nombre;
			this->pag=pag;
		}
		void imprimir(){
			cout <<"Nombre : "<<nombre<<" --- ";
			cout <<"Paginas : "<<pag<<endl;
		}	
};
int main(){
	vector<Libro> libros;
	Libro Moby_dick("Moby Dick",619);
	Libro L_O_P_S("Los ojos del perro siberiano",136);
	Libro Principito("El Principito",96);
	Libro Harry_Potter("Harry Potter y la camara secreta",288);
	Libro Quijote("El Quijote de la mancha",462);
	libros.push_back(Moby_dick);
	libros.push_back(L_O_P_S);
	libros.push_back(Principito);
	libros.push_back(Harry_Potter);
	libros.push_back(Quijote);
	for(int i=0;i<libros.size();i++){
		libros[i].imprimir();
	}
	cout<<endl;
	cout<<"Se borra el segundo libro"<<endl;
	libros.erase(libros.begin()+1,libros.begin()+2);
	for(int i=0;i<libros.size();i++){
		libros[i].imprimir();
	}
	Libro FMA("Full Metal Alchemist tomo 1",192);
	libros.push_back(FMA);
	cout<<endl;
	cout<<"Agregamos un libro"<<endl;
	for(int i=0;i<libros.size();i++){
		libros[i].imprimir();
	}
	cout<<endl;
	cout<<"Eliminamos el ultimo libro"<<endl;
	libros.pop_back();
	for(int i=0;i<libros.size();i++){
		libros[i].imprimir();
	}
	return 0;
}
