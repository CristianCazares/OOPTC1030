#include <iostream>
#include "Shape.h"
using namespace std;


int main(){
    Shape *Shapes[5];
    Shapes[0] = new Circle();
    Shapes[1] = new Rectangle();
    Shapes[2] = new Rectangle(1,2,5,6);
    Shapes[3] = new Circle(4,2,1);
    Shapes[4] = new Rectangle();

    for(int i=0;i<5;i++){
        Shape *current = Shapes[i];
        current->draw();
    }

    return 0;
}