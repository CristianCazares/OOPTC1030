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

        virtual void show() = 0;

        void setName(string);
        void setAlias(string);
        void setGender(char);
        void setColors(vector<string>);
        void setPowers(vector<string>);

        string getName();
        string getAlias();
        char getGender();
        vector<string> getColors();
        vector<string> getPowers();

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


void Avenger::setName(string Name){name = Name;}
void Avenger::setAlias(string Alias){alias = Alias;}
void Avenger::setGender(char Gender){gender = Gender;}
void Avenger::setColors(vector<string> Colors){colors = Colors;}
void Avenger::setPowers(vector<string> Powers){powers = Powers;}

string Avenger::getName(){return name;}
string Avenger::getAlias(){return alias;}
char Avenger::getGender(){return gender;}
vector<string> Avenger::getColors(){return colors;}
vector<string> Avenger::getPowers(){return powers;}

#endif