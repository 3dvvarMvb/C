#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;
class Caja{
    private:
        int id;
    public:
        Caja(int id){
            this->id=id;
        }
        int GetID(){
            return id;
        }
};
void RecibirCaja(Caja c,stack<Caja>*cs){
    if(cs->size()>=20){
        cout<<"lo sentimos pero no se pueden ingresar mas cajas"<<endl;
        return;
    }
    cs->push(c);
}
void RecibirVariasCajas(vector<Caja>ca,stack<Caja>*cs){
    if(cs->size()>=20){
        cout<<"lo sentimos pero no se pueden ingresar mas cajas"<<endl;
        return;
    }
    for(int i=0;i<ca.size();i++){
        cs->push(ca[i]);
    }
}
int main()
{
    stack<Caja>*Bodega=new stack<Caja>;
    vector<Caja>Cajas;
    Caja cajaP(000);
    RecibirCaja(cajaP,Bodega);
    Caja caja1(100);
    Caja caja2(110);
    Caja caja3(111);
    Caja caja4(200);
    Cajas.push_back(caja1);
    Cajas.push_back(caja2);
    Cajas.push_back(caja3);
    Cajas.push_back(caja4);
    RecibirVariasCajas(Cajas,Bodega);
    cout<<"todas las cajas"<<endl;
    while(!Bodega->empty()){
        cout<<(Bodega->top()).GetID()<<endl;
        Bodega->pop();
    }
    return 0;
}
