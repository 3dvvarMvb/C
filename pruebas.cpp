#include<iostream>
using namespace std;

int tiempo=5;

int main()
{
    cout<<"tiempo restante: "<<tiempo<<endl;
    tiempo--;

    if (tiempo==0)
    {
        return 0;
    }
    
    else{
        cout<<"el tiempo no ha terminado"<<endl;
        main();
    }
}