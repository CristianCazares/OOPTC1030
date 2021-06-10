#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include"aliens.h"
#include"humans.h"
#include"loadAvengers.h"
using namespace std;


class Question{
    public:
        void askPlanet();
        void askGender();
        vector<string> findPosibleLocations();
        void askLocation();
        void askColors();
        void askPowers();
        void showOptions();
        bool checkWin();
        void clear();

        void win();
        bool lost();
        bool isLost;
    private:
        vector<Avenger*> options;
        bool isHuman;
};

void Question::askPlanet(){
    int sel;
    cout<<"Tu personaje proviene del Planeta Tierra? ";cin>>sel;
    for(int i=0;i<Avengers.size();i++){
        if(sel==1 && Avengers[i]->isHuman==true){
            options.push_back(Avengers[i]);
        }else if(sel==0 && Avengers[i]->isHuman==false){
            options.push_back(Avengers[i]);
        }
    }
}

void Question::askGender(){
    int sel;
    cout<<"Tu personaje es mujer? ";cin>>sel;
    vector<Avenger*> aux;

    for(int i=0;i<options.size();i++){
        if(sel==1 && options[i]->getGender()=='F'){
            aux.push_back(options[i]);
        }else if(sel==0 && options[i]->getGender()=='M'){
            aux.push_back(options[i]);
        }
    }
    options = aux;
}

//SE NECESITAN DE VUELTA LOS OBJETOS ORIGINALES
vector<Human> humansTemp;
vector<Alien> aliensTemp;
vector<string> Question::findPosibleLocations(){
    bool isHuman = options[0]->isHuman;

    //Guardar options (Avengers), en su clase original (Humans/Aliens).
    if(isHuman){
        for(int i=0;i<options.size();i++){
            for(int j=0;j<Humans.size();j++){
                if(Humans[j].getAlias() == options[i]->getAlias()){
                    humansTemp.push_back(Humans[j]);
                }
            }
        }
    }else{
        for(int i=0;i<options.size();i++){
            for(int j=0;j<Aliens.size();j++){
                if(Aliens[j].getAlias() == options[i]->getAlias()){
                    aliensTemp.push_back(Aliens[j]);
                }
            }
        }
    }

    vector<string> askedLocations;
    //Preguntar COUNTRY si es HUMAN
    if(isHuman){
        //Preguntar por el primero siempre
        askedLocations.push_back(humansTemp[0].getCountry());
        
        //Por cada elemento
        for(int i=0;i<humansTemp.size();i++){
            //Checar si fue preguntado
            bool asked=false;
            for(int j=0;j<askedLocations.size();j++){
                if(humansTemp[i].getCountry()==askedLocations[j]){
                    asked = true;
                }
            }
            if(!asked){
                askedLocations.push_back(humansTemp[i].getCountry());
            }
        }
    }else{
        //Preguntar por el primero siempre
        askedLocations.push_back(aliensTemp[0].getPlanet());
        
        //Por cada elemento
        for(int i=0;i<aliensTemp.size();i++){
            //Checar si fue preguntado
            bool asked=false;
            for(int j=0;j<askedLocations.size();j++){
                if(aliensTemp[i].getPlanet()==askedLocations[j]){
                    asked = true;
                }
            }
            if(!asked){
                askedLocations.push_back(aliensTemp[i].getPlanet());
            }
        }
    }

    return askedLocations;
}



void Question::askLocation(){
    bool isHuman = options[0]->isHuman;
    vector<string> posibleLocations = findPosibleLocations();

    //Formular pregunta
    string strQuestion;
    vector<string> askedLocations;
    if(options[0]->getGender()=='F'){
        strQuestion = "La Vengadora en cuestion proviene de ";
    }else{
        strQuestion = "El Vengador que buscas es orundio de ";
    }

    

    int sel = 0, tries = 0;
    string answer;
    vector<Avenger*> aux;
    
    while(sel == 0 && tries<posibleLocations.size()){
        cout<<strQuestion<<posibleLocations[tries]<<"? ";
        cin>>sel;
        if(sel==1){
            answer = posibleLocations[tries];
        }
        tries++;
    }
    if(sel==1){

        if(isHuman){
            for(int i=0;i<humansTemp.size();i++){
                if(humansTemp[i].getCountry()==answer){
                    Human h = humansTemp[i];
                    aux.push_back(new Human(h.getName(), h.getAlias(), h.getGender(), h.getCountry(), h.getColors(), h.getPowers()));
                }
            }
        }else{
            for(int i=0;i<aliensTemp.size();i++){
                if(aliensTemp[i].getPlanet()==answer){
                    Alien a = aliensTemp[i];
                    aux.push_back(new Alien(a.getName(), a.getAlias(), a.getGender(), a.getPlanet(), a.getColors(), a.getPowers()));
                }
            }
        }
        options = aux;
    }else{
        lost();
    }
}

