#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "loadAvengers.h"
#include "questions.h"
using namespace std;

void clear();
void pause();
void pause(string);

void IntroduccionFury();
void TutorialFury();
void Preguntas();
void logo();
void NickFury();

int main(){
    clear();
    load();
    IntroduccionFury();
    TutorialFury();
    Preguntas();
    return 0;
}

void IntroduccionFury(){
    logo();
    cout<<"\t.:BIENVENID@:.\n\n";
    cout<<"Que tal? Soy Nick Fury, director de S.H.I.E.L.D.\n";
    NickFury();
    pause();
    cout<<"Escuche que has venido a reclutar a un Vengador para ayudarte en una mision...\n";
    pause();
    cout<<"Ahora mismo algunos se encuentran ocupados.\n";
    cout<<"Esta es la lista de los Vengadores disponibles:\n";
    pause();
    clear();
    cout<<"\n>>>Lista de Vengadores disponibles:\n";
    for(int i=0;i<Avengers.size();i++){
        cout<<"\t>"<<i+1<<".- "<<Avengers[i]->getAlias()<<endl;
    }
    cout<<"\n\n";
    cout<<"Piensa cual de ellos es mas adecuado para tu mision...\n";
    pause();
    cout<<"Muy bien. Ahora te hare unas preguntas para asegurarnos que de verdad lo o la conoces.\n";
    pause();
}

void TutorialFury(){
    clear();
    cout<<"\nTodas las preguntas seran de \"SI\" o \"NO\"\n";
    pause();
    cout<<"Para contestarlas ingresaras UNICAMENTE:\n";
    cout<<"    1 = Si\n";
    cout<<"    0 = No\n";
    int sel = 0;
    while(sel!=1){   
        cout<<"Estas preparado? "; cin>>sel;
    }
}

void Preguntas(){
    clear();
    Question Fury;
    cout<<"\n\n===PREGUNTA\n";
    Fury.askPlanet();
    clear();
    cout<<"\n\n===PREGUNTA\n";
    //Fury.showOptions();
    Fury.askGender();
    clear();
    cout<<"\n\n===PREGUNTA\n";
    //Fury.showOptions();
    Fury.askLocation();
    if(!Fury.checkWin() && !Fury.isLost){
        clear();
        cout<<"\n\n===PREGUNTA\n";
        Fury.askPowers();
        if(Fury.checkWin() && !Fury.isLost){
            Fury.win();
        }
    }else if(Fury.checkWin()){
        Fury.win();
    }
    pause("ENTER para salir . . .");
    
}


void clear(){
    if (system("CLS")) system("clear");
}
void pause(){
    cout<<"\tENTER para continuar . . ."; cin.get();
    cout<<"\n";
}
void pause(string msg){
    cout<<msg<<"\t(Enter)";
    fflush(stdin);cin.get();
    cout<<"\n\n";
}



void logo(){
    cout<<"    ____            __      __  ___                                      \n" ;
    cout<<"   / __ \\___  _____/ /_  __/ /_/   |_   _____  ____  ____ ____  __________\n";
    cout<<"  / /_/ / _ \\/ ___/ / / / / __/ /| | | / / _ \\/ __ \\/ __ `/ _ \\/ ___/ ___/\n";
    cout<<" / _, _/  __/ /__/ / /_/ / /_/ ___ | |/ /  __/ / / / /_/ /  __/ /  (__  ) \n";
    cout<<"/_/ |_|\\___/\\___/_/\\__,_/\\__/_/  |_|___/\\___/_/ /_/\\__, /\\___/_/  /____/  \n";
    cout<<"                                                  /____/                  \n";
}
void NickFury(){
    cout<<"                                                                                \n";
    cout<<"                                  */,,*(#*.  ,#*                                \n";
    cout<<"                           .%,&@@@@@@@@@@@@@@/     (/                           \n";
    cout<<"                       ,/ @@@@@&@%.                    ./                       \n";
    cout<<"                    ,*..@@@@@@                          @ ..                    \n";
    cout<<"                   # @@@@@@@@,                           (@ (                   \n";
    cout<<"                  ( @@@@@@@@@                             #, ,                  \n";
    cout<<"                 * .@@@@& *@@(                                *                 \n";
    cout<<"                 / &@@@@@    %@&                               .                \n";
    cout<<"                 . @@@@@@      *@@,                         ,*                  \n";
    cout<<"                 / #@@@@&         @@@                      *@  /                \n";
    cout<<"                 #  @@@@&           /@@.                   (@/.                 \n";
    cout<<"                 ,  %@@@@@@%.          @@%         /    %  (@%*                 \n";
    cout<<"              *(. . /#*@   @,            *@@,  /(   /(  ,# *@/*                 \n";
    cout<<"             @@#@/   @@#*   *@/            &@&#@@@@@@&%#%&@@ %*@(              \n";
    cout<<"             .((.@(   @@@@@@@@%(.          .@@@@@@@&,@%#*@(&@.,@&               \n";
    cout<<"              **@@* #%@@@@%&@@@@@@@@@%(@@@@@@@@@@@##@@@*(/@@& @((               \n";
    cout<<"               /@&(,(% %@@( %@@%  @@@%    &@@@@@@@@@@@@@&&@@. #&                \n";
    cout<<"                //@ &.  &&&(/,.*%&,  ,.    @@@@@@@@@@@@@@@@& /&#                \n";
    cout<<"                 /@ &.              /&/    ,&@@@@@@@@@@&#** %@@*                \n";
    cout<<"                   &*@         /@@ *@@      ,@, (/  .(  /    #(                 \n";
    cout<<"                .@(* @@#     .@&*                #./  ,  #@#%@@ %               \n";
    cout<<"              @..@(@(&@@@@/#/&#  @@@@@@@.*@@@@@@&   @@@@@@@&@@@&@ %             \n";
    cout<<"            & ,&/%@@@*@@@@(*#         **#/%         .@@.@@@@@@@@%& %            \n";
    cout<<"         .& #&%(@@@@@@,@@@@/    @@@@@@@@@@@@@%@&&&    ( @@@@@@@@#&(  #          \n";
    cout<<"       ,@  @#(&@@@@@@@@(@%& @@@@@@@@(,/.*%,*%@@@@@@%@% *@&@@@@@@%/@     &%      \n";
    cout<<"###(/@*  ,@#(#@@@@@@@@@@@&%.@@@(@@@%,,/&&@@(*(&@@  @@@#@/@#@@@@@@@(@#      .&&, \n";
    cout<<"&@/     .@&# #@@@@@@@@@@@@@(@@&  ( /#. ,    ,%/    &@@@&%@@@@@@@@@@#.(%@@&      \n";
    cout<<"@, %@* %@@/*(#@@@@@@@@@@@@@@@@@&    (@@@@@@@@*    (@@@@@@@@@@@@@@@@@@@@&#*,%@&  \n";
    cout<<"@@@@* #@@/#/*#@@@@@@@@@@@@@@@@@@@.     .        /@@@@@@@@@@@@@@@#.,,,(@@@@@@@@@,\n";
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@& .&@*       *@@@@\n";
    cout<<"@@@@@@&%#((((&@@@@@@@@@@@@@@&#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*       *&@(.     \n";
}
