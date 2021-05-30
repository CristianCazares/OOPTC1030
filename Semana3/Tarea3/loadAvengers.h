#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<vector>
#include"humans.h"
#include"aliens.h"
using namespace std;

vector<string> read(string);
void printArray(vector<string>);
void loadAvengers(vector<string>);

vector<Human> Humans;
vector<Alien> Aliens;

void load(){
    vector<string> array = read("avengers.txt");
    loadAvengers(array);
}

vector<string> read(string path){
    vector<string> lines;
    string line;
    ifstream inFile(path);
    while(getline(inFile,line)){
        lines.push_back(line);
    }
    return lines;
}

void loadAvengers(vector<string> arr){
    string line;

    //Recorrer arreglo del archivo por cada línea
    for(int i=0;i<arr.size();i++){
        vector<string> data;
        line = arr[i];


        //Recorrer la línea por cada letra
        string element = "";
        for(int j=0;j<line.size();j++){
            //Separar e ignorar comas
            if(line[j]!=','){
                element+=line[j];
            }else if(line[j] == ','){
                data.push_back(element);
                element = "";
            }
        }
        data.push_back(element);

        //Crear un humano o alien con sus respectivos datos
        //Datos generales:
        string name = data[1];
        string alias = data[2];
        char gender = data[3][0];
        vector<string> colors = {data[5],data[6]};
        vector<string> powers = {data[7],data[8],data[9]};
        //Datos específicos
        if(data[0]=="H"){
            string country = data[4];

            Human aux(name, alias, gender,country, colors, powers);
            Humans.push_back(aux);
        }else if(data[0]=="A"){
            string planet = data[4];

            Alien aux(name, alias, gender, planet, colors, powers);
            Aliens.push_back(aux);
        }
    }
}