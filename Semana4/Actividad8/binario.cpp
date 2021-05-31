#include<iostream>
using namespace std;

class Operacion{
    private:
        int operand;
    public:
        Operacion(int);
        Operacion();
        void Display();

        Operacion operator+(const Operacion &);
        Operacion operator*(const Operacion &);
};

Operacion::Operacion(int op){
    operand = op;
}
Operacion::Operacion(){
    operand = 0;
}
void Operacion::Display(){
    cout<<"El operando es: "<<operand<<endl;
}
Operacion Operacion::operator+(const Operacion &op1){
    Operacion opera;
    opera.operand = operand + op1.operand;
    return opera;
}
Operacion Operacion::operator*(const Operacion &op1){
    Operacion opera;
    opera.operand = operand * op1.operand;
    return opera;
}


int main(){
    Operacion var1(10);
    Operacion var2(10);
    Operacion res1(0);
    Operacion res2(0);

    res1 = var1 + var2;
    res1.Display();
    res2 = var1 * var2;
    res2.Display();
    return 0;
}