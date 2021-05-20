#include <iostream>
#include <string>
#include <stdlib.h>
#include "persona.h"
using namespace std;

//
class Maestro: public Persona{
    public:
        Maestro();
        Maestro(string, string, int);
        void show();

        string getDepto();
        void setDepto(string);

    private:
        string depto;

};
Maestro::Maestro() :Persona(){
    nombre = "SIN NOMBRE";
    edad = 0;
    depto = "SIN DEPTO.";
}
Maestro::Maestro(string Nombre, string Depto, int Edad) : Persona(Nombre,Edad){
    nombre = Nombre;
    edad = Edad;
    depto = Depto;
}
void Maestro::show(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Departamento: "<<depto<<endl;
    cout<<"Edad: "<<edad<<"\n\n";
}
void    Maestro::setDepto(string Depto){depto = Depto;}
string  Maestro::getDepto(){return depto;}