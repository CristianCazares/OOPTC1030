#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "loadAvengers.h"
using namespace std;

void clear();
void pause();

int main(){
    clear();
    load();
    for(int i=0;i<Humans.size();i++){
        Humans[i].show();
    }
    for(int i=0;i<Aliens.size();i++){
        Aliens[i].show();
    }

    pause();
    return 0;
}


void clear(){
    if (system("CLS")) system("clear");
}
void pause(){
    cout<<"Press ENTER key to continue . . ."; cin.get();
}