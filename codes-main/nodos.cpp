#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <bits/stl_vector.h>
using namespace std;
class Nodo
{
private:
	int ID;
	int costo;

public:
	Nodo()
	{
		ID = 0;
		costo = 0;
	}
	Nodo(int ID, int costo)
	{
		this->ID = ID;
		this->costo = costo;
	}
	int getID()
	{
		return ID;
	}
	int getCosto()
	{
		return costo;
	}
};
int main()
{
	srand(time(NULL));
	vector<Nodo>nodos;
	for (int i = 0; i < 5; i++)
	{
		int costo = rand() % 100 + 1;
		Nodo nodo(i+1, costo);
		nodos.push_back(nodo);
	}
	for (int i = 0; i < nodos.size(); i++)
	{
		cout << "ID: " << nodos[i].getID() << ", costo: " << nodos[i].getCosto() << endl;
	}
	return 0;
}
