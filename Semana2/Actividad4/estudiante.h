#include <iostream>
#include <string>
#include <stdlib.h>
#include "persona.h"
using namespace std;
//
class Estudiante: public Persona{
    public:
        Estudiante();
        Estudiante(string, string, int);
        void show();

        string getCarrera();
        void setCarrera(string);
    private:
        string carrera;
};
Estudiante::Estudiante() : Persona(){
    nombre = "SIN NOMBRE";
    edad = 0;
    carrera = "SIN CARRERA";
}
Estudiante::Estudiante(string Nombre, string Carrera, int Edad) : Persona(Nombre,Edad){
    nombre = Nombre;
    edad = Edad;
    carrera = Carrera;
}
void Estudiante::show(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Carrera: "<<carrera<<endl;
    cout<<"Edad: "<<edad<<"\n\n";
}
void    Estudiante::setCarrera(string Carrera){carrera = Carrera;}
string  Estudiante::getCarrera(){return carrera;}