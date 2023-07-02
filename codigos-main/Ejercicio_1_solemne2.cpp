#include <iostream>
#include <vector>
using namespace std;
class Empresa{
    protected:
        string nombre,rut;
        int saldo;
    public:
        Empresa(){
            nombre=" ";
            rut=" ";
            saldo=0;
        }
        Empresa(string nombre,string rut,int saldo){
            this->nombre=nombre;
            this->rut=rut;
            this->saldo=saldo;
        }
        void info(){
            cout<<"Nombre de la empresa : "<<nombre<<endl;
            cout<<"Rut de la empresa : "<<rut<<endl;
            cout<<"Saldo de la empresa : "<<saldo<<endl;
        }
        void AcumularSaldo(int monto){
            this->saldo += monto;
        }
};
class TiendaRopa : public Empresa{
    protected:
        vector<float>Fardos;
    public:
        TiendaRopa() : Empresa(){}
        TiendaRopa(string nombre,string rut,int saldo,vector<float>Fardos) : Empresa(nombre,rut,saldo){
            this->Fardos=Fardos;
        }
        float ExportarFardo(){
            float ultimo=this->Fardos.back();
            this->Fardos.pop_back();
            return ultimo;
        }
        bool VerificarFardo(){
            return !(this->Fardos.empty());
        }
        void Ver(){
            for(int i=0;i<this->Fardos.size();i++){
                cout<<"Fardo : "<<i+1<<this->Fardos[i]<<endl;
            }
        }
};
class Sucursal1 : public TiendaRopa{
    private:
    public: 
        Sucursal1() : TiendaRopa(){}
        Sucursal1(string nombre,string rut,int saldo,vector<float>Fardos) : TiendaRopa(nombre,rut,saldo,Fardos){}
        void venta(int cantidad){
            if(VerificarFardo()==true){
                for(int i=0;i<cantidad;i++){
                	AcumularSaldo(ExportarFardo()*1000);
				}
            }
            else{
                cout<<"No hay fardos disponibles"<<endl;
                return;
            }
            cout<<"La venta fue de : "<<this->saldo<<" Pesos"<<endl;
        }
};
int main()
{
	vector<float>Fardos;
	Fardos.push_back(4);
	Fardos.push_back(6);
	Fardos.push_back(1);
	Fardos.push_back(2);
    Sucursal1 Juanita("juanita","50.555.111-2",0,Fardos);
    Juanita.venta(3);
    return 0;
}
