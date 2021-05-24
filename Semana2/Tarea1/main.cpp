#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "characters.h"
using namespace std;

void clear();
void pause();

int main(){
    clear();
    cout<<".:LISTA DE AVENGERS:.\n\n";
    CapAmerica.show();
    IronMan.show();
    Thor.show();
    Hawkeye.show();
    Hulk.show();
    Spiderman.show();
    Groot.show();
    Loki.show();

    BlackWidow.show();
    Wasp.show();
    ScarlettWitich.show();
    Shuri.show();
    CapMarvel.show();
    Gamora.show();
    Valkyrie.show();
    pause();
    return 0;
}


void clear(){
    if (system("CLS")) system("clear");
}
void pause(){
    cout<<"Press ENTER key to continue . . ."; cin.get();
}