#include <iostream>
#include <string>
#include <vector>
#include "avengers.h"
using namespace std;

class Alien: public Avenger{
    public:
        Alien();
        Alien(string, string, char, string, vector<string>, vector<string>);
    
        void show();

        void setPlanet(string);
    private:
        string planet;
};

Alien::Alien() :Avenger(){
    name = "-/-";
    alias = "-/-";
    gender = '-';
    planet = '-';
    powers = {"-/-","-/-","-/-"};
    colors = {"-/-","-/-"};
}
Alien::Alien(string Name, string Alias, char Gender, string Planet, vector<string> Colors, vector<string> Powers):Avenger(Name, Alias, Gender, Colors, Powers){
    name = Name;
    alias = Alias;
    planet = Planet;
    gender = Gender;
    colors = Colors;
    powers = Powers;
}

void Alien::show(){
    cout<<"="<<alias<<endl;
    cout<<"    Nombre: "<<name<<endl;
    cout<<"    Genero: ";
    if(gender=='F'){
        cout<<"Femenino";
    }
    else if(gender=='M'){
        cout<<"Masculino";
    }
    else{
        cout<<gender;
    }
    cout<<"\n";
    cout<<"    Planeta: "<<planet<<endl;
    cout<<"    Colores:"<<endl;
    for (int i = 0; i < colors.size(); i++){
        cout<<"        -"<<colors[i]<<endl;
    }
    cout<<"    Poderes:"<<endl;
    for (int i = 0; i < powers.size(); i++){
        cout<<"        -"<<powers[i]<<endl;
    }
    cout<<"\n\n";
}