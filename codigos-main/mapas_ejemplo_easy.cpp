#include <iostream>
#include <map>
#include <vector>
#include <iterator>
using namespace std;
class SeccionesPA{
    private:
        map<string, int> cuposSeccion;
        map<string, vector<string > > alumnosSeccion;
    public:
        SeccionesPA(){
        }
        void agregarSeccion(string codSeccion, int cuposSeccion){
            if(this->cuposSeccion.find(codSeccion) == this->cuposSeccion.end()){
                cout<<" Seccion Agregada "<<endl;
                this->cuposSeccion[codSeccion]=cuposSeccion;
            }
            else{
                cout<<" La seccion ya esta registrada "<<endl;
            }
        }
        bool agregarAlumno(string codSeccion, string rutAlumno){
            if(this->cuposSeccion.find(codSeccion) != this->cuposSeccion.end()){
                if(this->cuposSeccion[codSeccion]>0){
                    (this->alumnosSeccion[codSeccion]).push_back(rutAlumno);
                    --(this->cuposSeccion[codSeccion]);
                    return true;
                }
                else{
                    return false;
                }
            }
            return false;
        }
        void imprimirLista(string codSeccion){
            for(int i=0;i<(this->alumnosSeccion[codSeccion]).size();i++){
                cout<<(this->alumnosSeccion[codSeccion])[i]<<endl;
            }
            cout<<"El cupo disponible en la seccion es : "<<this->cuposSeccion[codSeccion]<<endl;
        }
};
int main()
{
    SeccionesPA *spa = new SeccionesPA();
    // spa->agregarSeccion( "cit2000", 5 );
    // spa->agregarSeccion( "cit2000", 5 );
    spa->agregarAlumno( "cit2000", "19.932.690-2");
    spa->agregarSeccion( "cit2000", 5 );
    spa->agregarAlumno( "cit2000", "19.932.690-2");
    spa->agregarAlumno( "cit2000", "19.932.690-3");
    spa->agregarAlumno( "cit2000", "19.932.690-4");
    spa->agregarAlumno( "cit2000", "19.932.690-9");
    spa->agregarAlumno( "cit2000", "19.932.690-54");
    spa->agregarAlumno( "cit2000", "19.932.690-55");
    spa->imprimirLista( "cit2000" );
    return 0;
}
