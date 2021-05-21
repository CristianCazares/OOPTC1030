#include<iostream>
#include "operacion.h"
using namespace std;

class Multiplica:public Operacion{
    public:
        void operar();
};

void Multiplica::operar(){
    resultado = valor1*valor2;
}