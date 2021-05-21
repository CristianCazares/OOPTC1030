#include <iostream>
#include <string>
#include <stdlib.h>
#include "suma.h"
#include "multiplica.h"
#include "resta.h"
using namespace std;

void clear();

int main(){
    clear();
    //Suma
    Suma suma;
    suma.setValor1();
    suma.setValor2();
    suma.operar();
    cout<<"Resultado suma = "<<suma.mostrarResultado()<<"\n\n";

    //Resta
    Resta resta;
    resta.setValor1();
    resta.setValor2();
    resta.operar();
    cout<<"Resultado resta = "<<resta.mostrarResultado()<<"\n\n";


    //Multiplica
    Multiplica multiplica;
    multiplica.setValor1();
    multiplica.setValor2();
    multiplica.operar();
    cout<<"Resultado multiplicacion = "<<multiplica.mostrarResultado()<<"\n\n";

    return 0;
}

void clear(){
    if (system("CLS")) system("clear");
}