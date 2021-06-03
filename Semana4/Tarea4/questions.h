#include<iostream>
#include<string>
#include<vector>
#include<ctime>
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
            posibleLocations.push_back(humanOptions[i].getCountry());
        }
    }else{
        for(int i=0;i<alienOptions.size();i++){
            posibleLocations.push_back(alienOptions[i].getPlanet());
        }
    }

    cout<<"Posibles locaciones"<<endl;
    for(int i=0;i<posibleLocations.size();i++){
        cout<<posibleLocations[i]<<endl;
    }

}

void Question::showOptions(){
    cout<<"Probables Vengadores al momento:\n";
    if(isHuman){
        for(int i=0;i<humanOptions.size();i++){
            cout<<"    "<<i+1<<".-"<<humanOptions[i].getAlias()<<endl;
        }
    }else{
        for(int i=0;i<alienOptions.size();i++){
            cout<<"    "<<i+1<<".-"<<alienOptions[i].getAlias()<<endl;
        }
    }
    cout<<"\n\n";
}