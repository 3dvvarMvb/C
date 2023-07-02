#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector <int> V;
	while(1){
		V.push_back(n);
		if(n == 1){ 
		break; 
		}
		else if(n%2 == 1 ){
			n++;
		}
		else if(n%2 == 0){
			n=n/2;
		}
	}
	for(int i=0;i<V.size();i++){
		cout<<V[i]<<"  ";
	}
	cout<<endl;
	return 0;
}
