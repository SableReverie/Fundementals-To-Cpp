#include <iostream>
using namespace std;


class printer{
    private:
    string name;

    public: void setName(string n){
        name = n;
    }
    public: string getName(){
        return name;
    }
};

int main(){
    
    printer person1 = new printer();
        
   



    return 0;
}