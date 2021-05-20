#include <iostream>
#include <string>
#include <stdlib.h>
#include "suma.h"
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



    //Multiplica


    return 0;
}

void clear(){
    if (system("CLS")) system("clear");
}