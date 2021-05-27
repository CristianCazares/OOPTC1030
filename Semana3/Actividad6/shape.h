#include <iostream>
using namespace std;

class Shape{
    public:
        Shape();
        Shape(int,int);
        int getX();
        int getY();
        virtual void draw();
        int x;
        int y;
};
Shape::Shape(){
    x = 0;
    y = 0;
}
Shape::Shape(int X, int Y){
    x = X;
    y = Y;
}
void Shape::draw(){
    cout<<"Soy una figura\n";
}


class Circle: public Shape{
    public:
        Circle();
        Circle(int, int, int);
        void draw();
    private:
        int r;
};
Circle::Circle(): Shape(){
    x = 0;
    y = 0;
    r = 0;
}
Circle::Circle(int X, int Y, int R): Shape(X, Y){
    x = X;
    y = Y;
    r = R;
}
void Circle::draw(){
    cout<<"Soy un circulo de radio "<<r<<".\n";
}


class Rectangle : public Shape{
    public:
        Rectangle();
        Rectangle(int,int,int,int);
        void draw();
    
    private:
        int xr;
        int yr;
};
Rectangle::Rectangle(): Shape(){
    xr = 0;
    yr = 0;
}
Rectangle::Rectangle(int X, int Y, int XR, int YR): Shape(X, Y){
    x = X;
    y = Y;
    xr = XR;
    yr = YR;
}
void Rectangle::draw(){
    cout<<"Soy un rectangulo de base "<<yr<<" y altura "<<xr<<".\n";
}