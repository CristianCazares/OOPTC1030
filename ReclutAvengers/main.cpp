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
    pause("\t->Continuar. . .");
    clear();
    cout<<"Veo que ya tienes a tu Vengador escogido... Vamos a las preguntas.\n";
    pause("\t->Continuar. . .");
    cout<<"Es importante responder de la siguiente manera:\n    1=\"Si\" 0=\"No\"\n";
    pause("\t->Continuar. . .");
    clear();

    Question q;
    q.askPlanet();
    clear();
    q.showOptions();
    //pause();
    pause("\t->Siguiente pregunta. . .");

    q.askGender();
    clear();
    q.showOptions();
    //pause();
    pause("\t->Siguiente pregunta. . .");

    q.askLocation();



    pause();
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
    cout<<"Piensa en el que creas mejor para tu mision y te haré preguntas al respecto...\n";
}


void clear(){
    if (system("CLS")) system("clear");
}
void pause(){
    cout<<"Press ENTER key to continue . . ."; cin.get(); cin.ignore();
}
void pause(string msg){
    cout<<msg<<"\t(Enter)";
    fflush(stdin);cin.get();
    cout<<"\n\n";
}