void Question::askPowers(){
    cout<<"Mmh... Ya casi. Estamos cerca."<<endl;

    //Formular pregunta
    string strQuestion;
    if(options[0]->getGender()=='F'){
        strQuestion = "\n===PREGUNTA\nTu heroina es famosa por tener ESPECIFICAMENTE ";
    }else{
        strQuestion = "\n===PREGUNTA\nEl heroe que tienes en mente SE CARACTERIZA por tener ";
    }
    
    vector<string> posiblePowers;
    Avenger* answer;
    int sel = 0;
    for(int i=0;i<options.size();i++){
        clear();
        if(sel!=1){
            string strPowers;
            vector<string> powers = options[i]->getPowers();
            strPowers = powers[0] + ", " + powers[1] + " y " + powers[2];
            //Hacer pregunta
            clear();
            cout<<strQuestion<<strPowers<<"?";cin>>sel;
            answer=options[i];
        }else if(sel==1){
            break;
        }
    }
    if(sel==0){
        lost();
    }else{
        vector<Avenger*> aux;
        aux.push_back(answer);
        options = aux;
    }
}

void Question::showOptions(){
    cout<<"INVENTARIO:\n    (Probables Vengadores al momento)\n";
    for(int i=0;i<options.size();i++){
        cout<<options[i]->getAlias()<<endl;
    }
    cout<<"\n\n";
}

bool Question::checkWin(){
    if(options.size()==1){
        return true;
    }
    return false;
}

void Question::win(){
    clear();

    cout<<"Lo tengo... Tu vengador es...\n\n";
    cout<<"                    .   *        .       .	\n";
    cout<<"       *      -0-				\n";
    cout<<"          .                .  *       - )-	\n";
    cout<<"       .      *       o       .       *		\n";
    cout<<" o                |				\n";
    cout<<"           .     -O-				\n";
    cout<<".                 |        *      .     -0-	\n";
    cout<<"       *  o     .    '       *      .        o	\n";
    cout<<"     .       "<<options[0]->getAlias()<<"  .        |      *	\n";
    cout<<"   *             *              -O-          .	\n";
    cout<<"         .             *         |     ,	\n";
    cout<<"   `            .           o			\n";
    cout<<" 	*	.       `        ,   *		\n";
    cout<<"       .  *            o       '		\n";
    cout<<"	    *      `         ,         `    	\n";
    cout<<"                 .                        *	\n";
    cout<<"       *                 `     .       *		\n\n";

    options[0]->show();
}
bool Question::lost(){
    clear();
    cout<<" __    ______    __    __     .__   __.   ______    __               _______     \n";
    cout<<"(__)  /  __  \\  |  |  |  |    |  \\ |  |  /  __  \\  |  |             |       \\  _ \n";
    cout<<"|  | |  |  |  | |  |__|  |    |   \\|  | |  |  |  | |  |             |  .--.  |(_)\n";
    cout<<"|  | |  |  |  | |   __   |    |  . `  | |  |  |  | |  |             |  |  |  |   \n";
    cout<<"|  | |  `--'  | |  |  |  |    |  |\\   | |  `--'  | |__|             |  '--'  | _ \n";
    cout<<"|__|  \\______/  |__|  |__|    |__| \\__|  \\______/  (__)             |_______/ (_)\n";

    cout<<"\n\n\nNo tengo ni idea de quien hablas!!!\n";
    cout<<"Parece ser que no conozco a mis Vengadores...\n    O quiza TU no los conoces...\n\n\n";
    isLost = true;
    return false;
}
void Question::clear(){
    if (system("CLS")) system("clear");
}