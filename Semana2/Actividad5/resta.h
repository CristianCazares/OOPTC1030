#include<iostream>
#include "operacion.h"
using namespace std;

class Resta:public Operacion{
    public:
        void operar();
};

void Resta::operar(){
    resultado = valor1-valor2;
}