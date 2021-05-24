#ifndef avengers_h
#define avengers_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int nPowers=3;
const int nColors=2;
class Avenger{
    public:
        Avenger();
        Avenger(string, string, char, vector<string>,vector<string>);

        void showAvenger();

        void setName(string);
        void setAlias(string);
        void setGender(char);
        void setColors(vector<string>);
        void setPowers(vector<string>);

        string getName();
        string getAlias();
        char getGender();

    protected:
        string name;
        string alias;
        char gender;
        vector<string> colors;
        vector<string> powers;
};

Avenger::Avenger(){
    name = "-/-";
    alias = "-/-";
    gender = '-';
    powers = {"-/-","-/-","-/-"};
    colors = {"-/-","-/-"};
}
Avenger::Avenger(string Name, string Alias, char Gender, vector<string> Colors, vector<string> Powers){
    name = Name;
    alias = Alias;
    gender = Gender;
    colors = Colors;
    powers = Powers;
}
void Avenger::showAvenger(){
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
    cout<<"    Colores:"<<endl;
    for (int i = 0; i < colors.size(); i++){
        cout<<"        -"<<powers[i]<<endl;
    }
    cout<<"    Poderes:"<<endl;
    for (int i = 0; i < powers.size(); i++){
        cout<<"        -"<<colors[i]<<endl;
    }
    cout<<"\n\n";
}


void Avenger::setName(string Name){
    name = Name;
}
void Avenger::setAlias(string Alias){
    alias = Alias;
}
void Avenger::setGender(char Gender){
    gender = Gender;
}
void Avenger::setColors(vector<string> Colors){
    colors = Colors;
}
void Avenger::setPowers(vector<string> Powers){
    powers = Powers;
}



#endif