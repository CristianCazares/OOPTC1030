#include <iostream>
#include <string>
#include <vector>
#include "avengers.h"
using namespace std;

class Human: public Avenger{
    public:
        Human();
        Human(string, string, char, string, vector<string>, vector<string>);
    
        void show();

        void setCountry(string);
    private:
        string country;
};

Human::Human() :Avenger(){
    name = "-/-";
    alias = "-/-";
    gender = '-';
    country = '-';
    powers = {"-/-","-/-","-/-"};
    colors = {"-/-","-/-"};
}
Human::Human(string Name, string Alias, char Gender, string Country, vector<string> Colors, vector<string> Powers):Avenger(Name, Alias, Gender, Colors, Powers){
    name = Name;
    alias = Alias;
    country = Country;
    gender = Gender;
    colors = Colors;
    powers = Powers;
}

void Human::show(){
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
    cout<<"    Pais: "<<country<<endl;
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