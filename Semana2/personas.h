#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void clear();

//

class Persona{
    public:
        Persona();
        Persona(string,int);

        void setNombre(string);
        void setEdad(int);
        string getNombre();
        int getEdad();
    protected:
        string nombre;
        int edad;      
};
Persona::Persona(){
    nombre = "SIN NOMBRE";
    edad = 0;
}
Persona::Persona(string Nombre, int Edad){
    nombre = Nombre;
    edad = Edad;
}
void    Persona::setNombre(string Nombre){nombre = Nombre;}
void    Persona::setEdad(int Edad){edad = Edad;}
string  Persona::getNombre(){return nombre;}
int     Persona::getEdad(){return edad;}



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






void clear(){
    if (system("CLS")) system("clear");
}
