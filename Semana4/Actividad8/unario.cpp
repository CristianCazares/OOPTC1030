#include<iostream>
using namespace std;

class Test{
    private:
        int count;
    public:
        operator ++();
        operator --();
        void Display(){
            cout<< "El contador es: "<<count<<endl;
        }
};
Test::operator ++(){
    count+=5;
    return 0;
}
Test::operator --(){
    count-=10;
    return 0;
}


int main(){
    Test t;
    ++t;
    t.Display();

    --t;
    --t;
    --t;
    t.Display();

    return 0;
}

