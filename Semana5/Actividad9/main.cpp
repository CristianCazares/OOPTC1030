#include <iostream>
#include <string>
using namespace std;

class DividedByZerito{
    public:
        DividedByZerito(string);
        string tellmeMsg();
    private:
        string errorMsg;
};
DividedByZerito::DividedByZerito(string str){
    errorMsg = str;
}
string DividedByZerito::tellmeMsg(){
    return errorMsg;
}

int main(){
    int x = 100;
    int y = 0;

    try{
        if(y!=0)
            x = x/y;
        else
            throw DividedByZerito("ERROR ERROR ERROR");

        cout<<x<<"/"<<y<<"="<<x<<endl;
    }

    catch(DividedByZerito e){
        cout<<e.tellmeMsg()<<" Divisor debe ser distinto de zero."<<endl;
    }



    return 0;
}


