#include<iostream>
#include<vector>
using namespace std;
class Nodo{
	private:
		string ID;
		int costo;
	public:
		Nodo(string ID,int costo){
			this->ID=ID;
			this->costo=costo;
		}	
		Nodo(){
			ID="";
			costo=0;
		}
		string GetID(){
			return ID;
		}	
		int GetCosto(){
			return costo;
		}
};
int main(){
	vector<Nodo>noditos(5);
	
	return 0;
}
