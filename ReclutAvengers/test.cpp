#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "loadAvengers.h"
#include "questions.h"
using namespace std;


int main(){
    system("cls");
    load();

    Question Fury;
    Fury.askPlanet();
    //Fury.showOptions();
    Fury.askGender();
    //Fury.showOptions();
    Fury.askLocation();
    if(!Fury.checkWin() && !Fury.isLost){
        Fury.askPowers();
        if(Fury.checkWin() && !Fury.isLost){
            Fury.win();
        }
    }else if(Fury.checkWin()){
        Fury.win();
    }

}