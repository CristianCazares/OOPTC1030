#ifndef operacion_h
#define operacion_h

#include<iostream>
using namespace std;

class Operacion{
    public:
        void setValor1();
        void setValor2();
        int mostrarResultado();
    protected:
        int valor1;
        int valor2;
        int resultado;
};

void Operacion::setValor1(){
    cout<<"Ingrese valor 1: ";cin>>valor1;
}

void Operacion::setValor2(){
    cout<<"Ingrese valor 2: ";cin>>valor2;
}

int Operacion::mostrarResultado(){
    return resultado;
}

#endif