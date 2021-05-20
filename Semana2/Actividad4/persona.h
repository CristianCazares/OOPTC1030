#ifndef persona.h
#define persona.h


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



void clear(){
    if (system("CLS")) system("clear");
}
void pause(){
    cout<<"Press ENTER key to continue . . ."; cin.get();
}

#endif