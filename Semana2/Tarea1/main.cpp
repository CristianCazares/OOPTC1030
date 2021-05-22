#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void clear();
void pause();

int main(){


    return 0;
}


void clear(){
    if (system("CLS")) system("clear");
}
void pause(){
    cout<<"Press ENTER key to continue . . ."; cin.get();
}