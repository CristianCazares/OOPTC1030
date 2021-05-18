#include <iostream>
#include <string>
#include <stdlib.h>
#include "personas.h"
using namespace std;

int main(){
    clear();
    Estudiante e1;
    e1.show();
    e1.setNombre("Melissa");
    e1.setEdad(18);
    e1.setCarrera("ITD");
    e1.show();

    Estudiante e2("Cristian","ITC",19);
    e2.show();

    system("PAUSE");
    return 0;
}

