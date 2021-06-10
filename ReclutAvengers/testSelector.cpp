#include<iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

int selection(string, string, string);
void printOptions(string, string, string);

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int sel = selection("Pregunta", "Si", "No");
    cout<<"HA SELECCIONADO: "<<sel<<endl;

    return 0;
}

int selection(string question, string op1, string op2){
    if (system("CLS")) system("clear");
    cout<<question<<endl;
    cout<<">"<<op1<<"<"<<endl;
    cout<<" "<<op2<<" "<<endl;
    int c=0, sel = 1;
    bool repeat = true;
    while(repeat)
    {
        c = 0;
        switch((c=getch())) {
            case KEY_UP:
                if (system("CLS")) system("clear");
                cout<<question<<endl;
                cout<<">"<<op1<<"<"<<endl;
                cout<<" "<<op2<<" "<<endl;
                sel = 1;
                break;
            case KEY_DOWN:
                if (system("CLS")) system("clear");
                cout<<question<<endl;
                cout<<" "<<op1<<" "<<endl;
                cout<<">"<<op2<<"<"<<endl;
                sel = 0;
                break;
            case KEY_ENTER:
                repeat = false;
                break;
        }
    }
    return sel;
}