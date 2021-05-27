#include<iostream>
#include<vector>
#include "Shape.h"
using namespace std;


int main(){
    vector<Shape*> shapes;
    Shape *shape;

    shape = new Circle(5,6,7);
    shapes.push_back(shape);

    shape = new Rectangle(5,6,7,8);
    shapes.push_back(shape);

    shape = new Circle(15,16,17);
    shapes.push_back(shape);

    shape = new Rectangle(50,60,70,80);
    shapes.push_back(shape);

    for(int i=0;i<shapes.size();i++){
        shapes[i]->draw();
    }

    return 0;
}