#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "loadAvengers.h"
#include "aliens.h"
#include "humans.h"
#include "questions.h"
using namespace std;

void clear();
void pause();
void pause(string);

void mainScreen();

int main(){
    clear();
    load();
    mainScreen();
    pause("\t->ENTER para continuar. . .");
    cout<<"Continuamos\n";






    return 0;
}

void mainScreen(){
    cout<<"\t.:BIENVENIDO:.\n";
    cout<<"Estos son los vengadores disponibles:\n";
    int count=1;
    for(int i=0;i<Humans.size();i++){
        cout<<"    "<<count<<".-"<<Humans[i].getAlias()<<endl;
        count++;
    }
    for(int i=0;i<Aliens.size();i++){
        cout<<"    "<<count<<".-"<<Aliens[i].getAlias()<<endl;
        count++;
    }
    cout<<"Piensa en el que creas mejor para tu mision y te hare preguntas al respecto...\n";
}


void clear(){
    if (system("CLS")) system("clear");
}
void pause(){
    cout<<"Press ENTER key to continue . . ."; cin.get();
}
void pause(string msg){
    cout<<msg; cin.get();
    cout<<"\n\n";
}