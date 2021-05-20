#include <iostream>
#include "operacion.h"
using namespace std;

class Suma:public Operacion{
    public:
        void operar();
};

void Suma::operar(){
    resultado = valor1+valor2;
}