#include <iostream>
using namespace std;
class Caja{
	private:
		int a,b,c;
	public:	
		Caja(int a,int b,int c){
		this->a=a;
		this->b=b;
		this->c=c;	
		}
		Caja(){}
		int GetLargo(){
			return this->a;
		}
		int GetAncho(){
			return this->b;
		}
		int GetAlto(){
			return this->c;
		}
		bool cabe(Caja caja){
			int vol1=this->a*this->b*this->c;
			int vol2=caja.GetLargo()*caja.GetAncho()*caja.GetAlto();
			if(vol1>=vol2){
				return true;
			}
			return false;
		}
		
};
int main(){
	Caja caja1(5,5,5);
	Caja caja2(7,7,7);
	if(caja1.cabe(caja2)==true){
		cout<<"la caja cabe dentro"<<endl;
	}
	else{
		cout<<"la caja no cabe"<<endl;
	}
	return 0;
}
