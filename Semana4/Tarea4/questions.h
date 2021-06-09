#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include <algorithm>
#include"aliens.h"
#include"humans.h"
#include"loadAvengers.h"
using namespace std;

class Question{
    public:
        int rng(int,int);
        void askPlanet();
        void askGender();
        void askLocation();
        void askColors();
        void askPowers();
        void showOptions();
        void lost();
        void checkWin();
    private:
        vector<Alien> alienOptions;
        vector<Human> humanOptions;
        bool isHuman;
};

int Question::rng(int x, int y){
    srand((unsigned) time(0));

    int result;
    result = x+(rand()%y);
    return result;
}

void Question::askPlanet(){
    int sel;
    cout<<"¿Tu personaje proviene del Planeta Tierra? ";cin>>sel;
    if(sel==1){
        isHuman = true;
        for(int i=0;i<Humans.size();i++){
            humanOptions.push_back(Humans[i]);
        }
    }else{
        isHuman = false;
        for(int i=0;i<Aliens.size();i++){
            alienOptions.push_back(Aliens[i]);
        }
    }
}

void Question::askGender(){
    int sel;
    cout<<"¿Tu personaje es Mujer? ";cin>>sel;
    char gender;
    if(sel==1){
        gender = 'F';
    }else{
        gender = 'M';
    }

    if(isHuman){
        //Guardar resultados en arreglo auxiliar
        vector<Human> aux;
        for(int i=0;i<humanOptions.size();i++){
            if(humanOptions[i].getGender()==gender){
                aux.push_back(humanOptions[i]);
            }
        }
        humanOptions = aux;
    }else{
        vector<Alien> aux;
        for(int i=0;i<alienOptions.size();i++){
            if(alienOptions[i].getGender()==gender){
                aux.push_back(alienOptions[i]);
            }
        }
        alienOptions = aux;
    }
}

void Question::askLocation(){
    //Crear arreglo de ubicaciones de los posibles Vengadores
    vector<string> posibleLocations;
    if(isHuman){
        for(int i=0;i<humanOptions.size();i++){
            string key = humanOptions[i].getCountry();
            if (find(posibleLocations.begin(), posibleLocations.end(), key) == posibleLocations.end()) {
                posibleLocations.push_back(key);
            }
        }
    }else{
        for(int i=0;i<alienOptions.size();i++){
            string key = alienOptions[i].getPlanet();
            if (find(posibleLocations.begin(), posibleLocations.end(), key) == posibleLocations.end()) {
                posibleLocations.push_back(key);
            }
        }        
    }

    int tries = 0, sel;
    string location;
    bool isLost = false;
    while(sel!=1 && tries<posibleLocations.size()){
        location = posibleLocations[tries];

        cout<<tries+1<<".- ¿El Vengador proviene de "<<location<<"?";cin>>sel;
        tries++;
        if(tries>=posibleLocations.size()){
            isLost = true;
        }
    }
    if(!isLost){
        if(isHuman){
            vector<Human> aux;
            for(int i=0;i<humanOptions.size();i++){
                if(humanOptions[i].getCountry()==location){
                    aux.push_back(humanOptions[i]);
                }
            }
            humanOptions = aux;
        }else{
            vector<Alien> aux;
            for(int i=0;i<alienOptions.size();i++){
                if(alienOptions[i].getPlanet()==location){
                    aux.push_back(alienOptions[i]);
                }
            }
            alienOptions = aux;
        }
        checkWin();
    }else{
        lost();
    }
}

void Question::showOptions(){
    cout<<"INVENTARIO:\n    (Probables Vengadores al momento)\n";
    if(isHuman){
        for(int i=0;i<humanOptions.size();i++){
            cout<<"    "<<i+1<<".- "<<humanOptions[i].getAlias()<<endl;
        }
    }else{
        for(int i=0;i<alienOptions.size();i++){
            cout<<"    "<<i+1<<".- "<<alienOptions[i].getAlias()<<endl;
        }
    }
    cout<<"\n\n";
}

void Question::checkWin(){
    if(isHuman){
        if(humanOptions.size()==1){
            cout<<"\n\nEL VENGADOR EN EL QUE PIENSAS ES:\n";
            humanOptions[0].show();
        }else{
            showOptions();
            cout<<"\n\nPOR TERMINAR...";
        }
    }else{
        if(alienOptions.size()==1){
            cout<<"\n\nEL VENGADOR EN EL QUE PIENSAS ES:\n";
            alienOptions[0].show();
        }else{
            showOptions();
            cout<<"\n\nPOR TERMINAR...";
        }
    }
}

void Question::lost(){
    cout<<"NO SE PUEDE ADIVINAR\n";
}
