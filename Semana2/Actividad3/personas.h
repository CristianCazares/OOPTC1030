#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void clear();
void pause();
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





void clear(){
    if (system("CLS")) system("clear");
}
void pause(){
    cout<<"Press ENTER key to continue . . ."; cin.get();
}