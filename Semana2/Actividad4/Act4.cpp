#include <iostream>
#include <string>
#include <stdlib.h>
#include "estudiante.h"
#include "maestro.h"
using namespace std;

int main(){
    clear();
    Estudiante e1;
    cout<<"ESTUDIANTES\n";
    cout<<"\t(Por constructor default)\n";
    e1.show();
    e1.setNombre("Melissa");
    e1.setEdad(18);
    e1.setCarrera("ITD");
    e1.show();
    cout<<"\t(Por constructor con parametros)\n";
    Estudiante e2("Cristian","ITC",19);
    e2.show();


    Maestro m1;
    cout<<"\n\nMAESTROS\n";
    cout<<"\t(Por constructor default)\n";
    m1.show();
    m1.setNombre("Dinaky");
    m1.setEdad(53);
    m1.setDepto("Matematicas");
    m1.show();
    cout<<"\t(Por constructor con parametros)\n";
    Maestro m2("Chiquete","Filosofia y letras",52);
    m2.show();



    pause();
    return 0;
}

